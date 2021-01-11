#include "qrcode.h"
#include "stdio.h"

void app_main(void)
{
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(3)];
    qrcode_initText(&qrcode, qrcodeData, 3, 0, "Welcome to TOTP Project");

    printf("\n\n\n\n");

    for (uint8_t y = 0; y < qrcode.size; y++)
    {

        // Left quiet zone
        printf("        ");

        // Each horizontal module
        for (uint8_t x = 0; x < qrcode.size; x++)
        {

            // Print each module (UTF-8 \u2588 is a solid block)
            printf(qrcode_getModule(&qrcode, x, y) ? "\u2588\u2588" : "  ");
        }

        printf("\n");
    }

    // Bottom quiet zone
    printf("\n\n\n\n");
}