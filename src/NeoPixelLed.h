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
 *   @file   NeoPixelLed.h
 *
 *   @brief  Implements am LED using a NeoPixel
 *
 ****************************************************************************/

#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Led.h"

//! Implements an LED using a NeoPixel.
//! @details Allows each of the primary colors (red, green, blue) of a neopixel
//!          to be treated as an LED.
class NeoPixelLed : public Led {
 public:
    using Led = uint16_t;         //!< Alias to store a LED number.
    using ColorValue = uint32_t;  //!< Alias to store a color.

    //! Color of the NeoPixel to use.
    //! @note Currently we only support the 3 primary colors.
    enum Color : ColorValue {
        RED = 0xff0000,    //!< Red
        GREEN = 0x00ff00,  //!< Green
        BLUE = 0x0000ff,   //!< Blue
    };

    //! Constructor
    NeoPixelLed(
        Adafruit_NeoPixel* strip,  //!< NeoPixel Strip containing the LED
        Led id,                    //!< Number of the LED within the strip.
        Color color                //!< Color to assign to this LED.
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
    Adafruit_NeoPixel* strip;  //!< NeoPixel Strip containing the LED
    Led led;                   //!< Number of the LED within the strip.
    Color color;               //!< Color to assign to this LED.
};
