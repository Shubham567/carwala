#include <AFMotor.h> // Install Adafruit motor shield version 1 library in arduino ide

#define LEFT_PORT 1
#define RIGHT_PORT 2


const short unsigned int LEFT_FORWARD = BACKWARD;
const short unsigned int RIGHT_FORWARD = BACKWARD;

const short unsigned int LEFT_BACKWARD = FORWARD;
const short unsigned int RIGHT_BACKWARD = FORWARD;


AF_DCMotor motorLeft(LEFT_PORT);
AF_DCMotor motorRight(RIGHT_PORT);


void stopBoth(){
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void leftTurn(){
  motorLeft.run(RELEASE);
  motorRight.run(RIGHT_FORWARD);
}

void rightTurn(){
  motorLeft.run(LEFT_FORWARD);
  motorRight.run(RELEASE);
}

void moveBackward(){
  motorLeft.run(LEFT_BACKWARD);
  motorRight.run(RIGHT_BACKWARD);
}

void moveForward(){
  motorLeft.run(LEFT_FORWARD);
  motorRight.run(RIGHT_FORWARD);
}

void setup() {
  // put your setup code here, to run once:

  motorLeft.setSpeed(255);
  motorRight.setSpeed(255);

  Serial.begin(9600);


}

char s = 'z';

void loop() {
  // put your main code here, to run repeatedly:

  s = Serial.read();

//  Serial.println("Hello World");

  if(s == 'w'){
    moveForward();
  }
  else if(s == 'a'){
    leftTurn();
  }
  else if(s == 'd'){
    rightTurn();
  }
  else if(s == 's'){
    moveBackward();
  }
  else if(s == 'z'){
    stopBoth();
  }
//  else{
//    stopBoth();
//    s = 'e';
//  }

}
