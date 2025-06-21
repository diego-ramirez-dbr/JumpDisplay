# JumpDisplay

A lightweight Arduino library for controlling two-digit 7-segment LED displays using TPIC6B595 shift registers.

## Features

- Clean C++ class interface
- Works with Arduino Nano Every and other boards
- Fully portable for use in embedded projects

## Usage

```cpp
#include <JumpDisplay.h>

JumpDisplay display(11, 13, 10); // DATA, CLOCK, LATCH

void setup() {
  display.begin();
  display.displayNumber(42);
}

void loop() {
  // Update display as needed
}