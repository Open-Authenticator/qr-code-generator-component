#include <stdint.h>
#include <stdio.h>
#include "qrcode.h"


void app_main(void)
{

   // initialising the QR code structure
   QRCode qrcode;

   // specifying the version of qrcode to use
   uint8_t version = 2;

   // The array to store the bitmap data of the qrcode
   uint8_t qrcodeData[qrcode_getBufferSize(version)];

   // initialising the qrcode with the text Data
   qrcode_initText(&qrcode, qrcodeData, version, 0, "https://192.168.1.1");

   // Printing the bitmap matrix of the image
   for (uint8_t y = 0; y < qrcode.size; y++)
   {
      for (uint8_t x = 0; x < qrcode.size; x++)
      {
         printf("%d ", qrcodeData[x + y]);
      }
      printf("\n");
   }

}