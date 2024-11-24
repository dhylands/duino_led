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
 *   @file   NeoPixelLed.cpp
 *
 *   @brief  Implements am LED using a NeoPixel
 *
 ****************************************************************************/

#include "NeoPixelLed.h"

#if defined(DUINO_LED_USE_NEOPIXEL)

NeoPixelLed::NeoPixelLed(Adafruit_NeoPixel* strip, Led id, Color color)
    : strip{strip}, led{led}, color{color} {}

void NeoPixelLed::init() {
    this->off();
}

void NeoPixelLed::on() {}

void NeoPixelLed::off() {}

void NeoPixelLed::toggle() {}

#endif  // DUINO_LED_USE_NEOPIXEL
