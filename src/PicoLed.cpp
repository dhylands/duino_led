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
 *   @file   PicoLed.cpp
 *
 *   @brief  Implements an LED on a GPIO pin for the RPi Pico
 *
 ****************************************************************************/

#include "duino_led/PicoLed.h"

PicoLed::PicoLed(uint pin, Active active)
    : pin{pin}, on_val{active == Active::HIGH}, off_val(active == Active::LOW) {}

void PicoLed::init() {
    gpio_init(this->pin);
    gpio_set_dir(this->pin, GPIO_OUT);
}

void PicoLed::on() {
    gpio_put(this->pin, this->on_val);
}

void PicoLed::off() {
    gpio_put(this->pin, this->off_val);
}

void PicoLed::toggle() {
    if (gpio_get(this->pin) == this->on_val) {
        gpio_put(this->pin, this->off_val);
    } else {
        gpio_put(this->pin, this->on_val);
    }
}
