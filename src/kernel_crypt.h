#ifndef KERNELCRYPT_KERNEL_CRYPT_H
#define KERNELCRYPT_KERNEL_CRYPT_H

#include <linux/stddef.h>
#include "utils/vrg.h"
#include "utils/types.h"

alg_t default_alg = aes_cbc;
bits_t default_bits = s_256;
unsigned char* default_key = NULL;
unsigned char* default_iv = NULL;
encoding_t default_encoding = bytes;

alg_t default_alg_h = sha3;
bits_t default_bits_h = s_384;
unsigned char* default_key_h = NULL;
encoding_t default_encoding_h = hex;

#define encrypt(...)                                            vrg(encrypt_f, __VA_ARGS__)
#define encrypt_2arg(arg1, arg2)                                encrypt_f(arg1, arg2, default_alg, default_bits, default_key, default_iv, default_encoding)
#define encrypt_3arg(arg1, arg2, arg3)                          encrypt_f(arg1, arg2, arg3, default_bits, default_key, default_iv, default_encoding)
#define encrypt_4arg(arg1, arg2, arg3, arg4)                    encrypt_f(arg1, arg2, arg3, arg4, default_key, default_iv, default_encoding)
#define encrypt_5arg(arg1, arg2, arg3, arg4, arg5)              encrypt_f(arg1, arg2, arg3, arg4, arg5, default_iv, default_encoding)
#define encrypt_6arg(arg1, arg2, arg3, arg4, arg5, arg6)        encrypt_f(arg1, arg2, arg3, arg4, arg5, arg6, default_encoding)
#define encrypt_7arg(arg1, arg2, arg3, arg4, arg5, arg6, arg7)  encrypt_f(arg1, arg2, arg3, arg4, arg5, arg6, arg7)

#define decrypt(...)                                            vrg(decrypt_f, __VA_ARGS__)
#define decrypt_2arg(arg1, arg2)                                decrypt_f(arg1, arg2, default_alg, default_bits, default_key, default_iv, default_encoding)
#define decrypt_3arg(arg1, arg2, arg3)                          decrypt_f(arg1, arg2, arg3, default_bits, default_key, default_iv, default_encoding)
#define decrypt_4arg(arg1, arg2, arg3, arg4)                    decrypt_f(arg1, arg2, arg3, arg4, default_key, default_iv, default_encoding)
#define decrypt_5arg(arg1, arg2, arg3, arg4, arg5)              decrypt_f(arg1, arg2, arg3, arg4, arg5, default_iv, default_encoding)
#define decrypt_6arg(arg1, arg2, arg3, arg4, arg5, arg6)        decrypt_f(arg1, arg2, arg3, arg4, arg5, arg6, default_encoding)
#define decrypt_7arg(arg1, arg2, arg3, arg4, arg5, arg6, arg7)  decrypt_f(arg1, arg2, arg3, arg4, arg5, arg6, arg7)

#define hash(...)                                               vrg(hash_f, __VA_ARGS__)
#define hash_2arg(arg1, arg2)                                   hash_f(arg1, arg2, default_alg_h, default_bits_h, default_key_h, default_encoding_h)
#define hash_3arg(arg1, arg2, arg3)                             hash_f(arg1, arg2, arg3, default_bits_h, default_key_h, default_encoding_h)
#define hash_4arg(arg1, arg2, arg3, arg4)                       hash_f(arg1, arg2, arg3, arg4, default_key_h, default_encoding_h)
#define hash_5arg(arg1, arg2, arg3, arg4, arg5)                 hash_f(arg1, arg2, arg3, arg4, arg5, default_encoding_h)
#define hash_6arg(arg1, arg2, arg3, arg4, arg5, arg6)           hash_f(arg1, arg2, arg3, arg4, arg5, arg6)

int encrypt_f(
        unsigned char* input,
        crypto_res_t* output,
        alg_t algorithm,
        bits_t bits,
        unsigned char* key,
        unsigned char* iv,
        encoding_t encoding
);

int decrypt_f(
        unsigned char* input,
        crypto_res_t* output,
        alg_t algorithm,
        bits_t bits,
        unsigned char* key,
        unsigned char* iv,
        encoding_t encoding
);

int hash_f(
        unsigned char* input,
        hash_res_t* output,
        alg_t algorithm,
        bits_t bits,
        unsigned char* key,
        encoding_t encoding
);

#endif //KERNELCRYPT_KERNEL_CRYPT_H
