#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#include "renJu.h"
//4.16.~ omg
//5.3.睡攪

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13

typedef struct PointArr {
	int x;
	int y;
}pointArr;

void gotoXY_g(int x, int y);
void gotoXY(int* x, int* y, int gameMod);

void drawMenu();
void drawBoard();
void resetSetting(int* gridX, int* gridY, int* gameMod, int* turn);
void setGameSetting(int* gridX, int* gridY, int* gameMod);
void EXITGAME();

void putRock(int gridX, int gridY, int* turn);
int checkRes(int gridX, int gridY);
void printRes(int res);

void putRockAI(int gridX, int gridY);
void playAI(int gridX, int gridY);

int board[15][15] = { 0 };
int weightBoardBlack[15][15] = { 0 };
int weightBoardWhite[15][15] = { 0 };

int main()
{
	int gridX = 0, gridY = 2, gameMod = 0;

	int kb = 0, turn = 1;

	resetSetting(&gridX, &gridY, &gameMod, &turn);

	while (1) {
		if (_kbhit()) {
			kb = _getch();
			if (kb == 224)
			{
				kb = _getch();
				switch (kb) {
				case UP:
					gridY -= 1;
					gotoXY(&gridX, &gridY, gameMod);
					break;
				case DOWN:
					gridY += 1;
					gotoXY(&gridX, &gridY, gameMod);
					break;
				case LEFT:
					gridX -= 3;
					gotoXY(&gridX, &gridY, gameMod);
					break;
				case RIGHT:
					gridX += 3;
					gotoXY(&gridX, &gridY, gameMod);
					break;
				}
			}
			else if (kb == SPACE) {
				if (gameMod == 0 && (gridY == 2 || gridY == 4)) {

					if (gridY == 2)
						gameMod = 1;
					else
						gameMod = 2;

					setGameSetting(&gridX, &gridY, &gameMod);
					drawBoard();
					gotoXY(&gridX, &gridY, gameMod);
				}
				else if (gameMod == 1) {
					if (board[gridY][gridX / 3] == 3 || board[gridY][gridX / 3] == 2) { continue; }

					putRockAI(gridX, gridY, &turn);

					if (243 == checkRes(gridX, gridY) || 32 == checkRes(gridX, gridY)) {
						resetSetting(&gridX, &gridY, &gameMod, &turn);
					}
				}
				else if (gameMod == 2) {
					if (board[gridY][gridX / 3] != 0) { continue; }

					putRock(gridX, gridY, &turn);

					if (243 == checkRes(gridX, gridY) || 32 == checkRes(gridX, gridY)) {
						resetSetting(&gridX, &gridY, &gameMod, &turn);
					}
				}
				else if (gridY == 6) {
					EXITGAME();
					return 0;
				}
			}
		}
	}
}

void gotoXY_g(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void gotoXY(int* x, int* y, int gameMod)
{
	if (gameMod == 0 && (*y <= 0 || *y >= 8))
	{
		if (*y <= 0) { (*y) += 2; }
		else { (*y) -= 2; }

	}
	else if (gameMod == 0 && *x != 0) { *x = 0; }
	else if (gameMod == 1 || gameMod == 2)
	{
		if (*x <= 0) { *x = 0; }
		else if (*x >= 45) { *x -= 3; }
		else if (*y < 0) { (*y) += 1; }
		else if (*y > 14) { *y -= 1; }
	}

	COORD Pos;
	Pos.X = *x;
	Pos.Y = *y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void drawMenu()
{
	printf("1. 1P Player\n\n");
	printf("2. 2P Player\n\n");
	printf("3. EXIT");
}

void drawBoard()
{
	int a, b;

	for (a = 0; a < 15; a++) {
		for (b = 0; b < 43; b++) {
			if (a == 0) {
				if (b == 0) { printf("旨"); }
				else if (b == 42) { printf("旬"); }
				else if (b % 3 != 0) { printf("收"); }
				else if (b % 3 == 0) { printf("有"); }
				continue;
			}
			if (b == 0) {
				if (a == 14) { printf("曲"); }
				else if (a % 2 == 1) { printf("早"); }
				else if (a % 2 == 0) { printf("曳"); }
				continue;
			}
			if (b == 42) {
				if (a == 14) { printf("旭"); }
				else if (a % 2 == 1) { printf("早"); }
				else if (a % 2 == 0) { printf("朽"); }
				continue;
			}
			if (a == 14) {
				if (b % 3 != 0) { printf("收"); }
				else if (b % 3 == 0) { printf("朴"); }
				continue;
			}
			if (b % 3 == 0) {
				printf("朱");
				continue;
			}
			else if (b % 3 != 0) {
				printf("收");
				continue;
			}
		}
		printf("\n");
	}
}
void resetSetting(int* gridX, int* gridY, int* gameMod, int* turn)
{
	*gridX = 0;
	*gridY = 2;
	*gameMod = 0;
	*turn = 1;

	for (int a = 0; a < 15; a++) {
		for (int b = 0; b < 15; b++) {
			board[a][b] = 0;
		}
	}

	system("cls");
	gotoXY(gridX, gridY, gameMod);
	drawMenu();
	gotoXY(gridX, gridY, gameMod);
}
void setGameSetting(int* gridX, int* gridY, int* gameMod)
{
	system("cls");

	if (*gridY == 4)
		*gameMod = 2;
	else
		*gameMod = 1;

	*gridX = 21;
	*gridY = 7;
}
void EXITGAME()
{
	system("cls");
	printf("BYE");
	for (int i = 0; i < 3; i++) {
		printf(".");
		Sleep(1000);
	}
	system("cls");
}

void putRock(int gridX, int gridY, int* turn)
{
	if (*turn == 1) {
		if (checkSam(gridX, gridY) >= 2 || checkJang(gridX, gridY) == 1 || checkSa(gridX, gridY) >= 2) {
			alretKim(&gridX, &gridY, 1);
			return;
		}
		printf("∞");
		board[gridY][gridX / 3] = 3;

		(*turn)++;
	}
	else {
		printf("≒");
		board[gridY][gridX / 3] = 2;

		(*turn)--;
	}
}
int checkRes(int gridX, int gridY)
{
	int res = 1;

	if (243 == board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] * board[gridY][gridX / 3 + 4] ||
		243 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] ||
		243 == board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] ||
		243 == board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] ||
		243 == board[gridY][gridX / 3 - 4] * board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] ||

		243 == board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] * board[gridY + 4][gridX / 3] ||
		243 == board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] ||
		243 == board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] ||
		243 == board[gridY - 3][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] ||
		243 == board[gridY - 4][gridX / 3] * board[gridY - 3][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] ||

		243 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] * board[gridY - 4][gridX / 3 + 4] ||
		243 == board[gridY + 1][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] ||
		243 == board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] ||
		243 == board[gridY + 3][gridX / 3 - 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] ||
		243 == board[gridY + 4][gridX / 3 - 4] * board[gridY + 3][gridX / 3 - 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3 - 1] ||

		243 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] * board[gridY - 4][gridX / 3 - 4] ||
		243 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] * board[gridY + 1][gridX / 3 + 1] ||
		243 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 1][gridX / 3 + 1] ||
		243 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 1][gridX / 3 + 1] ||
		243 == board[gridY][gridX / 3] * board[gridY + 4][gridX / 3 + 4] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 1][gridX / 3 + 1]) {

		printRes(243);
		return 243;
	}
	else if (32 == board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] * board[gridY][gridX / 3 + 4] ||
		32 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] ||
		32 == board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] ||
		32 == board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY][gridX / 3 + 1] ||
		32 == board[gridY][gridX / 3 - 4] * board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3] ||

		32 == board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] * board[gridY + 4][gridX / 3] ||
		32 == board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] ||
		32 == board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] ||
		32 == board[gridY - 3][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3] ||
		32 == board[gridY - 4][gridX / 3] * board[gridY - 3][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY][gridX / 3] ||

		32 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] * board[gridY - 4][gridX / 3 + 4] ||
		32 == board[gridY + 1][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] ||
		32 == board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] ||
		32 == board[gridY + 3][gridX / 3 - 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 - 1] * board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 + 1] ||
		32 == board[gridY + 4][gridX / 3 - 4] * board[gridY + 3][gridX / 3 - 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY][gridX / 3] * board[gridY + 1][gridX / 3 - 1] ||

		32 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] * board[gridY - 4][gridX / 3 - 4] ||
		32 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] * board[gridY + 1][gridX / 3 + 1] ||
		32 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 1][gridX / 3 + 1] ||
		32 == board[gridY][gridX / 3] * board[gridY - 1][gridX / 3 - 1] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 1][gridX / 3 + 1] ||
		32 == board[gridY][gridX / 3] * board[gridY + 4][gridX / 3 + 4] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 1][gridX / 3 + 1]) {

		printRes(32);
		return 32;
	}
	return 0;
}
void printRes(int res)
{
	gotoXY_g(50, 8);
	if (res == 243)
		printf("Black Win!!\n");
	else
		printf("White Win!!\n");

	Sleep(1000);
}

void putRockAI(int gridX, int gridY)
{
	if (checkSam(gridX, gridY) >= 2 || checkJang(gridX, gridY) == 1 || checkSa(gridX, gridY) >= 2) {
		alretKim(&gridX, &gridY, 1);
		return;
	}
	printf("∞");
	board[gridY][gridX / 3] = 3;
	weightBoardBlack[gridY][gridX / 3] = 3;


	playAI(gridX, gridY);
}
void playAI(int gridX, int gridY)
{
	int i = 0, x = 0, y = 0;
	int min = 9, minCount = 0;
	int stack = 1;

	/*for (y = -1; y < 2; y++) {
		for (x = -1; x < 2; x++) {
			if (y == 0 && x == 0 || weightBoardBlack[gridY + y][gridX / 3 + x] == 3 || weightBoardBlack[gridY + y][gridX / 3 + x] == 2)
				continue;
			weightBoardBlack[gridY + y][gridX / 3 + x] -= 1;
		}
	}*/

	gotoXY_g(45, 20);
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++)
			printf("%4d", board[y][x]);
		printf("\n");
		gotoXY_g(45, 21 + y);
	}
	gotoXY_g(110, 3);
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++)
			printf("%4d", weightBoardBlack[y][x]);
		printf("\n");
		gotoXY_g(110, 4 + y);
	}
	gotoXY_g(110, 20);
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++)
			printf("%4d", weightBoardWhite[y][x]);
		printf("\n");
		gotoXY_g(110, 21 + y);
	}

	//Sleep(100000);
	for (y = 0; y < 15; y++) {
		for (x = 0; x < 15; x++) {

			if (board[y][x] == 3) {
				while (board[y - stack][x - stack] == 3) { stack++; }	//Ｊ
				weightBoardBlack[y - stack][x - stack] = -stack;
				stack = 1;

				while (board[y - stack][x] == 3) { stack++; }			//∟
				weightBoardBlack[y - stack][x] = -stack;
				stack = 1;

				while (board[y - stack][x + stack] == 3) { stack++; }	//Ｈ
				weightBoardBlack[y - stack][x + stack] = -stack;
				stack = 1;

				while (board[y][x + stack] == 3) { stack++; }			//⊥
				if (weightBoardBlack[y][x + stack] > -stack)
					weightBoardBlack[y][x + stack] = -stack;
				stack = 1;

				while (board[y + stack][x + stack] == 3) {				//Ｋ
					stack++;
				}
				if (weightBoardBlack[y + stack][x + stack] > -stack)
					weightBoardBlack[y + stack][x + stack] = -stack;
				stack = 1;

				while (board[y + stack][x] == 3) { stack++; }			//⊿
				if (weightBoardBlack[y + stack][x] > -stack)
					weightBoardBlack[y + stack][x] = -stack;
				stack = 1;

				while (board[y + stack][x - stack] == 3) { stack++; }	//Ｉ
				if (weightBoardBlack[y + stack][x - stack] > -stack)
					weightBoardBlack[y + stack][x - stack] = -stack;
				stack = 1;

				while (board[y][x - stack] == 3) { stack++; }			//∠
				weightBoardBlack[y][x - stack] = -stack;
				stack = 1;
			}
		}
	}

	gotoXY_g(45, 20);
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++)
			printf("%4d", board[y][x]);
		printf("\n");
		gotoXY_g(45, 21 + y);
	}
	gotoXY_g(110, 3);
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++)
			printf("%4d", weightBoardBlack[y][x]);
		printf("\n");
		gotoXY_g(110, 4 + y);
	}
	gotoXY_g(110, 20);
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 15; x++)
			printf("%4d", weightBoardWhite[y][x]);
		printf("\n");
		gotoXY_g(110, 21 + y);
	}

	for (y = 0; y < 15; y++) {								//minFind&Count
		for (x = 0; x < 15; x++) {
			if (weightBoardBlack[y][x] < min) {
				min = weightBoardBlack[y][x];
				minCount = 1;
			}
			else if (weightBoardBlack[y][x] == min) {
				minCount++;
			}
		}
	}





}