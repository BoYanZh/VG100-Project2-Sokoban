#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8);
#define ROW 11
#define COL 11
char val;

void motorMove(char sr) {
  int dire = 0;
  if (sr == 'w')
    dire = 0;
  else if (sr == 'd')
    dire = 1;
  else if (sr == 's')
    dire = 2;
  else if (sr == 'a')
    dire = 3;
}

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

void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");
  BT.begin(9600);
  Sokoban mySokoban;
  while (1) {
    if (BT.available()) {
      val = BT.read();
      if ((int)val <= 53) {
        Serial.print("Choose Map:");
        Serial.println(val);
        mySokoban.chooseMap((int)val - 48);
      } else {
        Serial.print("Move Car:");
        Serial.println(val);
        bool shouldMove = mySokoban.moveCar(val);
        Serial.println(shouldMove);
        if (shouldMove) {
          motorMove(val);
        }
        Serial.println(mySokoban.isWin());
      }
      BT.print("hhh");
    }
  }
}
