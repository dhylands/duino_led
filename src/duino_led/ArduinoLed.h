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

#include <Arduino.h>
#include "duino_led/Led.h"

// Normally, ArduinoCore-API/api/Common.h defines pin_size_t and PinStatus
// But the ESP32 platformm doesn't seem to have that header and
// esp32-hal-gpio.h #define's LOW and HIGH

#if defined(LOW)

#undef LOW
#undef HIGH

//! Status of a Pin
enum PinStatus {
    LOW = 0,
    HIGH = 1,
};

using pin_size_t = uint8_t;
#endif  // ARDUINO_ARCH_ESP32

//! Class to encapsulate an LED attached to an Arduino GPIO.
class ArduinoLed : public Led {
 public:
    //! Indicates how the LED is wired.
    enum class Active {
        LOW = 0,   //!< A LOW signal causes the LED to turn off.
        HIGH = 1,  //!< A HIGH signal causes the LedLED to turn on.
    };

    //! Constructor
    ArduinoLed(
        pin_size_t pin,               //!< [in] Pin connected to the LED.
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
    pin_size_t pin;     //!< This is the pin hooked up to the LED
    PinStatus on_val;   //!< This value turns the LED on
    PinStatus off_val;  //!< This value turns the LED off
};
