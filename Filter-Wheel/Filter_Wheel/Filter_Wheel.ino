/*   
 *   Basic example code for controlling a stepper without library
 *      
 *   by Dejan, https://howtomechatronics.com
 */

// defines pins
#define stepPin 17
#define dirPin 16 
#define red_in 32
#define green_in 33
#define blue_in 25

#define red_pos 100
#define green_pos 33
#define blue_pos 66

int current_pos = 0;
int current_color = 0;//0 = red, 1 = green, 2 = blue

int prevRed = LOW;
int prevGreen = LOW;
int prevBlue = LOW;


void setup() {
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  digitalWrite(stepPin, LOW);
  digitalWrite(dirPin, LOW);

  pinMode(red_in,   INPUT_PULLDOWN);
  pinMode(green_in, INPUT_PULLDOWN);
  pinMode(blue_in,  INPUT_PULLDOWN);
}


void stepN(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(700);
  }
  current_pos += steps;
}


/*
void stepN(int steps) {
  int startDelay = 700;   // total period (µs)
  int endDelay   = 250;   // total period (µs)

  for (int i = 0; i < steps; i++) {

    int totalPeriod = startDelay -
      ((startDelay - endDelay) * i) / (steps - 1);

    int halfPeriod = totalPeriod / 2;

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(halfPeriod);

    digitalWrite(stepPin, LOW);
    delayMicroseconds(halfPeriod);
  }

  current_pos += steps;
}
*/

void loop() {
  digitalWrite(dirPin, HIGH);
  
  int r = digitalRead(red_in);
  int g = digitalRead(green_in);
  int b = digitalRead(blue_in);

  if (r == HIGH && prevRed == LOW) {
    if (current_color == 1){
      stepN(67);
    }
    else if (current_color == 2){
      stepN(34);
    }
    current_pos = 0;
    current_color = 0;
    Serial.println("Red");
  }
  if (g == HIGH && prevGreen == LOW) {
    if (current_color == 0){
      stepN(33);
    }
    else if (current_color == 2){
      stepN(67);
    }
    current_pos = 0;
    current_color = 1;
    Serial.println("Green");
  }
  if (b == HIGH && prevBlue == LOW) {
    if (current_color == 0){
      stepN(66);
    }
    else if (current_color == 1){
      stepN(33);
    }
    current_pos = 0;
    current_color = 2;
    Serial.println("Blue");
  }

  prevRed = r;
  prevGreen = g;
  prevBlue = b;
  delay(5);
}
