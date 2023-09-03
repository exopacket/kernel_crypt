//
// Created by root on 9/2/23.
//

#ifndef KERNELCRYPT_AES_H
#define KERNELCRYPT_AES_H

#include "../utils/types.h"

int aes_ecb_encdec(
        unsigned char *input,
        unsigned char *output,
        bits_t bits,
        unsigned char *key,
        encoding_t encoding,
        int encrypt
);

int aes_cbc_encdec(
        unsigned char *input,
        unsigned char *output,
        bits_t bits,
        unsigned char *key,
        unsigned char *iv,
        encoding_t encoding,
        int encrypt
);

int aes_gcm_encdec(
        unsigned char *input,
        unsigned char *output,
        bits_t bits,
        unsigned char *key,
        unsigned char *iv,
        unsigned char *tag,
        encoding_t encoding,
        int encrypt
);

#endif //KERNELCRYPT_AES_H
