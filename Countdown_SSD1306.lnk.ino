/*-------------------------------------------
 * Countdown with SSD1306
 * Credits: Diogo Vilhena
 * https://github.com/VilhenaChen
 *-------------------------------------------
 */
 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//Variables declaration Hour(hora) Minute(minu) Second(sec)
int hora = 53;
int minu = 57;
int sec = 60;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x64
  display.fillScreen(0);
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  do {
    display.clearDisplay(); //Used to clear the display
    //Text stuff, Size and Color
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(13,0); //setCursor(x,y) //Change to your needs
    display.print("Countdown");
    display.setCursor(25,15);
    display.setCursor(13,40);
    display.setTextSize(2);
    //This if(variable < 10) ensures that if the number is below 2 digits, it will remain centered otherwise justs prints the variable
    if( hora < 10) {
      display.print("0");
      display.setCursor(25,40);
      display.print(hora);
    }
    else {
      display.print(hora);
    }
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
    //Delay for 1s = 1000ms
    delay(1000);
    //The maths behinf this, if sec==0 then minu=minu-1 and if minu==0 then hora=hora-1, just the basics of a clock
    sec = sec - 1;
    if(sec == 0) {
      sec = 60;
      minu = minu - 1;
    }
    if (minu < 0) {
      minu = 60;
      hora = hora - 1;
    }
    display.display(); //Display the corrent countdown
  } while (hora != 0);
}
