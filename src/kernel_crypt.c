#include <linux/stddef.h>
#include "kernel_crypt.h"
#include "utils/types.h"

int encrypt_f(
        unsigned char* input,
        crypto_res_t* output,
        alg_t algorithm,
        bits_t bits,
        unsigned char* key,
        unsigned char* iv,
        encoding_t encoding
) {

    if(algorithm == aes_cbc) {

        if(key == NULL) {

        }

    }

}
