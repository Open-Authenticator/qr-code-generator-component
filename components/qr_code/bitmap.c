#include "bitmap.h"

void setPixel(uint8_t x, uint8_t y, uint8_t width, uint8_t *arr_bitmap)
{
    uint8_t index_bitmap = (width * y + x) / 8;
    uint8_t index_bit = 7 - ((x) % 8);
    uint8_t power = 1 << index_bit;
    arr_bitmap[index_bitmap] = arr_bitmap[index_bitmap] | power;
}

void qrcode_to_bitmap(const uint8_t qrcode[],uint8_t *arr_bitmap,uint8_t version)
{
    uint8_t size = qrcodegen_getSize(qrcode);
    
    uint8_twidth = (((size * 2) + 7) / 8) * 8;

    uint8_tz = 0;
    for (uint8_ty = 0; y < size; y++)
    {

        for (uint8_tx = 0; x < size; x++)
        {
            if (qrcodegen_getModule(qrcode, x, y))
            {
                setPixel(x + z, y, width, (uint8_t *) arr_bitmap);
            }
            z++;
        }
        z = 0;
    }
}
