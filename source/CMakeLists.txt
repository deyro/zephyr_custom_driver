# Copyright (c) 2024 RD Technologies
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.20.0)

# Add our modules directory to Zephyr Modules
list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/modules)

# Set project, dts and board directories
set(PROJ_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/)
set(DTS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/dts)
set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR})


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_custom_driver)

add_subdirectory(src)
#target_sources(app PRIVATE src/main.c)
