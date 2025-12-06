#include "thingProperties.h"

#define LDR 32
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
  
  int NODE_AMOUNT = 2;
  
  light = analogRead(LDR);
  presence = !digitalRead(IRS);

  if (light < 400 && presence == LOW) {
    consumption = 10 * NODE_AMOUNT;
    strong_on = false;
    dim_on = true;
    
    digitalWrite(LED_STRONG, LOW);
    digitalWrite(LED_DIM, HIGH);
  }
  
  else if (light < 400 && presence == HIGH) {
    consumption = 20 * NODE_AMOUNT;
    strong_on = true;
    dim_on = false;
    
    digitalWrite(LED_DIM, LOW);
    digitalWrite(LED_STRONG, HIGH);
  }
  
  else {
    consumption = 0;
    strong_on = false;
    dim_on = false;
    
    digitalWrite(LED_STRONG, LOW);  
    digitalWrite(LED_DIM, LOW);
  }

  ArduinoCloud.update();
  delay(500);
}
