#include <cstdlib>
#include <iostream>
#include <Windows.h>

#define ROW 11
#define COL 11

int xBox[10], yBox[10];
int x0, y0;
char map[6][ROW][COL] =
    {{"##########", "#^  ######", "# @@######", "# @ ###$##", "### ###$##",
      "###    $##", "###     ##", "##   #  ##", "##   #####", "##########"},
     {"##########", "## ^######", "##@@######", "## $######", "#  $  ####",
      "# #$  ####", "# @  #####", "###  #####", "##########", "##########"},
     {"##########", "##   #####", "##$$@#####", "#  $  ####", "#  @@ ####",
      "####^ ####", "##########", "##########", "##########", "##########"},
     {"##########", "# $   ####", "# #@  ####", "# @$# ####", "##$@^ ####",
      "##  ######", "##  ######", "##########", "##########", "##########"},
     {"##########", "##   #####", "## #   ###", "#^@$ $ ###", "# @$# ####",
      "## @  ####", "##   #####", "##########", "##########", "##########"},
     {"##########", "##  ######", "# ^@  ####", "# $@  ####", "## @######",
      "##$ $ ####", "##    ####", "##########", "##########", "##########"}},
     mapNow[ROW][COL], mapTgt[ROW][COL], sr;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, boxIndex = 0, mapIndex;

int main(void) {
  while (1) {
    printf("choose the map(0~5):");
    scanf("%d", &mapIndex);
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
    while (1) {
      printf(
          "UI: #:Wall  @:Box  $:Target  ^:Man\n"
          "Input: w/a/s/d:Movement r:Restart q:Quit\n");
      int reachCount = 0, dire = 0;
      for (int i = 0; i < ROW; i++, printf("\n"))
        for (int j = 0; j < COL; j++, printf(" ")) {
          printf("%c", mapNow[i][j] != ' ' ? mapNow[i][j] : mapTgt[i][j]);
          if (mapTgt[i][j] == '$' && mapNow[i][j] == '@') reachCount++;
        }
      if (reachCount == boxIndex) break;
      scanf("%c", &sr), fflush(stdin), system("cls");
      if (sr == 'w')
        dire = 0;
      else if (sr == 'd')
        dire = 1;
      else if (sr == 's')
        dire = 2;
      else if (sr == 'a')
        dire = 3;
      else if (sr == 'r') {
        boxIndex = 0;
        for (int i = 0; i < ROW; i++) {
          for (int j = 0; j < COL; j++) {
            mapNow[i][j] =
                map[mapIndex][i][j] != '$' ? map[mapIndex][i][j] : ' ';
            mapTgt[i][j] = map[mapIndex][i][j] == '$' ? '$' : ' ';
            if (map[mapIndex][i][j] == '@')
              xBox[boxIndex] = i, yBox[boxIndex++] = j;
            else if (map[mapIndex][i][j] == '^')
              x0 = i, y0 = j;
          }
        }
        continue;
      } else if (sr == 'q')
        break;
      else
        continue;
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
      }
    }
  }
  return 0;
}

void connectBluetooth()
{
	HANDLE hCom = CreateFile("\\\\.\\COM9", GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, 0, NULL); //与HC-06建立无线连接
	if (hCom == INVALID_HANDLE_VALUE) {
		std::cout << "Port unavailable!" << std::endl;
		return 0;
	}
//以下配置串口通信参数
	DCB dcb;
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 9600;
	dcb.ByteSize = DATABITS_8;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	BOOL br = SetCommState(hCom,&dcb);
	COMMTIMEOUTS cto ={MAXDWORD, MAXDWORD, MAXDWORD, MAXDWORD, MAXDWORD};
	br = SetCommTimeouts(hCom, &cto);
//开始等待用户输入
	for (; ; ) {
		int nInput = 0;
		std::cin >> nInput;
		if (nInput > 255 || nInput < 0) {
			break; //如果输入的值大于255或小于0则直接退出程序
		}
		BYTE byVal = (BYTE)nInput;
		DWORD dwTransmitted;
//将输入的值发送给HC-06
		WriteFile(hCom, &byVal, sizeof(byVal), &dwTransmitted, NULL);
	}
	CloseHandle(hCom);
}
