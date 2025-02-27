int ledPin = 3;
int sensorPin = 5;
bool ledState = false;        
bool lastSensorState = LOW;   

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  digitalWrite(ledPin, ledState);  
}

void updateLED() {
  digitalWrite(ledPin, ledState);  
}

void loop() {
  // control logic 
  bool currentSensorState = digitalRead(sensorPin);

  if (currentSensorState == HIGH && lastSensorState == LOW) {
    ledState = !ledState;     
    updateLED();               
    Serial.print("Toggled LED to: ");
    Serial.println(ledState);
    delay(50); 
  }

  lastSensorState = currentSensorState;  
}