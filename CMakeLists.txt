cmake_minimum_required(VERSION 3.26)
project(KernelCrypt C)

set(CMAKE_C_STANDARD 11)

add_library(KernelCrypt src/kernel_crypt.c
        src/aes/aes.h
        src/aes/aes.c
        src/utils/hex.c
        src/utils/hex.h
        src/sha/sha.c
        src/sha/sha.h
        src/utils/b64.c
        src/utils/b64.h
        src/random/rand.c
        src/random/rand.h
        src/utils/types.h
        src/utils/vrg.h)
