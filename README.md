# zephyr_custom_driver
This repo contains a dummy custom device driver for Zephyr RTOS used for demonstrate purposes

# Building
west build -p always -d build/ source/ -b native_posix -G"Eclipse CDT4 - Ninja"
