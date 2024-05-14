#include "WiFi.h"

#define RED_PIN   21
#define GREEN_PIN 20
#define BLUE_PIN  10
// These are not really attempts
// This is the number which defines how many checks there are before saying, that the connection was not successfull (10 checks per second)
#define MAX_CONNECTION_ATTEMPTS 1000


void setup() {
  setLed(0, 0, 0);

  WiFi.mode(WIFI_STA);
  //WiFi.disconnect();

  connect();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setLed(short red, short green, short blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

// Returns wether the connection was successfully established (true = yes)
bool connect() {
  setLed(255, 255, 0);
  WiFi.begin(SSID, WIFI_PASS);

  bool on = true;
  int counter = 0;

  while(WiFi.status() != WL_CONNECTED){
        if(on) {
          setLed(0, 0, 0);
        } else {
          setLed(255, 255, 0);
        }
        
        on = !on;
        counter++;

        if(counter >= MAX_CONNECTION_ATTEMPTS) {
          setLed(255, 0, 0);
          return false;
        }

        delay(100);
  }

  setLed(0, 255, 0);
  return true;
}