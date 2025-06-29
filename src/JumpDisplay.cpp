#include "JumpDisplay.h"

JumpDisplay::JumpDisplay(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin)
  : _dataPin(dataPin), _clockPin(clockPin), _latchPin(latchPin) {}

  void JumpDisplay::begin() {
    pinMode(_dataPin, OUTPUT);
    pinMode(_clockPin, OUTPUT);
    pinMode(_latchPin, OUTPUT);
  
    digitalWrite(_dataPin, LOW);
    digitalWrite(_clockPin, LOW);
    digitalWrite(_latchPin, LOW);
  
    displayNumber(0);
  }

void JumpDisplay::displayNumber(uint8_t number) {
  uint8_t rightDigit = digitFlipped[number % 10];
  uint8_t leftDigit  = (number >= 10) ? digitFlipped[(number / 10) % 10] : 0b00000000;
  updateDisplay(rightDigit, leftDigit);
}

void JumpDisplay::updateDisplay(uint8_t digit1, uint8_t digit2) {
  Serial.print("Updating display: ");
  Serial.print(digit1);
  Serial.print(" ");
  Serial.println(digit2);

  digitalWrite(_latchPin, LOW);

  // REVERSE THE ORDER
  shiftOutSafe(digit2);  // Send left digit first
  shiftOutSafe(digit1);  // Then right digit

  digitalWrite(_latchPin, HIGH);
}

void JumpDisplay::shiftOutSafe(uint8_t val) {
  for (int i = 7; i >= 0; i--) {
    digitalWrite(_clockPin, LOW);
    delayMicroseconds(1);  // 👈 add this line
    digitalWrite(_dataPin, (val >> i) & 1);
    delayMicroseconds(1);  // 👈 add this line
    digitalWrite(_clockPin, HIGH);
    delayMicroseconds(1);  // 👈 add this line
  }
}