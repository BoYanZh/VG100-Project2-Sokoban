
#include <AFMotor.h>

AF_DCMotor motor1(1,MOTOR12_1KHZ);  //connect to M1
AF_DCMotor motor2(2,MOTOR12_1KHZ);  //connect to M2
AF_DCMotor motor3(3,MOTOR34_1KHZ);  //connect to M3
AF_DCMotor motor4(4,MOTOR34_1KHZ);  //connect to M4
int motor_speed = 230; 
int motor_delay = 400; 
int motorA =14;
int motorB =15;
int motorC=16;
int motorD=17;

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello");
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(motorC,OUTPUT);
  pinMode(motorD,OUTPUT);
  b_motor_stop();
  delay(2000);  
}


void loop()
{
  int  key;
  if(Serial.available() > 0) {    
    key = Serial.read();  
    if(key >= 30 && key <= 122) { 
      b_motor_com(key);  
    }
  }
}

void b_motor_stop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
}

void b_motor_com(int keyword){
  //forward
  if(keyword=='w')
  {
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
  //backward
  else if(keyword=='s'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
  //turn left
  else if(keyword=='a'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
  //turn right
  else if(keyword=='d'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
  //forward step
  else if(keyword=='W')
  {
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
    delay(motor_delay); 
    b_motor_stop();
  }
  //backward step
  else if(keyword=='S'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
    delay(motor_delay); 
    b_motor_stop();
  }
  //turn left step
  else if(keyword=='A'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
    delay(motor_delay); 
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
    b_motor_stop();
  }
  //turn right step
  else if(keyword=='D'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
    delay(motor_delay); 
    b_motor_stop();
  }
  //diaganalL
    else if(keyword=='q'){
    motor1.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor1.run(FORWARD);
    motor2.run(RELEASE);
    motor3.run(FORWARD);
    motor4.run(RELEASE);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
    else if(keyword=='e'){
    motor2.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor3.run(RELEASE);
    motor4.run(FORWARD);
          digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
    else if(keyword=='z'){
    motor1.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor2.run(BACKWARD);
    motor3.run(RELEASE);
    motor4.run(BACKWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
    else if(keyword=='c'){
    motor2.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor2.run(RELEASE);
    motor1.run(BACKWARD);
    motor4.run(RELEASE);
    motor3.run(BACKWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
  //turn round
    else if(keyword=='t'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
    else if(keyword=='r'){
    motor1.setSpeed(motor_speed);
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
  //CONCERNING
    else if(keyword=='f'){
    motor2.setSpeed(motor_speed);
    motor3.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor4.run(RELEASE);
    motor3.run(FORWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }
     else if(keyword=='g'){
    motor1.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor2.run(RELEASE);
    motor1.run(FORWARD);
    motor3.run(RELEASE);
    motor4.run(FORWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  } 
     else if(keyword=='b'){
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor4.run(FORWARD);
    motor2.run(RELEASE);
    motor3.run(BACKWARD);
      digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }   
      else if(keyword=='i'){
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor4.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  digitalWrite(motorA,HIGH);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }   
       else if(keyword=='k'){
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor4.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,HIGH);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  }   
       else if(keyword=='j'){
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor4.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,HIGH);
  digitalWrite(motorD,LOW);
  }  
       else if(keyword=='l'){
    motor3.setSpeed(motor_speed);
    motor4.setSpeed(motor_speed);
    motor1.run(RELEASE);
    motor4.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,HIGH);
  }    
  //Stop
  else if(keyword=='X'){
    b_motor_stop();
  }
  else{
    b_motor_stop();
  }
}


