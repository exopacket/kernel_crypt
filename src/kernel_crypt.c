#include <linux/kernel.h>
#include "kernel_crypt.h"
#include "utils/types.h"
#include "random/rand.h"

int encrypt_f(
        unsigned char* input,
        crypto_res_t* output,
        alg_t algorithm,
        bits_t bits,
        unsigned char* _key,
        unsigned char* _iv,
        encoding_t encoding
) {

    unsigned int s = bits / 8;

    if(algorithm == aes_cbc) {

        unsigned char key[s];
        if(_key == ((void *) 0)) {
            fill_srand(bits, key);
        }

        printk("test");

    }

}
