#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "esp_log.h"

#include "qrcodegen.h"
#include "bitmap.h"

#define TAG "QRCODE"

int app_main()
{

   // Text to be written as QRcode
   const char *text = "http:192.168.1.1";

   // setting the error correction level
   enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;

   // setting the version of the qrcode
   uint8_t version = 1;

   // creating the qrcode buffer
   uint8_t qrcode[qrcodegen_BUFFER_LEN_FOR_VERSION(version)];
   uint8_t tempBuffer[qrcodegen_BUFFER_LEN_FOR_VERSION(version)];

   // creating the QR code
   bool ok = qrcodegen_encodeText(text, tempBuffer, qrcode, errCorLvl, version, version, qrcodegen_Mask_AUTO, true);
   if (ok)
   {
      ESP_LOGI(TAG, "QRcode successfully created");
   }

   uint8_t size = qrcodegen_getSize(qrcode);

   uint8_t arr_bitmap[(size * ((2 * size + 7) / 8))];
   memset(arr_bitmap, 0, sizeof(arr_bitmap));

   // converting the qrcode buffer to bitmap array
   qrcode_to_bitmap(qrcode, (uint8_t *)&arr_bitmap, version);

   // printing the bitmap array
   printf("Bitmap Array:-\n");
   for (int i = 0; i < sizeof(arr_bitmap); i++)
   {
      printf("%d ,", arr_bitmap[i]);
   }

   return 0;
}
