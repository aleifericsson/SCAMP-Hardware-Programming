#include <TFT_eSPI.h>
#include <SPI.h>


TFT_eSPI tft = TFT_eSPI();  // Uses pins from User_Setup.h

#define red_in 32
#define green_in 33
#define blue_in 25

int prevRed = LOW;
int prevGreen = LOW;
int prevBlue = LOW;

void setup() {
  Serial.begin(9600);
  
  pinMode(red_in,   INPUT_PULLDOWN);
  pinMode(green_in, INPUT_PULLDOWN);
  pinMode(blue_in,  INPUT_PULLDOWN);
  
  Serial.println("Starting...");

  tft.init();              // REQUIRED
  tft.setRotation(2);      // Optional, but recommended
  tft.fillScreen(TFT_BLACK);  // Clear once before timing

  // --- Time fillScreen() properly ---
  uint32_t start = millis();
  tft.fillScreen(TFT_BLACK);
  uint32_t elapsed = millis() - start;

  Serial.print("fillScreen() took: ");
  Serial.print(elapsed);
  Serial.println(" ms");
}

void loop() {
  int r = digitalRead(red_in);
  int g = digitalRead(green_in);
  int b = digitalRead(blue_in);

  // --- Detect rising edges ---
  if (r == HIGH && prevRed == LOW) {
    tft.fillScreen(TFT_RED);
  }
  if (g == HIGH && prevGreen == LOW) {
    tft.fillScreen(TFT_GREEN);
  }
  if (b == HIGH && prevBlue == LOW) {
    tft.fillScreen(TFT_BLUE);
  }

  // Update previous states
  prevRed = r;
  prevGreen = g;
  prevBlue = b;
  
}
