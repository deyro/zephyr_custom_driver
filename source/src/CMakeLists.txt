# Copyright (c) 2024 RD Technologies
# SPDX-License-Identifier: MIT

list(APPEND app_sources 
			main.c
	)
	
target_sources(app PRIVATE ${app_sources})