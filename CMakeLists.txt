cmake_minimum_required(VERSION 3.26)
project(KernelCrypt C)

set(CMAKE_C_STANDARD 11)

add_library(
        kernel_crypt STATIC
        src/kernel_crypt.c
        src/kernel_crypt.h
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
        src/utils/vrg.h
)

target_include_directories(kernel_crypt PRIVATE /usr/include)