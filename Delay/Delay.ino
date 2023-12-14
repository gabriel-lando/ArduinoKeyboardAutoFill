// Arduino Leonardo sketch

#include "Keyboard.h"

// Time in 'ms' to wait before sending characters
const int INITIAL_DELAY = 5000;

// Header file with the credentials
// Take a look at the Credentials.sample.h
#include "Credentials.h"

void setup() {
  Keyboard.begin();

  delay(INITIAL_DELAY);

  if (email.length()){
    writeString(email);
    writeChar(KEY_TAB);
  }
  writeString(pass);
  writeChar(KEY_RETURN);
}

void writeString(String str) {
  for (const auto& c : str) {
    writeChar(c);
  }
}

void writeChar(char c) {
  Keyboard.press(c);
  delay(10);
  Keyboard.release(c);
  delay(random(50, 120));
}

void loop() {}
