//
// Created by root on 9/2/23.
//

#ifndef KERNELCRYPT_TYPES_H
#define KERNELCRYPT_TYPES_H

enum bits {s_512, s_384, s_256, s_192, s_128};
typedef enum bits bits_t;

enum encoding {base64, hex, bytes};
typedef enum encoding encoding_t;

enum algs {aes_cbc, aes_gcm, aes_ecb, sha1, sha1_hmac, sha3, sha3_hmac};
typedef enum algs alg_t;

enum statuses {failure = 0, encrypted = 1, decrypted = 1, hashed = 1};
typedef enum statuses status_t;

struct crypto_res {
    unsigned char* data;

    unsigned char* key;
    unsigned char* iv;

    unsigned char* tag;

    status_t status;
};

typedef struct crypto_res crypto_res_t;

struct hash_res {
    unsigned char* data;

    unsigned char* key;

    status_t status;
};

typedef struct hash_res hash_res_t;

#endif //KERNELCRYPT_TYPES_H