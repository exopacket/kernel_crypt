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

    size_t s = 32;
    switch(bits) {
        case s_512:
            s = 64;
            break;
        case s_384:
            s = 48;
            break;
        case s_256:
            s = 32;
            break;
        case s_192:
            s = 24;
            break;
        case s_128:
            s = 16;
            break;
    }

    u8 arr[s];
    get_random_bytes(arr, s);
    out = kmalloc(s, GFP_KERNEL);
    memcpy(out, arr, s);

}