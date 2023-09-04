#include "random/rand.h"
#include <linux/kernel.h>

int encrypt_f(
        unsigned char *input,
        crypto_res_t *output,
        alg_t algorithm,
        bits_t bits,
        const unsigned char *_key,
        unsigned char *_iv,
        encoding_t encoding
) {

    unsigned int s = bits / 8;

    if (algorithm == aes_cbc) {

        unsigned char key[s];
        if (_key == ((void *) 0)) {
            printk(KERN_INFO "fill_srand\n");
            fill_srand(key, bits);
        }

        printk(KERN_INFO "test=%d\n", key[0]);

    }

    return 0;

}
