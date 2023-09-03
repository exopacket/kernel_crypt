cmake_minimum_required(VERSION 3.26)
project(KernelCrypt C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Module info
#add_definitions(-D__KERNEL__ -DMODULE)

#target_include_directories(kernel_crypt PRIVATE /usr/src/linux-source-5.15.0/include)

# Find the kernel release
execute_process(
        COMMAND uname -r
        OUTPUT_VARIABLE KERNEL_RELEASE
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Find the headers
find_path(
        KERNELHEADERS_DIR
        include/linux/user.h
        PATHS /usr/src/linux-headers-${KERNEL_RELEASE}
)

message(STATUS "Kernel release: ${KERNEL_RELEASE}")
message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}")

# Add header files
include_directories(
#        /usr/include
#        /usr/src/linux-source-5.15.0/include
        ${KERNELHEADERS_DIR}/include
#        /usr/src/linux-headers-5.19.0-32-generic/include
)

#set(DRIVER_FILE hello.ko)
#set(KBUILD_CMD $(MAKE) -C ${KERNELHEADERS_DIR} modules M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR})

# Generate the Kbuild file through cmake.
#FILE(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild "obj-m := hello.o")

#add_custom_command(OUTPUT ${DRIVER_FILE}
#        COMMAND ${KBUILD_CMD}
#        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#        DEPENDS hello.c VERBATIM)

#add_custom_target(driver ALL DEPENDS ${DRIVER_FILE})
# Parse c files
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