#include "kernel_crypt.h"
#include "random/rand.h"

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
            fill_srand(key, bits);
        }

//        printk("test=%d", key[0]);

    }

    return 0;

}
