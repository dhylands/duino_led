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

NeoPixelLed::NeoPixelLed(Adafruit_NeoPixel* strip, Led id, Color color)
    : strip{strip}, led{led}, color{color} {}

void NeoPixelLed::init() {
    this->off();
}

void NeoPixelLed::on() {
    ColorValue currColor = this->strip->getPixelColor(this->led);
    currColor |= this->color;
    strip->setPixelColor(this->led, currColor);
    strip->show();
}

void NeoPixelLed::off() {
    ColorValue currColor = this->strip->getPixelColor(this->led);
    currColor &= ~this->color;
    strip->setPixelColor(this->led, currColor);
    strip->show();
}

void NeoPixelLed::toggle() {
    ColorValue currColor = this->strip->getPixelColor(this->led);
    currColor ^= this->color;
    this->strip->setPixelColor(this->led, currColor);
    strip->show();
}
