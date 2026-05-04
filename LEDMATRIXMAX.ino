#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1

#define DATA_PIN 12
#define CLK_PIN  13
#define CS_PIN   9

MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
SoftwareSerial BT(10, 11);

// Variables
String message = "HELLO";
int speedValue = 100;
int brightness = 5;

// ❤️ HEART ICON
byte HEART[8] = {
  B01100110,B11111111,B11111111,B11111111,
  B01111110,B00111100,B00011000,B00000000
};

// 🙂 SMILE ICON
byte SMILE[8] = {
  B00111100,B01000010,B10100101,B10000001,
  B10100101,B10011001,B01000010,B00111100
};

void showIcon(byte icon[8]) {
  display.displayClear();
  for (int i = 0; i < 8; i++) {
    display.getGraphicObject()->setRow(0, i, icon[i]);
  }
}

// Start scrolling text (no end delay)
void startDisplay() {
  display.displayClear();
  display.displayText(message.c_str(), PA_CENTER, speedValue, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void setup() {
  BT.begin(115200); //set baud rate that works on your module default baud rate is 9600

  display.begin();
  display.setIntensity(brightness);
  display.setSpeed(speedValue);
  display.setPause(0);

  startDisplay();
}

void loop() {

  if (BT.available()) {
    String input = BT.readStringUntil('\n');
    input.trim();

    // TEXT
    if (input.startsWith("T:")) {
      message = input.substring(2);
      startDisplay();
    }

    // SPEED
    else if (input.startsWith("S:")) {
      speedValue = input.substring(2).toInt();
      display.setSpeed(speedValue);
      startDisplay();
    }

    // BRIGHTNESS
    else if (input.startsWith("B:")) {
      brightness = constrain(input.substring(2).toInt(), 0, 15);
      display.setIntensity(brightness);
    }

    // ICONS
    else if (input.startsWith("I:")) {
      String icon = input.substring(2);

      if (icon == "HEART") {
        showIcon(HEART);
      }
      else if (icon == "SMILE") {
        showIcon(SMILE);
      }
    }

    // RESET
    else if (input == "R") {
      message = "HELLO";
      speedValue = 100;
      brightness = 5;

      display.setSpeed(speedValue);
      display.setIntensity(brightness);

      startDisplay();
    }
  }

  if (display.displayAnimate()) {
    display.displayReset();
  }
}