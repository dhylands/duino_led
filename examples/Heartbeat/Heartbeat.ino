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
 *   @file   Heartbeat.ino
 *
 *   @brief  Example using the TimedActionSequence.
 *
 ****************************************************************************/

#include <Arduino.h>

#include "duino_led.h"
#include "duino_util.h"

#if !defined(LED_BUILTIN)
#error No definition for LED_BUILTIN
#endif

static ArduinoLed led{LED_BUILTIN, ArduinoLed::Active::HIGH};

static TimedActionSequence::Action heartbeat_list[] = {
    {std::bind(&Led::toggle, &led), 100},
    {std::bind(&Led::toggle, &led), 100},
    {std::bind(&Led::toggle, &led), 100},
    {std::bind(&Led::toggle, &led), 700},
};
static TimedActionSequence heartbeat{heartbeat_list, LEN(heartbeat_list)};

//! One time initialization.
void setup() {
    led.init();
    heartbeat.init();
}

//! Runs indefinitely
void loop() {
    heartbeat.run();
}
