#define RED_PIN   21
#define GREEN_PIN 20
#define BLUE_PIN  10

void setup() {
  setLed(0, 0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setLed(short red, short green, short blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
