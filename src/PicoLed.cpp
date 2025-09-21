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
#include "duino_util/Util.h"

static PicoLed g_debugLed[] = {
    PicoLed(2),
    PicoLed(3),
};

void debugLedInit() {
    for (auto& led : g_debugLed) {
        led.init();
        led.off();
    }
}

void debugLed(uint num, bool on) {
    if (num < LEN(g_debugLed)) {
        if (on) {
            g_debugLed[num].on();
        } else {
            g_debugLed[num].off();
        }
    }
}

PicoLed::PicoLed(uint pin, Active active)
    : m_pin{pin}, m_on_val{active == Active::HIGH}, m_off_val(active == Active::LOW) {}

void PicoLed::init() {
    gpio_init(this->m_pin);
    gpio_set_dir(this->m_pin, GPIO_OUT);
    this->m_initialized = true;
}

void PicoLed::on() {
    if (this->m_initialized) {
        gpio_put(this->m_pin, this->m_on_val);
    }
}

void PicoLed::off() {
    if (this->m_initialized) {
        gpio_put(this->m_pin, this->m_off_val);
    }
}

void PicoLed::toggle() {
    if (this->m_initialized) {
        if (gpio_get(this->m_pin) == this->m_on_val) {
            gpio_put(this->m_pin, this->m_off_val);
        } else {
            gpio_put(this->m_pin, this->m_on_val);
        }
    }
}
