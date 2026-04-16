// --- Pin Definitions ---
const int greenLedPin = 8;
const int redLedPin = 9;
const int yellowLedPin = 10;
const int cameraFlashPin = 11; 
const int trigPin = 2;
const int echoPin = 3;
const int powerPin = 5;        

// --- System Configurations ---
const int thresholdDistance = 28;        
const unsigned long greenLightTime = 2000; 
const unsigned long yellowLightTime = 2000;
const unsigned long redLightTime = 5000;  

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(cameraFlashPin, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initial State Setup
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(cameraFlashPin, LOW);
  digitalWrite(powerPin, HIGH); 
  
  Serial.begin(9600);
}

void loop() {
 
  digitalWrite(greenLedPin, HIGH);
  delay(greenLightTime); 
  digitalWrite(greenLedPin, LOW);

  
  digitalWrite(yellowLedPin, HIGH);
  delay(yellowLightTime);
  digitalWrite(yellowLedPin, LOW);

  
  digitalWrite(redLedPin, HIGH);
  
  
  unsigned long redStartTime = millis();
  
  
  while (millis() - redStartTime < redLightTime) {
    
    int distance = getDistance();
    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

      if (distance > 0 && distance < thresholdDistance) {
      Serial.println("captureSignal");
      Serial.println(distance);
      
      // Flash the camera LED
      digitalWrite(cameraFlashPin, HIGH);
      delay(100);
      digitalWrite(cameraFlashPin, LOW);
    } else {
      
      delay(100); 
    }
  }
  
 
  digitalWrite(redLedPin, LOW);
}



int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int calculatedDistance = duration * 0.034 / 2;
  
  return calculatedDistance;
}