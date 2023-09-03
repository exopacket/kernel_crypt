//
// Created by root on 9/2/23.
//

#include "rand.h"
#include <linux/module.h>
#include <linux/types.h>
#include <linux/random.h>
#include <crypto/rng.h>

int fill_srand(unsigned char *out, bits_t bits) {

    struct crypto_rng *rng = ((void *) 0);
    char *drbg = "drbg_nopr_sha256";
    int ret;

    rng = crypto_alloc_rng(drbg, 0, 0);
    if (IS_ERR(rng)) {
        return PTR_ERR(rng);
    }

    unsigned int s = bits / 8;
    out = kmalloc(s, GFP_KERNEL);
    ret = crypto_rng_get_bytes(rng, out, s);
    if (ret < 0)
        return -1;
    else if (ret == 0)
        return 0;

    crypto_free_rng(rng);
    return ret;

}