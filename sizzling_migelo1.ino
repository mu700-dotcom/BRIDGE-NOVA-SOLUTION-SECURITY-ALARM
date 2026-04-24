// Pin definitions
int buzzer = 6;
int led1 = 2;
int led2 = 3;
int ldr = A0;

int lightValue = 0;
int threshold = 500; // adjust this based on your environment

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  Serial.begin(9600); // for monitoring light values
}

void loop() {
  lightValue = analogRead(ldr); // read light sensor

  Serial.println(lightValue); // see values in Serial Monitor

  if (lightValue < threshold) {
    // DARK condition
    digitalWrite(led1, HIGH);   // LED1 ON
    digitalWrite(led2, LOW);    // LED2 OFF
    digitalWrite(buzzer, HIGH); // Buzzer ON
  } 
  else {
    // BRIGHT condition
    digitalWrite(led1, LOW);    // LED1 OFF
    digitalWrite(led2, HIGH);   // LED2 ON
    digitalWrite(buzzer, LOW);  // Buzzer OFF
  }

  delay(200);
}
