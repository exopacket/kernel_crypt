cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
project(KernelCrypt C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_definitions(-D__KERNEL__ -DMODULE)

execute_process(
        COMMAND uname -r
        OUTPUT_VARIABLE KERNEL_RELEASE
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

find_path(
        KERNELHEADERS_DIR
        include/linux/user.h
        PATHS /usr/src/linux-headers-${KERNEL_RELEASE}
)

#set(KERNELHEADERS_DIR /usr/src/linux-headers-5.19.0-32-generic)

message(STATUS "Kernel release: ${KERNEL_RELEASE}")
message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}")

include_directories(
        ${KERNELHEADERS_DIR}/include
#        /usr/include
#        /usr/src/linux-source-5.15.0/include
)

set(DRIVER_FILE mod_template.ko)
set(KBUILD_CMD $(MAKE) -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR})

FILE(WRITE
        ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild
"obj-m := mod_template.o
KVERSION:=$(shell uname -r)
KDIR:= ${KERNELHEADERS_DIR}
PWD:= $(shell pwd)

all:
\tmake -C $(KDIR) M=$(PWD) modules
clean:
\tmake -C $(KDIR) M=$(PWD) clean
")

add_custom_command(OUTPUT ${DRIVER_FILE}
        COMMAND ${KBUILD_CMD}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS mod_template.c VERBATIM)

add_custom_target(driver ALL DEPENDS ${DRIVER_FILE})

#add_library(
#        kernel_crypt
##        src/kernel_crypt.c
##        src/kernel_crypt.h
##        src/aes/aes.h
##        src/aes/aes.c
##        src/utils/hex.c
##        src/utils/hex.h
##        src/sha/sha.c
##        src/sha/sha.h
##        src/utils/b64.c
##        src/utils/b64.h
##        src/random/rand.c
##        src/random/rand.h
##        src/utils/types.h
##        src/utils/vrg.h
#        mod_template.c
#)