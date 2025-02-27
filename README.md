# LED Toggle with Sensor

This Arduino sketch toggles an LED when a sensor input changes from LOW to HIGH. The LED state is updated only on a rising edge of the sensor signal.

## Components Required
- Arduino board
- LED
- Resistor (220Ω)
- Sensor (e.g., push button or IR sensor)
- Jumper wires

## Circuit Diagram
- Connect the LED to **pin 3** with a **220Ω resistor** in series to **GND**.
- Connect the sensor to **pin 5** with one terminal to **GND** and the other to **5V** (or use a pull-down resistor if needed).

## Code Explanation
- The LED is controlled using `ledPin` (pin 3).
- The sensor input is read from `sensorPin` (pin 5).
- When the sensor detects a HIGH state after being LOW, the LED toggles.
- The LED state is printed to the Serial Monitor.

## Installation
1. Copy the code into the Arduino IDE.
2. Connect your Arduino board to your computer.
3. Upload the sketch to your Arduino.

## Code
```cpp
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
```

## Usage
- Open the Serial Monitor (`9600 baud`) to view the LED status updates.
- Trigger the sensor to toggle the LED on and off.

## License
This project is open-source under the MIT License.

