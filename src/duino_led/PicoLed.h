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
 *   @file   ArduinoLed.h
 *
 *   @brief  Implements an LED on a GPIO pin for the Arduino
 *
 ****************************************************************************/

#pragma once

#include "hardware/gpio.h"

#include "duino_led/Led.h"

//! Class to encapsulate an LED attached to a Pico GPIO.
class PicoLed : public Led {
 public:
    //! Indicates how the LED is wired.
    enum class Active {
        LOW = 0,   //!< A LOW signal causes the LED to turn off.
        HIGH = 1,  //!< A HIGH signal causes the LedLED to turn on.
    };

    //! Constructor
    PicoLed(
        uint pin,                     //!< [in] Pin connected to the LED.
        Active active = Active::HIGH  //!< [in] Indicates how the LED is wired.
    );

    //! Initializes the pin to be an output.
    void init();

    //! Turns the LED on.
    void on() override;

    //! Turns the LED off.
    void off() override;

    //! Toggles the state of the LED.
    void toggle() override;

 private:
    uint pin;      //!< This is the pin hooked up to the LED
    bool on_val;   //!< This value turns the LED on
    bool off_val;  //!< This value turns the LED off
};
