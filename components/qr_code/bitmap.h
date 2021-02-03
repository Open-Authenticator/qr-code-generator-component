#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <stdio.h>
#include <stdint.h>
#include "qrcodegen.h"
#include <string.h>

/**
 * @brief Set the pixel at the coordinate (x,y) as 1
 * @param[in] x coordinate of the pixel to be on 
 * @param[in] y coordinate of the pixel to be on
 * @param[in] width of the qrcode
 * @param[in] pointer to the bitmap array
 */

void setPixel(uint8_t x, uint8_t y, uint8_t width, uint8_t *arr_bitmap);


/**
 * @brief converts the qrcode buffer into bitmap array
 * @param[out] pointer to the bitmap array
 * @param[in]  qrcode buffer array
 * @param[in]  pointer to the bitmap array
 * @param[in]  version of the qrcode used
 */

void qrcode_to_bitmap(const uint8_t qrcode[],uint8_t *arr_bitmap,uint8_t version);

#endif