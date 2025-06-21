#include "JumpDisplay.h"

JumpDisplay::JumpDisplay(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin)
  : _dataPin(dataPin), _clockPin(clockPin), _latchPin(latchPin) {}

void JumpDisplay::begin() {
  pinMode(_dataPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
}

void JumpDisplay::displayNumber(uint8_t number) {
  uint8_t right = digitFlipped[number % 10];
  uint8_t left = (number >= 10) ? digitFlipped[(number / 10) % 10] : 0;
  updateDisplay(right, left);
}

void JumpDisplay::updateDisplay(uint8_t d1, uint8_t d2) {
  digitalWrite(_latchPin, LOW);
  shiftOutSafe(d2);  // left digit
  shiftOutSafe(d1);  // right digit
  digitalWrite(_latchPin, HIGH);
}

void JumpDisplay::shiftOutSafe(uint8_t val) {
  for (int i = 7; i >= 0; i--) {
    digitalWrite(_clockPin, LOW);
    digitalWrite(_dataPin, (val >> i) & 0x01);
    digitalWrite(_clockPin, HIGH);
  }
}