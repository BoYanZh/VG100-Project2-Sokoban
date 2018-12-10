#include <Servo.h>
#include <SoftwareSerial.h>
#define A_SERVO_PIN 4

#define A_Motor_Input1 9 //OUT 4
#define A_Motor_Input2 10 //OUT 3

#define UP 1
#define DOWN 2
//Debug for Servo Motor
#define SERVO_VALUE_INIT 20
#define SERVO_VALUE_MAX 34
#define SERVO_VALUE_MIN 20 // A worked value version: init=20, max=37, min=20. -- DEC.10, 22:04, MK

#define A_MOTOR_SPEED 120

Servo AServo;
int ans=0;
void moveServo(int direction) {
  int pos;
  if (direction == UP) {
    for (pos = SERVO_VALUE_MIN; pos < SERVO_VALUE_MAX; pos += 1) {
      AServo.write(pos);
      //RightServo.write(pos);
      delay(15);
    }
  } else if (direction == DOWN) {
    for (pos = SERVO_VALUE_MAX; pos >= SERVO_VALUE_MIN; pos -= 1) {
      AServo.write(pos);
      //RightServo.write(pos);
      delay(15);
    }
  }
  Serial.println("barrier moves");
}
void setup() {
  // put your setup code here, to run once:
  AServo.attach(A_SERVO_PIN);
  AServo.write(SERVO_VALUE_INIT);
  delay(5000);
  pinMode(A_Motor_Input1, OUTPUT);
  pinMode(A_Motor_Input2, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  moveServo(UP);
  delay(1000);
  
  digitalWrite(A_Motor_Input1, HIGH);//analogWrite(A_Motor_Input1, A_MOTOR_SPEED);//
  digitalWrite(A_Motor_Input2, LOW);//analogWrite(A_Motor_Input2, 0);//
  delay(150);
  ans++;
  Serial.println("move1");
  Serial.println(ans);
  digitalWrite(A_Motor_Input1, LOW);//analogWrite(A_Motor_Input1, 0);//
  digitalWrite(A_Motor_Input2, LOW);//analogWrite(A_Motor_Input2, 0);//  cannot be replaced by analogWrite. Why? Did I miss something?
  delay(100);
  ans++;
  Serial.println("move2");
  Serial.println(ans);

  moveServo(DOWN);
  delay(200);
  AServo.write(SERVO_VALUE_INIT);
  delay(1000);
/*  
  moveServo(UP);
  delay(1000);
  moveServo(DOWN);
  delay(1000);
  delay(1000);
*/

}
