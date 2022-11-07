// Pins for directing power to the motor
const int motor1 = 3; 
const int motor2 = 5;

// Pins for steering with the motors
const int motor1Pin1 = 8;  
const int motor1Pin2 = 9;
const int motor2Pin1 = 10;
const int motor2Pin2 = 11;

// Keeping track of time
unsigned long currentMillis;  // what time is it now
unsigned long startMillis;    // time when we started
const int motorForwardinterval = 3000; // how long it should drive forward


void setup() {
  // put your setup code here, to run once:
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  startMillis = millis();
}

// Time is spent on one side and one corner of the square
void loop() {
  // Recording current time
  currentMillis = millis();
  run_straight();

  // Checking if we spent the required interval to go forward
  if(currentMillis - startMillis >= motorForwardinterval){
    turn_right();
    startMillis = currentMillis; // reseting start time
  }

  //delay(1000);
}

// Both motors forward
void run_straight(){
 drive(HIGH, HIGH, LOW, LOW);
}

// Only one motor forward
void turn_right(){
  drive(LOW, HIGH, LOW, LOW);
}

// Function to play around with how the motors should work
void drive(int state1,int state2,int state3,int state4) {
  analogWrite(motor1, 10); // Low speed to limit sharp turns
  analogWrite(motor2, 5);

  digitalWrite(motor1Pin1, state1);
  digitalWrite(motor2Pin1, state2);

  digitalWrite(motor1Pin2, state3);
  digitalWrite(motor2Pin2, state4);
  

  delay(1000);  
}