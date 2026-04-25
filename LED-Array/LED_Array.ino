/*
#define red_in 34
#define green_in 35
#define blue_in 32

#define red_out 33
#define green_out 25
#define blue_out 26
*/

#define white_in 12
#define red_in 11
#define green_in 10
#define blue_in 9

#define red_out 6
#define green_out 5
#define blue_out 3

int prev_r = LOW;
int prev_g = LOW;
int prev_b = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(red_in,   INPUT);
  pinMode(green_in, INPUT);
  pinMode(blue_in,  INPUT);

  pinMode(red_out,   OUTPUT);
  pinMode(green_out, OUTPUT);
  pinMode(blue_out,  OUTPUT);
}

void loop() {
  int w = digitalRead(white_in);
  int r = digitalRead(red_in);
  int g = digitalRead(green_in);
  int b = digitalRead(blue_in);

  if (w == LOW){
    digitalWrite(red_out, r);
    digitalWrite(green_out, g);
    digitalWrite(blue_out, b);
    
    if (r != prev_r) {
      Serial.print("red: ");
      Serial.println(r);
      prev_r = r;
    }

    if (g != prev_g) {
      Serial.print("green: ");
      Serial.println(g);
      prev_g = g;
    }

    if (b != prev_b) {
      Serial.print("blue: ");
      Serial.println(b);
      prev_b = b;
    }
  }
  else{
    Serial.print("white: ");
    digitalWrite(red_out, LOW);
    digitalWrite(green_out, LOW);
    digitalWrite(blue_out, LOW);
  }

  
}
