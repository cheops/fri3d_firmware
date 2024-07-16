#pragma once

#include "driver/gpio.h"

// Capabilities
#define BSP_CAPS_DISPLAY        0
#define BSP_CAPS_TOUCH          0
#define BSP_CAPS_BUTTONS        0
#define BSP_CAPS_AUDIO          0
#define BSP_CAPS_AUDIO_SPEAKER  0
#define BSP_CAPS_AUDIO_MIC      0
#define BSP_CAPS_LED            1
#define BSP_CAPS_SDCARD         0
#define BSP_CAPS_IMU            1

// Pinout

// Leds
#define BSP_LED_RGB_GPIO        (GPIO_NUM_2)
#define BSP_LED_NUM             (15)

// IC2
#define BSP_IC2_SDA             (GPIO_NUM_21)
#define BSP_IC2_SCL             (GPIO_NUM_22)
#define CONFIG_I2CDEV_TIMEOUT   (100)

// IMU
#define BSP_IMU_ADDR            (0x18)
