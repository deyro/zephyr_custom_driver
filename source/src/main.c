/*
 * Copyright (c) 2024 RD Technologies
 * SPDX-License-Identifier: MIT
 *
 *  Created on: 21-Mar-2024
 *      Author: Rohan Dey (rd@rodeytech.com)
 */

#include <stdio.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main);

int main(void)
{
	printf("Custom sensor driver demo on: %s\n", CONFIG_BOARD);

	const struct device* sim_dev1 = DEVICE_DT_GET(DT_NODELABEL(sensor_sim1));
	if (sim_dev1 == NULL) {
		LOG_ERR("device sensor_sim1 not found");
		return -1;
	}

	const struct device* sim_dev2 = DEVICE_DT_GET(DT_NODELABEL(sensor_sim2));
	if (sim_dev2 == NULL) {
		LOG_ERR("device sensor_sim2 not found");
		return -1;
	}

	struct sensor_value val;

	while (1) {
		sensor_sample_fetch_chan(sim_dev1, SENSOR_CHAN_AMBIENT_TEMP);
		sensor_channel_get(sim_dev1, SENSOR_CHAN_AMBIENT_TEMP, &val);
		LOG_INF("sim1 val = %d\n", val.val1);

		sensor_sample_fetch_chan(sim_dev2, SENSOR_CHAN_AMBIENT_TEMP);
		sensor_channel_get(sim_dev2, SENSOR_CHAN_AMBIENT_TEMP, &val);
		LOG_INF("sim2 val = %d\n", val.val1);

		k_sleep(K_MSEC(1000));
	}

	return 0;
}
