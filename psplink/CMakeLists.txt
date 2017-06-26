cmake_minimum_required(VERSION 2.8)

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
)

add_executable(${PROJECT_NAME}
        main.c
        shell.c
        )

target_link_libraries(${PROJECT_NAME}
        SceAppMgr_stub
        SceSysmem_stub
        SceIofilemgr_stub
        SceLibKernel_stub
        SceKernelThreadMgr_stub
        taihen_stub
        gcc
        )
vita_create_self(${PROJECT_NAME}.suprx ${PROJECT_NAME}
        #CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/exports.yml
        UNSAFE)

#add_custom_target(${PROJECT_NAME}.stubs
#        COMMAND rm -rf ${CMAKE_SOURCE_DIR}/knet/stub
#        COMMAND ${VITASDK}/bin/vita-libs-gen ${CMAKE_SOURCE_DIR}/knet/db.yml ${CMAKE_SOURCE_DIR}/knet/stub
#        COMMAND VITASDK=${VITASDK} make -C ${CMAKE_SOURCE_DIR}/knet/stub
#        )
#add_dependencies(${PROJECT_NAME}.elf ${PROJECT_NAME}.stubs)
