#include "thingProperties.h"

#define LDR 15
#define LED_STRONG 23
#define LED_DIM 21
#define IRS 19

void setup() {
  Serial.begin(9600);
  delay(1500);

  pinMode(LED_STRONG, OUTPUT);
  pinMode(LED_DIM, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(IRS, INPUT);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
}

void loop() {
  ArduinoCloud.update();

  light = analogRead(LDR);
  Serial.println(light);
  presence = !digitalRead(IRS);

  if (light < 400 && presence == LOW) {
    digitalWrite(LED_STRONG, LOW);
    digitalWrite(LED_DIM, HIGH);
  } else if (light < 400 && presence == HIGH) {
    digitalWrite(LED_DIM, LOW);
    digitalWrite(LED_STRONG, HIGH);
  } else {
    digitalWrite(LED_STRONG, LOW);  
    digitalWrite(LED_DIM, LOW);
  }

  delay(500);
}
