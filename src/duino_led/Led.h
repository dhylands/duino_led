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
 *   @file   Led.h
 *
 *   @brief  Abstraction for an LED.
 *
 ****************************************************************************/

#pragma once

//! Class for abstracting an LED.
//! @details In particular, this class introduces the notion of on and off,
class Led {
 public:
    //! Constructor
    Led() {}

    //! Destructor
    virtual ~Led() {}

    //! Turns the LED on.
    virtual void on() = 0;

    //! Turns the LED off.
    virtual void off() = 0;

    //! Toggles the state of the LED.
    virtual void toggle() = 0;
};
