#pragma once
#include <Arduino.h>

/**
 * JumpDisplay.h
 * Arduino library for controlling a 2-digit 7-segment display
 * using TPIC6B595 shift registers.
 * Author: Diego Ramirez
 * License: MIT
 */

class JumpDisplay {
public:
  // Constructor: specify the data, clock, and latch pins
  JumpDisplay(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);

  // Initializes the display pins
  void begin();

  // Displays a number from 0 to 99
  void displayNumber(uint8_t number);

private:
  uint8_t _dataPin, _clockPin, _latchPin;

  // Sends two digits to the display via shift registers
  void updateDisplay(uint8_t digit1, uint8_t digit2);

  // Safe bit-banged shiftOut implementation
  void shiftOutSafe(uint8_t val);

  // Flipped segment bitmaps for digits 0–9
  const uint8_t digitFlipped[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
  };
};