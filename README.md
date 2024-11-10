# duino_led

[TOC]

Arduino Library for LEDs.

## Led

The 'Led' class is an abstract interface for LEDs that provides `on`, `off`, and `toggle` methods.

There is an `ArduinoLed` class which allows for active low or active high
wirings of LEDs connected to a GPIO pin.

There is a `NeoPixelLed` class which allows for NeoPixels to be used as a LED as well. The RP2040-Zero/Tiny/One boards all come with an onboard  NeoPixel in place of a LED.
