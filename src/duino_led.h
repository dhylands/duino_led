/****************************************************************************
 *
 *   @copyright Copyright (c) 2024 Dave Hylands     <dhylands@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the MIT License version as described in the
 *   LICENSE file in the root of this repository.
 *
 ****************************************************************************/
/**
 *   @file   duino_led.h
 *
 *   @brief  Arduino LED functions
 *
 ****************************************************************************/

#pragma once

#include "ArduinoLed.h"
#if defined(DUINOLED_USE_NEOPIXEL)
#include "NeoPixelLed.h"
#endif
