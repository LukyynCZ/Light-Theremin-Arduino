// Decleare variables
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // Set the max sensor value
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    // Set the min sensor value
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  // Turn the LED off - calibration is finished
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);
  // Map the sensor values to a wide range of pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  // Play the tone for 20 ms on pin 8
  tone(8, pitch, 20);  
  // Wait for 10ms
  delay(10);
}
