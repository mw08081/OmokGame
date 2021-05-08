#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#include "renJu.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13

void gotoXY_g(int x, int y);
void gotoXY(int * x, int * y, int gameMod);

void drawMenu();
void drawBoard();
void resetSetting(int board[][15], int * grid_x, int * grid_y, int * gameMod, int * turn);
void setGameSetting(int* grid_x, int* grid_y, int* gameMod);
void EXITGAME();

void putRock(int board[][15], int grid_x, int grid_y, int * turn);
int checkRes(int board[][15], int grid_x, int grid_y);
void printRes(int res);

int main()
{
	int grid_x = 0, grid_y = 2, gameMod = 0;

	int kb = 0, turn = 1;
	int board[15][15] = { 0 };

	resetSetting(board, &grid_x, &grid_y, &gameMod, &turn);
	
	while (1) {
		if (_kbhit()) { 
			kb = _getch();
			if (kb == 224)
			{
				kb = _getch();
				switch(kb) {
				case UP :
					grid_y -= 1;
					gotoXY(&grid_x, &grid_y,gameMod);
					break;
				case DOWN:
					grid_y += 1;
					gotoXY(&grid_x, &grid_y, gameMod);
					break;
				case LEFT:
					grid_x -= 3;
					gotoXY(&grid_x, &grid_y, gameMod);
					break;
				case RIGHT:
					grid_x += 3;
					gotoXY(&grid_x, &grid_y, gameMod);
					break;
				}
			}
			else if(kb == SPACE) {
				if (gameMod == 0 && grid_y == 2) {
					gameMod = 1;
				}
				else if (gameMod == 0 && grid_y == 4) {
					gameMod = 1;

					setGameSetting(&grid_x, &grid_y, &gameMod);
					drawBoard();
					gotoXY(&grid_x, &grid_y, gameMod);
				}
				else if (gameMod == 1) 
				{
					if (board[grid_y][grid_x / 3] != 0) { continue; }

					putRock(board, grid_x, grid_y, &turn);
					
					if (1 == checkRes(board, grid_x, grid_y) || 32 == checkRes(board, grid_x, grid_y)) {	
						resetSetting(board, &grid_x, &grid_y, &gameMod, &turn);
					}
				}
				else if (grid_y == 6) {
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
void gotoXY(int * x, int * y, int gameMod)
{
	if (gameMod == 0 && (*y <= 0 || *y >= 8))
	{
		if (*y <= 0) {	(*y) += 2;	}
		else {	(*y) -= 2;	}

	}
	else if (gameMod == 0 && *x != 0) { *x = 0; }
	else if (gameMod == 1)
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
void resetSetting(int board[][15], int* grid_x, int* grid_y, int* gameMod, int* turn) 
{
	*grid_x = 0;
	*grid_y = 2;
	*gameMod = 0;
	*turn = 1;

	for (int a = 0; a < 15; a++) {
		for (int b = 0; b < 15; b++) {
			board[a][b] = 0;
		}
	}

	system("cls");
	gotoXY(grid_x, grid_y, gameMod);
	drawMenu();
	gotoXY(grid_x, grid_y, gameMod);
}
void setGameSetting(int* grid_x, int* grid_y, int* gameMod)
{
	system("cls");
	*grid_x = 21;
	*grid_y = 7;
	*gameMod = 1;
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

void putRock(int board[][15], int grid_x, int grid_y, int* turn)
{
	if (*turn == 1) {
		if (checkSam(board, grid_x, grid_y) >= 2 || checkJang(board, grid_x, grid_y) == 1 || checkSa(board, grid_x, grid_y) >= 2) {
			alretKim(&grid_x, &grid_y, 1);
			return;
		}
		printf("∞");
		board[grid_y][grid_x / 3] = 1;
		
		(*turn)++;
	}
	else {
		printf("≒");
		board[grid_y][grid_x / 3] = 2;

		(*turn)--;
	}
}
int checkRes(int board[][15], int grid_x, int grid_y)
{
	int res = 1;
	
	if (1 == board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] * board[grid_y][grid_x / 3 + 4] ||
		1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] || 
		1 == board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] || 
		1 == board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] ||
		1 == board[grid_y][grid_x / 3 - 4] * board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] ||

		1 == board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] * board[grid_y + 4][grid_x / 3] || 
		1 == board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] ||
		1 == board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] ||
		1 == board[grid_y - 3][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] ||
		1 == board[grid_y - 4][grid_x / 3] * board[grid_y - 3][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] ||

		1 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] * board[grid_y - 4][grid_x / 3 + 4] ||
		1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] ||
		1 == board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] ||
		1 == board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] ||
		1 == board[grid_y + 4][grid_x / 3 - 4] * board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3 - 1] ||

		1 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y - 4][grid_x / 3 - 4] ||
		1 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y + 1][grid_x / 3 + 1] ||
		1 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 1][grid_x / 3 + 1] ||
		1 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 1][grid_x / 3 + 1] ||
		1 == board[grid_y][grid_x / 3] * board[grid_y + 4][grid_x / 3 + 4] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 1][grid_x / 3 + 1]) {
		
		printRes(1);
		return 1;
	}
	else if (32 == board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] * board[grid_y][grid_x / 3 + 4] ||
		32 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] ||
		32 == board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] ||
		32 == board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y][grid_x / 3 + 1] ||
		32 == board[grid_y][grid_x / 3 - 4] * board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3] ||

		32 == board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] * board[grid_y + 4][grid_x / 3] ||
		32 == board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] ||
		32 == board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] ||
		32 == board[grid_y - 3][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3] ||
		32 == board[grid_y - 4][grid_x / 3] * board[grid_y - 3][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y][grid_x / 3] ||

		32 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] * board[grid_y - 4][grid_x / 3 + 4] ||
		32 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] ||
		32 == board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] ||
		32 == board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 - 1] * board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 + 1] ||
		32 == board[grid_y + 4][grid_x / 3 - 4] * board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y][grid_x / 3] * board[grid_y + 1][grid_x / 3 - 1] ||

		32 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y - 4][grid_x / 3 - 4] ||
		32 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y + 1][grid_x / 3 + 1] ||
		32 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 1][grid_x / 3 + 1] ||
		32 == board[grid_y][grid_x / 3] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 1][grid_x / 3 + 1] ||
		32 == board[grid_y][grid_x / 3] * board[grid_y + 4][grid_x / 3 + 4] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 1][grid_x / 3 + 1]) {
		
		printRes(32);
		return 32;
	}
	return 0;
}
void printRes(int res)
{
	gotoXY_g(50, 8);
	if (res == 1) 
		printf("Black Win!!\n");
	else
		printf("White Win!!\n");

	Sleep(1000);
}
