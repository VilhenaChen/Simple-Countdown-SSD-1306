#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  display.fillScreen(0);
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  int hora = 53;
  int minu = 57;
  int sec = 60;
  do {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(13,0);
    display.print("Countdown");
    display.setCursor(25,15);
    //display.print("Copinho");
    display.setCursor(13,40);
    display.setTextSize(2);
    display.print(hora);
    display.setCursor(34,40);
    display.print(":");
    display.setCursor(41,40);
    if( minu < 10) {
      display.print("0");
      display.setCursor(53,40);
      display.print(minu);
    }
    else {
      display.print(minu);
    }
    display.setCursor(62,40);
    display.print(":");
    display.setCursor(70,40);
    display.print(sec);
    delay(1000);
    sec = sec - 1;
    if(sec == 0) {
      sec = 60;
      minu = minu - 1;
    }
    if (minu < 0) {
      minu = 60;
      hora = hora - 1;
    }
    display.display();
  } while (hora != 0);
}
