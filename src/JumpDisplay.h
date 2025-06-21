#pragma once
#include <Arduino.h>

class JumpDisplay {
public:
  JumpDisplay(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);
  void begin();
  void displayNumber(uint8_t number);

private:
  uint8_t _dataPin, _clockPin, _latchPin;
  void shiftOutSafe(uint8_t val);
  void updateDisplay(uint8_t digit1, uint8_t digit2);

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