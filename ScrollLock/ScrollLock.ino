// Arduino Leonardo sketch
// Type email and password after turning OFF Scroll Lock
// Obs.: For Elitebook, use Fn + C

// Install HID-Project library from NicoHood
#include "HID-Project.h"

// Header file with the credentials
// Take a look at the Credentials.sample.h
#include "Credentials.h"

bool g_bScrollLockStatus = false;
void setup() {
  Serial.begin(115200);
  BootKeyboard.begin();

  g_bScrollLockStatus = getScrollLockStatus();
}

void loop() {
  delay(100);

  auto bCurrentStatus = getScrollLockStatus();
  if (bCurrentStatus && !g_bScrollLockStatus) {
    Serial.println("Scroll Lock pressed");
  } else if (!bCurrentStatus && g_bScrollLockStatus) {
    Serial.println("Scroll Lock released");
    randomSeed(micros());
    writeEmailAndPass();
  }
  g_bScrollLockStatus = bCurrentStatus;
}

bool getScrollLockStatus() {
  return (BootKeyboard.getLeds() & LED_SCROLL_LOCK);
}

void writeEmailAndPass() {
  if (email.length()) {
    writeString(email);
    writeKey(KEY_TAB);
  }
  writeString(pass);
  writeKey(KEY_ENTER);
}

void writeString(String str) {
  for (const auto& c : str) {
    writeChar(c);
  }
}

void waitNextKey() {
  delay(random(30, 80));
}

void writeChar(char c) {
  BootKeyboard.write(c);
  waitNextKey();
}

void writeKey(KeyboardKeycode c) {
  BootKeyboard.write(c);
  waitNextKey();
}
