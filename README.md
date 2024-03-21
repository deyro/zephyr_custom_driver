# zephyr_custom_driver
A Zephyr RTOS project to demonstrate a custom device drivers for Zephyr using Zephyr's sensor interface.
The driver produces simulated data. It can be enhanced to work for an actual device like a temperature sensor, accelerometer etc.
This project will enable developers to create drivers for devices not yet supported by the [Zephyr RTOS project](https://github.com/zephyrproject-rtos/zephyr) and use it in an application.

The project's device tree adds 2 instances of the custom driver and the main function uses the sensor APIs to fetch and get data from the driver.
The driver generates a random number which is used as the sensor's value which is returned to the main application.

## Zephyr RTOS installation
Follow the [Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/index.html) to install Zephyr RTOS.

## How to build
The demo uses `native_posix` board but any other board from the [Supported Boards](https://docs.zephyrproject.org/latest/boards/index.html) can be used.
This project has been build and tested with `Zephyr v3.5.0`

To build the project, use any of the following commands:

```
west build -p always -d build/ source/ -b native_posix
```

If you want to build and generate an Eclipse project then use:
```
west build -p always -d build/ source/ -b native_posix -G"Eclipse CDT4 - Ninja"
```

## How to run
For `native_posix` board run the `zephyr.exe` program as shown below
```
./build/zephyr/zephyr.exe
```

For an actual hardware, flash with `west flash` to run the code.

See [Getting Started Guide - Flash](https://docs.zephyrproject.org/latest/develop/getting_started/index.html#flash-the-sample) for more info.
