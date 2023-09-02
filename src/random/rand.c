//
// Created by root on 9/2/23.
//

#include "rand.h"
#include <linux/types.h>
#include <linux/crypto.h>
#include <linux/string.h>
#include <linux/gfp.h>
#include <linux/random.h>


void fill_srand(bits_t bits, unsigned char* out) {

    size_t s = bits / 8;
    u8 arr[s];

    get_random_bytes(arr, s);
    out = kmalloc(s, GFP_KERNEL);

    memcpy(out, arr, s);

}