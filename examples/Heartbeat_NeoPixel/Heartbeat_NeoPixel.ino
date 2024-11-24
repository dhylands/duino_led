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
 *   @note   This example was designed to run on the Rp2040-Zero/Tiny/One.
 *
 ****************************************************************************/

#include <Arduino.h>

#define DUINO_LED_USE_NEOPIXEL 1

#include "duino_led.h"
#include "duino_util.h"

//! On the Waveshare RP2040-Tiny/Zero/One the LED is on GPIO 16
#define LED_PIN 16

//! On the Waveshare RP2040-Tiny/Zero/One there is a single LED
#define LED_COUNT 1

static Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

static NeoPixelLed red(&strip, 0, NeoPixelLed::Color::RED);
static NeoPixelLed green(&strip, 0, NeoPixelLed::Color::GREEN);

static TimedActionSequence::Action heartbeat_list[] = {
    {std::bind(&Led::toggle, red), 100},
    {std::bind(&Led::toggle, red), 100},
    {std::bind(&Led::toggle, red), 100},
    {std::bind(&Led::toggle, red), 700},
};
static TimedActionSequence heartbeat{heartbeat_list, LEN(heartbeat_list)};

static TimedActionSequence::Action activity_list[] = {
    {std::bind(&Led::toggle, green), 20},
    {std::bind(&Led::toggle, green), 20},
};
static TimedActionSequence activity{
    activity_list, LEN(activity_list), TimedActionSequence::Mode::ONE_SHOT};

//! One time initialization.
void setup() {
    strip.begin();
    strip.setBrightness(25);
    heartbeat.init();
    activity.init();
    Serial.begin();
}

//! Runs indefinitely
void loop() {
    heartbeat.run();
    activity.run();
    if (Serial.available()) {
        char ch = Serial.read();
        activity.start();
        Serial.print(ch);
    }
}
