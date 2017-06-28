cmake_minimum_required(VERSION 2.8)

enable_language(ASM)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if (DEFINED ENV{VITASDK})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
    else ()
        message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
    endif ()
endif ()

project(psplink)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-q -Wall -O3 -std=gnu99 -D__PSP2__ -D_PSP_FW_VERSION=199")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -D__PSP2__ -D_PSP_FW_VERSION=199")

include_directories(
        ../usbhostfs
        ../psp2
)

link_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_BINARY_DIR}/usbhostfs/usbhostfs.stubs
)

# user testing
add_executable(${PROJECT_NAME}-u
        main.c
        shell.c
        usbshell.c
        util.c
        ../psp2/setjmp.S
        )
target_link_libraries(${PROJECT_NAME}-u
        k
        gcc
        SceAppMgr_stub
        SceSysmem_stub
        SceIofilemgr_stub
        SceLibKernel_stub
        SceProcessmgr_stub
        SceKernelThreadMgr_stub
        usbhostfs_stub
        taihen_stub
        )
set_target_properties(${PROJECT_NAME}-u
        PROPERTIES LINK_FLAGS "-nostdlib"
        )
vita_create_self(${PROJECT_NAME}-u.suprx ${PROJECT_NAME}-u
        CONFIG ${CMAKE_SOURCE_DIR}/psp2/psplink_exports.yml
        UNSAFE)


# kernel testing
add_executable(${PROJECT_NAME}-k
        main.c
        shell.c
        usbshell.c
        util.c
        ../psp2/setjmp.S
        )
target_link_libraries(${PROJECT_NAME}-k
        k
        gcc
        SceAppMgr_stub
        SceSysmem_stub
        SceIofilemgr_stub
        SceLibKernel_stub
        SceProcessmgr_stub
        SceKernelThreadMgr_stub
        usbhostfs_stub
        taihen_stub
        )
set_target_properties(${PROJECT_NAME}-k
        PROPERTIES LINK_FLAGS "-nostdlib"
        )
vita_create_self(${PROJECT_NAME}-k.skprx ${PROJECT_NAME}-k
        CONFIG ${CMAKE_SOURCE_DIR}/psp2/psplink_exports.yml
        UNSAFE)
