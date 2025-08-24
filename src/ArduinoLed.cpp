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
 *   @file   ArduinoLed.cpp
 *
 *   @brief  Implements an LED on a GPIO pin for the Arduino
 *
 ****************************************************************************/

#include "duino_led/ArduinoLed.h"

ArduinoLed::ArduinoLed(pin_size_t pin, Active active)
    : pin{pin},
      on_val{active == Active::HIGH ? PinStatus::HIGH : PinStatus::LOW},
      off_val(active == Active::HIGH ? PinStatus::LOW : PinStatus::HIGH) {}

void ArduinoLed::init() {
    pinMode(this->pin, OUTPUT);
}

void ArduinoLed::on() {
    digitalWrite(this->pin, this->on_val);
}

void ArduinoLed::off() {
    digitalWrite(this->pin, this->off_val);
}

void ArduinoLed::toggle() {
    if (digitalRead(this->pin) == this->on_val) {
        digitalWrite(this->pin, this->off_val);
    } else {
        digitalWrite(this->pin, this->on_val);
    }
}
