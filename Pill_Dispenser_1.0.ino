// Set digital pins for DC motor 
const int enable = 5; // Motor speed 
const int dirA = 3; // Direction A (Clockwise)
const int dirB = 4; // Direction B (Counterclockwise)

// Set digital pins for ultrasonic sensor 
const int trigPin = 9;
const int echoPin = 10;

// Initialize global variables 
long duration; 
int distance; 

void setup() {
  // Set pin direction for: 

  // DC motor
  pinMode(enable,OUTPUT);
  pinMode(dirA,OUTPUT);
  pinMode(dirB,OUTPUT);

  // Ultrasonic sensor
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop() {

  // Sends a short pulse to trig pin 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH (active) state for 10ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Returns sound wave travel time in ms 
  duration = pulseIn(echoPin, HIGH);

  // Calculates distance in cm 
  distance = (duration * 0.034) / 2;

  // Prints the distance on the serial monitor and skips line
  Serial.print("Distance: ");
  Serial.println(distance);

  // If the distance is less than 7 (when hand approaches the sensor)
  if(distance < 7){

    // Set power to 255 (full)
    analogWrite(enable, 255);

    // Set the motor to move counterclockwise to deliver the pill
    digitalWrite(dirA,LOW); 
    digitalWrite(dirB,HIGH);
    delay(500); // Run the process for 500ms 


  } else { // If distance is more than 7 (when hand withdraws from sensor)

    // Set power to 255 and revert gear movement to clockwise motion 
    analogWrite(enable, 255);
    digitalWrite(dirA,HIGH);
    digitalWrite(dirB,LOW);
    delay(200); // Run the process for 200ms 
  }
}
   
