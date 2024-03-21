# Copyright (c) 2024 RD Technologies
# SPDX-License-Identifier: MIT

if (CONFIG_SENSOR_SIM)
	zephyr_include_directories(./)
	zephyr_library()
	zephyr_library_sources(sensor_sim.c)
endif()