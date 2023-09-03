#ifndef KERNELCRYPT_TYPES_H
#define KERNELCRYPT_TYPES_H

typedef enum {
    s_512 = 512, s_384 = 384, s_256 = 256, s_192 = 192, s_128 = 128
} bits_t;

typedef enum {
    base64, hex, bytes
} encoding_t;

typedef enum {
    aes_cbc, aes_gcm, aes_ecb, sha1, sha1_hmac, sha3, sha3_hmac
} alg_t;

typedef enum {
    failure = 0, encrypted = 1, decrypted = 1, hashed = 1
} status_t;

typedef struct {
    unsigned char *data;

    unsigned char *key;
    unsigned char *iv;

    unsigned char *tag;

    status_t status;
} crypto_res_t;

typedef struct {
    unsigned char *data;

    unsigned char *key;

    status_t status;
} hash_res_t;

#endif