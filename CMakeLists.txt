cmake_minimum_required(VERSION 3.26)
project(KernelCrypt C)

set(CMAKE_C_STANDARD 11)


include_directories(/usr/src/linux-headers-5.15.0-79/include /usr/include/linux /usr/src/linux-headers-5.19.0-32-generic/include)

add_library(KernelCrypt src/kernel_crypt.c src/kernel_crypt.h
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
