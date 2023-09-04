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

message(STATUS "Kernel release: ${KERNEL_RELEASE}")
message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}")

include_directories(
        ${KERNELHEADERS_DIR}/include
)

set(OBJECTS "src/kernel_crypt.o src/aes/aes.o src/utils/hex.o src/sha/sha.o src/utils/b64.o src/random/rand.o")
set(DRIVER_FILE mymodule.ko)
set(KBUILD_CMD $(MAKE) -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR})

FILE(WRITE
        ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild
"KDIR:=${KERNELHEADERS_DIR}
KVERSION:=$(shell uname -r)
PWD:=$(shell pwd)

obj-m+=mymodule.o
mymodule-y:=mod_template.o ${OBJECTS}

all:
\t$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
\t$(MAKE) -C $(KDIR) M=$(PWD) clean
")

add_custom_command(OUTPUT ${DRIVER_FILE}
        COMMAND ${KBUILD_CMD}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS mod_template.c VERBATIM)

add_custom_target(driver ALL DEPENDS ${DRIVER_FILE})