/*
 * Copyright (c) 2024 RD Technologies
 * SPDX-License-Identifier: MIT
 *
 *  Created on: 21-Mar-2024
 *      Author: Rohan Dey (rd@rodeytech.com)
 */


#define DT_DRV_COMPAT rdt_sensor_sim

#include <zephyr/drivers/sensor.h>
#include <zephyr/random/random.h>

#define LOG_LEVEL CONFIG_SENSOR_SIM_LOG_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(sensor_sim);

#include "sensor_sim.h"

struct sensor_sim_config {

};

struct sensor_sim_data {
	int sensor_attr;
	uint32_t sensor_val;
};

static int sensor_sim_sample_fetch(const struct device *dev, enum sensor_channel chan)
{
	struct sensor_sim_data *data = dev->data;
	int ret = 0;

	LOG_INF("sensor_sim_sample_fetch");

	switch (chan) {
	case SENSOR_CHAN_AMBIENT_TEMP:	/* this channel is used for demonstration only */
		/* generate a random value as the sensor output */
		data->sensor_val = sys_rand32_get() * data->sensor_attr;
		break;
	default:
		break;
	}

	return ret;
}

static int sensor_sim_channel_get(const struct device *dev, enum sensor_channel chan, struct sensor_value *valp)
{
	struct sensor_sim_data *data = dev->data;
	int ret = 0;

	LOG_INF("sensor_sim_channel_get");

	switch (chan) {
	case SENSOR_CHAN_AMBIENT_TEMP:	/* this channel is used for demonstration only */
		valp->val1 = data->sensor_val;
		break;
	default:
		break;
	}

	return ret;
}

static int sensor_sim_init(const struct device *dev)
{
	ARG_UNUSED(dev);
	int ret = 0;

	LOG_INF("sensor_sim_init");

	return ret;
}

static const struct sensor_driver_api sensor_sim_driver_api = {
	.sample_fetch = sensor_sim_sample_fetch,
	.channel_get = sensor_sim_channel_get,
};

#define DEVICE_INSTANCE(inst) \
\
const static struct sensor_sim_config sensor_sim_##inst##_cfg;\
\
static struct sensor_sim_data sensor_sim_##inst##_drvdata = { \
		.sensor_attr = DT_PROP(DT_DRV_INST(inst),sim_attr), \
}; \
\
DEVICE_DT_INST_DEFINE(inst,								\
		sensor_sim_init,								\
		device_pm_control_nop,							\
		&sensor_sim_##inst##_drvdata,					\
		&sensor_sim_##inst##_cfg,						\
		POST_KERNEL, CONFIG_SENSOR_SIM_INIT_PRIORITY,	\
		&sensor_sim_driver_api);

DT_INST_FOREACH_STATUS_OKAY(DEVICE_INSTANCE);
