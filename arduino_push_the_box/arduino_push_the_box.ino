#include <Servo.h>
#include <SoftwareSerial.h>

#define ROW 11
#define COL 11

#define OUT_PIN 4
#define IN4_PIN 5
#define IN3_PIN 6
#define TX_PIN 7
#define RX_PIN 8
#define IN2_PIN 10
#define IN1_PIN 11
#define V_SERVO_PIN 12
#define H_SERVO_PIN 13
#define S0_PIN A0
#define S1_PIN A1
#define S2_PIN A2
#define S3_PIN A3
#define MOTOR_SPEED 255

Servo vServo, hServo;
Servo SERVOS[] = {vServo, hServo};
SoftwareSerial BT(TX_PIN, RX_PIN);
const int N20_PIN_1[] = {IN1_PIN, IN3_PIN, IN2_PIN, IN4_PIN};
const int N20_PIN_2[] = {IN2_PIN, IN4_PIN, IN1_PIN, IN3_PIN};
const int SERVO_PRESS[] = {150, 150};
const int SERVO_RELEASE[] = {170, 170};
const int MOVE_TIME[] = {600, 600, 600, 600};
int pos = 0;
int red = 0, green = 0, blue = 0;

class Sokoban {
 public:
  int xBox[ROW - 1], yBox[COL - 1];
  int x0, y0;
  const char map[6][ROW][COL] = {
      {"##########", "#^  ######", "# @@######", "# @ ###$##", "### ###$##",
       "###    $##", "##   #  ##", "##   #####", "##########", "##########"},
      {"##########", "## ^######", "##@@######", "## $######", "#  $  ####",
       "# #$  ####", "# @  #####", "###  #####", "##########", "##########"},
      {"##########", "##   #####", "##$$@#####", "#  $  ####", "#  @@ ####",
       "####^ ####", "##########", "##########", "##########", "##########"},
      {"##########", "# $   ####", "# #@  ####", "# @$# ####", "##$@^ ####",
       "##  ######", "##  ######", "##########", "##########", "##########"},
      {"##########", "##   #####", "## #   ###", "#^@$ $ ###", "# @$# ####",
       "## @  ####", "##   #####", "##########", "##########", "##########"},
      {"##########", "##  ######", "# ^@  ####", "# $@  ####", "## @######",
       "##$ $ ####", "##    ####", "##########", "##########", "##########"}};
  char mapNow[ROW][COL], mapTgt[ROW][COL];
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, boxIndex, mapIndex;

  void chooseMap(int index) {
    mapIndex = index;
    boxIndex = 0;
    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
        mapNow[i][j] = map[mapIndex][i][j] != '$' ? map[mapIndex][i][j] : ' ';
        mapTgt[i][j] = map[mapIndex][i][j] == '$' ? '$' : ' ';
        if (map[mapIndex][i][j] == '@')
          xBox[boxIndex] = i, yBox[boxIndex++] = j;
        else if (map[mapIndex][i][j] == '^')
          x0 = i, y0 = j;
      }
    }
  }

  bool moveCar(char sr) {
    // return true;
    int dire = 0;
    if (sr == 'w')
      dire = 0;
    else if (sr == 'd')
      dire = 1;
    else if (sr == 's')
      dire = 2;
    else if (sr == 'a')
      dire = 3;
    if ((mapNow[x0 + dx[dire]][y0 + dy[dire]] == '@' &&
         mapNow[x0 + 2 * +dx[dire]][y0 + 2 * dy[dire]] == ' ') ||
        mapNow[x0 + dx[dire]][y0 + dy[dire]] == ' ') {
      for (int i = 0; i < boxIndex; i++)
        if (x0 + dx[dire] == xBox[i] && y0 + dy[dire] == yBox[i]) {
          xBox[i] += dx[dire], yBox[i] += dy[dire];
          mapNow[xBox[i]][yBox[i]] = '@';
          break;
        }
      mapNow[x0 + dx[dire]][y0 + dy[dire]] = '^';
      mapNow[x0][y0] = ' ';
      x0 += dx[dire], y0 += dy[dire];
      return 1;
    }
    return 0;
  }

  bool isWin() {
    int reachCount = 0;
    for (int i = 0; i < ROW; i++)
      for (int j = 0; j < COL; j++) {
        if (mapTgt[i][j] == '$' && mapNow[i][j] == '@' &&
            ++reachCount == boxIndex)
          return true;
      }
    return false;
  }
};

void motorMove(char sr) {
  // int dire = 0;
  int pin1, pin2;
  bool isBlack;
  if (sr == 'w') {
    pin1 = IN1_PIN;
    pin2 = IN2_PIN;
    vServo.write(SERVO_PRESS[0]);
  } else if (sr == 'd') {
    pin1 = IN3_PIN;
    pin2 = IN4_PIN;
    hServo.write(SERVO_PRESS[1]);
  } else if (sr == 's') {
    pin1 = IN2_PIN;
    pin2 = IN1_PIN;
    vServo.write(SERVO_PRESS[0]);
  } else if (sr == 'a') {
    pin1 = IN4_PIN;
    pin2 = IN3_PIN;
    hServo.write(SERVO_PRESS[1]);
  }
  Serial.print(sr);
  Serial.print(" ");
  Serial.print(pin1);
  Serial.print(" ");
  Serial.println(pin2);
  analogWrite(pin1, MOTOR_SPEED );
  analogWrite(pin2, 0);
  while(detectBlack()){
    delay(20);
  }
  delay(500);
  while (1) {
    isBlack = detectBlack();
    Serial.print("isBlack:");
    Serial.println(isBlack);
    if (isBlack){
      Serial.println(isBlack);
      break;
    }
    if (sr == 'w') {
      vServo.write(SERVO_PRESS[0]);
    } else if (sr == 'd') {
      hServo.write(SERVO_PRESS[1]);
    } else if (sr == 's') {
      vServo.write(SERVO_PRESS[0]);
    } else if (sr == 'a') {
      hServo.write(SERVO_PRESS[1]);
    }
  }
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  if (sr == 'w') {
    vServo.write(SERVO_RELEASE[0]);
  } else if (sr == 'd') {
    hServo.write(SERVO_RELEASE[1]);
  } else if (sr == 's') {
    vServo.write(SERVO_RELEASE[0]);
  } else if (sr == 'a') {
    hServo.write(SERVO_RELEASE[1]);
  }
  /*Serial.println(dire);
  speedUp(dire);
  holdServo(dire);
  speedDown(dire);*/
}

void getColor() {
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, LOW);
  red = pulseIn(OUT_PIN, digitalRead(OUT_PIN) == HIGH ? LOW : HIGH);
  digitalWrite(S3_PIN, HIGH);
  blue = pulseIn(OUT_PIN, digitalRead(OUT_PIN) == HIGH ? LOW : HIGH);
  digitalWrite(S2_PIN, HIGH);
  green = pulseIn(OUT_PIN, digitalRead(OUT_PIN) == HIGH ? LOW : HIGH);
}

bool detectBlack() {
  getColor();
  /*Serial.print("R:");
  Serial.print(red, DEC);
  Serial.print(" G: ");
  Serial.print(green, DEC);
  Serial.print(" B: ");
  Serial.print(blue, DEC);
  Serial.println();*/
  if (red >= 6 && green >= 6 && blue >= 6) {
    return true;
  } else {
    return false;
  }
}

void setup() {
  initPin();
  bluetoothTask();
}

void initPin() {
  Serial.begin(9600);
  BT.begin(9600);
  vServo.attach(V_SERVO_PIN);
  hServo.attach(H_SERVO_PIN);
  vServo.write(SERVO_RELEASE[0]);
  hServo.write(SERVO_RELEASE[1]);
  for (int i = 0; i < 4; i++) {
    pinMode(N20_PIN_1[i], OUTPUT);
  }
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);
  pinMode(OUT_PIN, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, HIGH);
  Serial.println("BT is ready!");
}

void bluetoothTask() {
  Sokoban mySokoban;
  int val;
  while (1) {
    val = readInput();
    Serial.print("input:");
    Serial.println(val);
    if ((int)val <= 57) {
      Serial.print("Choose Map:");
      Serial.println((int)val - 48);
      mySokoban.chooseMap((int)val - 48);
    } else {
      Serial.print("Move Car:");
      Serial.println((char)val);
      bool shouldMove = mySokoban.moveCar(val);
      Serial.print("Should Move:");
      Serial.println(shouldMove);
      // if (shouldMove) {
      if (true) {
        motorMove(val);
        Serial.print("Is Win:");
        Serial.println(mySokoban.isWin());
      }
    }
    // BT.print("hhh");
  }
}
char readInput() {
  while (1) {
    if (BT.available()) {
      return BT.read();
    }
    /*getColor();
    Serial.print("R:");
    Serial.print(red, DEC);
    Serial.print(" G: ");
    Serial.print(green, DEC);
    Serial.print(" B: ");
    Serial.print(blue, DEC);
    Serial.println();*/
    delay(100);
  }
}
int readInput1() {
  int val;
  while (1) {
    val = Serial.read();
    if (val != -1 && val != 10) {
      return val;
    }
  }
}
