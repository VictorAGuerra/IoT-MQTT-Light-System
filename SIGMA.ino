#define LDR 15
#define LED_STRONG 23
#define LED_DIM 21
#define IRS 22

int light;
int presence;

void setup() {
  Serial.begin(9600);
  pinMode(LED_STRONG, OUTPUT);
  pinMode(LED_DIM, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(IRS, INPUT);
}

void loop() {
  light = analogRead(LDR);
  presence = !(digitalRead(IRS));
  
  Serial.println(light);
  Serial.println(presence);
  
  if (light < 400 && presence == LOW) {
    digitalWrite(LED_STRONG, LOW);
    digitalWrite(LED_DIM, HIGH);
  }

  else if (light < 400 && presence == HIGH) {
    digitalWrite(LED_DIM, LOW);
    digitalWrite(LED_STRONG, HIGH);
  }

  else{
    digitalWrite(LED_STRONG, LOW);
    digitalWrite(LED_DIM, LOW);
  }
  
  delay(100);
}
