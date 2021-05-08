#include <stdio.h>
#include <Windows.h>

#include "renJu.h"

extern void gotoXY_g(int x, int y);
extern void gotoXY(int* x, int* y, int gameMod);

int checkJang(int board[][15], int grid_x, int grid_y)
{
	int res = 0;

	if (1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] * board[grid_y][grid_x / 3 + 4] * board[grid_y][grid_x / 3 - 1] ||
		1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] ||
		1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] ||
		1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 4] * board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 1] ||

		1 == board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] * board[grid_y + 4][grid_x / 3] * board[grid_y - 1][grid_x / 3] ||
		1 == board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] ||
		1 == board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y - 3][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] ||
		1 == board[grid_y + 1][grid_x / 3] * board[grid_y - 4][grid_x / 3] * board[grid_y - 3][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 1][grid_x / 3] ||

		1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] * board[grid_y - 4][grid_x / 3 + 4] * board[grid_y + 1][grid_x / 3 - 1] ||
		1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 - 1] ||
		1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 - 1] ||
		1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y + 4][grid_x / 3 - 4] * board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 - 1] ||

		1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y - 4][grid_x / 3 - 4] * board[grid_y + 1][grid_x / 3 + 1] ||
		1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 + 1] ||
		1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 + 1] ||
		1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 4][grid_x / 3 + 4] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 1][grid_x / 3 + 1]) {
		return 1;
	}
	return 0;
}
int checkSa(int board[][15], int grid_x, int grid_y)
{
	int cnt = 0;
	if (grid_x / 3 - 4 < 0 || grid_x / 3 + 4 > 15 || grid_y < 0 || grid_y > 15)
		return 0;

	//printf("%d %d\n", grid_x, grid_y);

	if ((1 == board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 4] && board[grid_y][grid_x / 3 - 1] == 0) && !(board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 5] == 4) ||
		(1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 - 4] && board[grid_y][grid_x / 3 - 2] == 0) && !(board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 5] == 4) ||
		(1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 4] && board[grid_y][grid_x / 3 - 3] == 0) && !(board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 5] == 4) ||
		(1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 3]) && !(board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 4] == 4) ||
		(1 == board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] * board[grid_y][grid_x / 3 + 4] && board[grid_y][grid_x / 3 + 1] == 0) && !(board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 3] * board[grid_y][grid_x / 3 + 4] && board[grid_y][grid_x / 3 + 2] == 0) && !(board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 4] && board[grid_y][grid_x / 3 + 3] == 0) && !(board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3]) && !(board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 4] == 4) ||

		(1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2]) && !(board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 + 3] == 4) ||
		(1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 3] && board[grid_y][grid_x / 3 + 2] == 0) && !(board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] && board[grid_y][grid_x / 3 + 1] == 0) && !(board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 2]) && !(board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 - 3] == 4) ||
		(1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 3] && board[grid_y][grid_x / 3 - 2] == 0) && !(board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 - 4] == 4) ||
		(1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 3] && board[grid_y][grid_x / 3 - 1] == 0) && !(board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 - 4] == 4) ||

		(1 == board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 - 2] && board[grid_y][grid_x / 3 - 1] == 0) && !(board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 + 3] == 4) ||
		(1 == board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 + 2] && board[grid_y][grid_x / 3 + 1] == 0) && !(board[grid_y][grid_x / 3 - 3] * board[grid_y][grid_x / 3 + 3] == 4)) {
		cnt++;
	}

	if ((1 == board[grid_y - 2][grid_x / 3] * board[grid_y - 3][grid_x / 3] * board[grid_y - 4][grid_x / 3] && board[grid_y - 1][grid_x / 3] == 0) && !(board[grid_y + 1][grid_x / 3] * board[grid_y - 5][grid_x / 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3] * board[grid_y - 3][grid_x / 3] * board[grid_y - 4][grid_x / 3] && board[grid_y - 2][grid_x / 3] == 0) && !(board[grid_y + 1][grid_x / 3] * board[grid_y - 5][grid_x / 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 4][grid_x / 3] && board[grid_y - 3][grid_x / 3] == 0) && !(board[grid_y + 1][grid_x / 3] * board[grid_y - 5][grid_x / 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 3][grid_x / 3]) && !(board[grid_y + 1][grid_x / 3] * board[grid_y - 4][grid_x / 3] == 4) ||
		(1 == board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] * board[grid_y + 4][grid_x / 3] && board[grid_y + 1][grid_x / 3] == 0) && !(board[grid_y - 1][grid_x / 3] * board[grid_y + 5][grid_x / 3] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3] * board[grid_y + 3][grid_x / 3] * board[grid_y + 4][grid_x / 3] && board[grid_y + 2][grid_x / 3] == 0) && !(board[grid_y - 1][grid_x / 3] * board[grid_y + 5][grid_x / 3] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 4][grid_x / 3] && board[grid_y + 3][grid_x / 3] == 0) && !(board[grid_y - 1][grid_x / 3] * board[grid_y + 5][grid_x / 3] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3]) && !(board[grid_y - 1][grid_x / 3] * board[grid_y + 4][grid_x / 3] == 4) ||

		(1 == board[grid_y - 1][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3]) && !(board[grid_y - 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3] * board[grid_y + 1][grid_x / 3] * board[grid_y + 3][grid_x / 3] && board[grid_y + 2][grid_x / 3] == 0) && !(board[grid_y - 2][grid_x / 3] * board[grid_y + 4][grid_x / 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] && board[grid_y + 1][grid_x / 3] == 0) && !(board[grid_y - 2][grid_x / 3] * board[grid_y + 4][grid_x / 3] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y - 2][grid_x / 3]) && !(board[grid_y + 2][grid_x / 3] * board[grid_y - 3][grid_x / 3] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3] * board[grid_y - 1][grid_x / 3] * board[grid_y - 3][grid_x / 3] && board[grid_y - 2][grid_x / 3] == 0) && !(board[grid_y + 2][grid_x / 3] * board[grid_y - 4][grid_x / 3] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y - 3][grid_x / 3] && board[grid_y - 1][grid_x / 3] == 0) && !(board[grid_y + 2][grid_x / 3] * board[grid_y - 4][grid_x / 3] == 4) ||

		(1 == board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] * board[grid_y - 2][grid_x / 3] && board[grid_y - 1][grid_x / 3] == 0) && !(board[grid_y - 3][grid_x / 3] * board[grid_y + 3][grid_x / 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3] * board[grid_y - 2][grid_x / 3] * board[grid_y + 2][grid_x / 3] && board[grid_y + 1][grid_x / 3] == 0) && !(board[grid_y - 3][grid_x / 3] * board[grid_y + 3][grid_x / 3] == 4)) {
		cnt++;
	}
	if ((1 == board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] * board[grid_y - 4][grid_x / 3 + 4] && board[grid_y - 1][grid_x / 3 + 1] == 0) && !(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 5][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 3][grid_x / 3 + 3] * board[grid_y - 4][grid_x / 3 + 4] && board[grid_y - 2][grid_x / 3 + 2] == 0) && !(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 5][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 4][grid_x / 3 + 4] && board[grid_y - 3][grid_x / 3 + 3] == 0) && !(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 5][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3]) && !(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 4][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 4][grid_x / 3 - 4] && board[grid_y + 1][grid_x / 3 - 1] == 0) && !(board[grid_y + 5][grid_x / 3 - 5] * board[grid_y - 1][grid_x / 3 + 1] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 3][grid_x / 3 - 3] * board[grid_y + 4][grid_x / 3 - 4] && board[grid_y + 2][grid_x / 3 - 2] == 0) && !(board[grid_y + 5][grid_x / 3 - 5] * board[grid_y - 1][grid_x / 3 + 1] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 4][grid_x / 3 - 4] && board[grid_y + 3][grid_x / 3 - 3] == 0) && !(board[grid_y + 5][grid_x / 3 - 5] * board[grid_y - 1][grid_x / 3 + 1] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 3][grid_x / 3 - 3]) && !(board[grid_y + 4][grid_x / 3 - 4] * board[grid_y - 1][grid_x / 3 + 1] == 4) ||

		(1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] && board[grid_y - 1][grid_x / 3 + 1] == 0) && !(board[grid_y + 2][grid_x / 3 - 2] * board[grid_y - 4][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 3][grid_x / 3 + 3] && board[grid_y - 2][grid_x / 3 + 2] == 0) && !(board[grid_y + 2][grid_x / 3 - 2] * board[grid_y - 4][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2]) && !(board[grid_y + 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 + 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 3][grid_x / 3 - 3] && board[grid_y + 1][grid_x / 3 - 1] == 0) && !(board[grid_y - 2][grid_x / 3 + 2] * board[grid_y + 4][grid_x / 3 - 4] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 3][grid_x / 3 - 3] && board[grid_y + 2][grid_x / 3 - 2] == 0) && !(board[grid_y - 2][grid_x / 3 + 2] * board[grid_y + 4][grid_x / 3 - 4] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 2][grid_x / 3 - 2]) && !(board[grid_y - 2][grid_x / 3 + 2] * board[grid_y + 4][grid_x / 3 - 4] == 4) ||

		(1 == board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 2][grid_x / 3 - 2] * board[grid_y - 2][grid_x / 3 + 2] && board[grid_y - 1][grid_x / 3 + 1] == 0) && !(board[grid_y - 3][grid_x / 3 + 3] * board[grid_y + 3][grid_x / 3 - 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] * board[grid_y + 2][grid_x / 3 - 2] && board[grid_y + 1][grid_x / 3 - 1] == 0) && !(board[grid_y - 3][grid_x / 3 + 3] * board[grid_y + 3][grid_x / 3 - 3] == 4)) {
		cnt++;
	}
	if ((1 == board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 4][grid_x / 3 + 4] && board[grid_y + 1][grid_x / 3 + 1] == 0) && !(board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 5][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 3][grid_x / 3 + 3] * board[grid_y + 4][grid_x / 3 + 4] && board[grid_y + 2][grid_x / 3 + 2] == 0) && !(board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 5][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 4][grid_x / 3 + 4] && board[grid_y + 3][grid_x / 3 + 3] == 0) && !(board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 5][grid_x / 3 + 5] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 3][grid_x / 3 + 3]) && !(board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 4][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y - 4][grid_x / 3 - 4] && board[grid_y - 1][grid_x / 3 - 1] == 0) && !(board[grid_y - 5][grid_x / 3 - 5] * board[grid_y + 1][grid_x / 3 + 1] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 3][grid_x / 3 - 3] * board[grid_y - 4][grid_x / 3 - 4] && board[grid_y - 2][grid_x / 3 - 2] == 0) && !(board[grid_y - 5][grid_x / 3 - 5] * board[grid_y + 1][grid_x / 3 + 1] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 4][grid_x / 3 - 4] && board[grid_y - 3][grid_x / 3 - 3] == 0) && !(board[grid_y - 5][grid_x / 3 - 5] * board[grid_y + 1][grid_x / 3 + 1] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3]) && !(board[grid_y - 4][grid_x / 3 - 4] * board[grid_y + 1][grid_x / 3 + 1] == 4) ||

		(1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 3][grid_x / 3 + 3] && board[grid_y + 1][grid_x / 3 + 1] == 0) && !(board[grid_y - 2][grid_x / 3 - 2] * board[grid_y + 4][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 3][grid_x / 3 + 3] && board[grid_y + 2][grid_x / 3 + 2] == 0) && !(board[grid_y - 2][grid_x / 3 - 2] * board[grid_y + 4][grid_x / 3 + 4] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 2][grid_x / 3 + 2]) && !(board[grid_y - 2][grid_x / 3 - 2] * board[grid_y + 3][grid_x / 3 + 3] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] && board[grid_y - 1][grid_x / 3 - 1] == 0) && !(board[grid_y + 2][grid_x / 3 + 2] * board[grid_y - 4][grid_x / 3 - 4] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 + 1] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 3][grid_x / 3 - 3] && board[grid_y - 2][grid_x / 3 - 2] == 0) && !(board[grid_y + 2][grid_x / 3 + 2] * board[grid_y - 4][grid_x / 3 - 4] == 4) ||
		(1 == board[grid_y + 1][grid_x / 3 + 1] * board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2]) && !(board[grid_y + 2][grid_x / 3 + 2] * board[grid_y - 4][grid_x / 3 - 4] == 4) ||

		(1 == board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 2][grid_x / 3 + 2] * board[grid_y - 2][grid_x / 3 - 2] && board[grid_y - 1][grid_x / 3 - 1] == 0) && !(board[grid_y + 3][grid_x / 3 + 3] * board[grid_y - 3][grid_x / 3 - 3] == 4) ||
		(1 == board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] * board[grid_y + 2][grid_x / 3 + 2] && board[grid_y + 1][grid_x / 3 + 1] == 0) && !(board[grid_y + 3][grid_x / 3 + 3] * board[grid_y - 3][grid_x / 3 - 3] == 4)) {
		cnt++;
	}

	return cnt;
}
int checkSam(int board[][15], int grid_x, int grid_y)
{
	int cnt = 0;
	if (grid_x / 3 - 4 < 0 || grid_x / 3 + 4 > 15 || grid_y < 0 || grid_y > 15)
		return 0;

	if ((board[grid_y - 1][grid_x / 3] * board[grid_y - 2][grid_x / 3] == 1 && board[grid_y - 3][grid_x / 3] == 0 && board[grid_y + 1][grid_x / 3] == 0) ||
		(board[grid_y - 2][grid_x / 3] * board[grid_y - 3][grid_x / 3] == 1 && board[grid_y - 4][grid_x / 3] == 0 && board[grid_y + 1][grid_x / 3] == 0 && board[grid_y - 1][grid_x / 3] == 0) ||
		(board[grid_y - 1][grid_x / 3] * board[grid_y - 3][grid_x / 3] == 1 && board[grid_y - 4][grid_x / 3] == 0 && board[grid_y + 1][grid_x / 3] == 0 && board[grid_y - 2][grid_x / 3] == 0) ||

		(board[grid_y + 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] == 1 && board[grid_y + 3][grid_x / 3] == 0 && board[grid_y - 1][grid_x / 3] == 0) ||
		(board[grid_y + 2][grid_x / 3] * board[grid_y + 3][grid_x / 3] == 1 && board[grid_y + 4][grid_x / 3] == 0 && board[grid_y - 1][grid_x / 3] == 0 && board[grid_y + 1][grid_x / 3] == 0) ||
		(board[grid_y + 1][grid_x / 3] * board[grid_y + 3][grid_x / 3] == 1 && board[grid_y + 4][grid_x / 3] == 0 && board[grid_y - 1][grid_x / 3] == 0 && board[grid_y + 2][grid_x / 3] == 0) ||

		(board[grid_y + 1][grid_x / 3] * board[grid_y - 1][grid_x / 3] == 1 && board[grid_y + 2][grid_x / 3] == 0 && board[grid_y - 2][grid_x / 3] == 0) ||
		(board[grid_y - 2][grid_x / 3] * board[grid_y + 1][grid_x / 3] == 1 && board[grid_y - 1][grid_x / 3] == 0 && board[grid_y + 2][grid_x / 3] == 0 && board[grid_y - 3][grid_x / 3] == 0) ||
		(board[grid_y - 1][grid_x / 3] * board[grid_y + 2][grid_x / 3] == 1 && board[grid_y + 1][grid_x / 3] == 0 && board[grid_y + 3][grid_x / 3] == 0 && board[grid_y - 2][grid_x / 3] == 0)
		) {
		cnt++;
	}		//세로에 3이있는지
	if ((board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 2] == 1 && board[grid_y][grid_x / 3 + 3] == 0 && board[grid_y][grid_x / 3 - 1] == 0) ||
		(board[grid_y][grid_x / 3 + 2] * board[grid_y][grid_x / 3 + 3] == 1 && board[grid_y][grid_x / 3 - 1] == 0 && board[grid_y][grid_x / 3 + 1] == 0 && board[grid_y][grid_x / 3 + 4] == 0) ||
		(board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 + 3] == 1 && board[grid_y][grid_x / 3 - 1] == 0 && board[grid_y][grid_x / 3 + 2] == 0 && board[grid_y][grid_x / 3 + 4] == 0) ||

		(board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 2] == 1 && board[grid_y][grid_x / 3 - 3] == 0 && board[grid_y][grid_x / 3 + 1] == 0) ||
		(board[grid_y][grid_x / 3 - 2] * board[grid_y][grid_x / 3 - 3] == 1 && board[grid_y][grid_x / 3 + 1] == 0 && board[grid_y][grid_x / 3 - 1] == 0 && board[grid_y][grid_x / 3 - 4] == 0) ||
		(board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 - 3] == 1 && board[grid_y][grid_x / 3 + 1] == 0 && board[grid_y][grid_x / 3 - 2] == 0 && board[grid_y][grid_x / 3 - 4] == 0) ||

		(board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 1] == 1 && board[grid_y][grid_x / 3 + 2] == 0 && board[grid_y][grid_x / 3 - 2] == 0) ||
		(board[grid_y][grid_x / 3 + 1] * board[grid_y][grid_x / 3 - 2] == 1 && board[grid_y][grid_x / 3 + 2] == 0 && board[grid_y][grid_x / 3 - 1] == 0 && board[grid_y][grid_x / 3 - 3] == 0) ||
		(board[grid_y][grid_x / 3 - 1] * board[grid_y][grid_x / 3 + 2] == 1 && board[grid_y][grid_x / 3 - 2] == 0 && board[grid_y][grid_x / 3 + 1] == 0 && board[grid_y][grid_x / 3 + 3] == 0)
		) {
		cnt++;
	}		//가로에 3이있는지
	if ((board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 + 2] == 1 && board[grid_y - 3][grid_x / 3 + 3] == 0 && board[grid_y + 1][grid_x / 3 - 1] == 0) ||
		(board[grid_y - 2][grid_x / 3 + 2] * board[grid_y - 3][grid_x / 3 + 3] == 1 && board[grid_y + 1][grid_x / 3 - 1] == 0 && board[grid_y - 1][grid_x / 3 + 1] == 0 && board[grid_y - 4][grid_x / 3 + 4] == 0) ||
		(board[grid_y - 1][grid_x / 3 + 1] * board[grid_y - 3][grid_x / 3 + 3] == 1 && board[grid_y + 1][grid_x / 3 - 1] == 0 && board[grid_y - 2][grid_x / 3 + 2] == 0 && board[grid_y - 4][grid_x / 3 + 4] == 0) ||

		(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 2][grid_x / 3 - 2] == 1 && board[grid_y + 3][grid_x / 3 - 3] == 0 && board[grid_y - 1][grid_x / 3 + 1] == 0) ||
		(board[grid_y + 2][grid_x / 3 - 2] * board[grid_y + 3][grid_x / 3 - 3] == 1 && board[grid_y - 1][grid_x / 3 + 1] == 0 && board[grid_y + 1][grid_x / 3 - 1] == 0 && board[grid_y + 4][grid_x / 3 - 4] == 0) ||
		(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y + 3][grid_x / 3 - 3] == 1 && board[grid_y - 1][grid_x / 3 + 1] == 0 && board[grid_y + 2][grid_x / 3 - 2] == 0 && board[grid_y + 4][grid_x / 3 - 4] == 0) ||

		(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 1][grid_x / 3 + 1] == 1 && board[grid_y + 2][grid_x / 3 - 2] == 0 && board[grid_y - 2][grid_x / 3 + 2] == 0) ||
		(board[grid_y + 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 + 2] == 1 && board[grid_y + 2][grid_x / 3 - 2] == 0 && board[grid_y - 1][grid_x / 3 + 1] == 0 && board[grid_y - 3][grid_x / 3 + 3] == 0) ||
		(board[grid_y + 2][grid_x / 3 - 2] * board[grid_y - 1][grid_x / 3 + 1] == 1 && board[grid_y + 3][grid_x / 3 - 3] == 0 && board[grid_y + 1][grid_x / 3 - 1] == 0 && board[grid_y - 2][grid_x / 3 + 2] == 0)
		) {
		cnt++;
	}		//우상향대각에 3이있는지
	if ((board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 2][grid_x / 3 + 2] == 1 && board[grid_y + 3][grid_x / 3 + 3] == 0 && board[grid_y - 1][grid_x / 3 - 1] == 0) ||
		(board[grid_y + 2][grid_x / 3 + 2] * board[grid_y + 3][grid_x / 3 + 3] == 1 && board[grid_y - 1][grid_x / 3 - 1] == 0 && board[grid_y + 1][grid_x / 3 + 1] == 0 && board[grid_y + 4][grid_x / 3 + 4] == 0) ||
		(board[grid_y + 1][grid_x / 3 + 1] * board[grid_y + 3][grid_x / 3 + 3] == 1 && board[grid_y - 1][grid_x / 3 - 1] == 0 && board[grid_y + 2][grid_x / 3 + 2] == 0 && board[grid_y + 4][grid_x / 3 + 4] == 0) ||

		(board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 2][grid_x / 3 - 2] == 1 && board[grid_y - 3][grid_x / 3 - 3] == 0 && board[grid_y + 1][grid_x / 3 + 1] == 0) ||
		(board[grid_y - 2][grid_x / 3 - 2] * board[grid_y - 3][grid_x / 3 - 3] == 1 && board[grid_y + 1][grid_x / 3 + 1] == 0 && board[grid_y - 1][grid_x / 3 - 1] == 0 && board[grid_y - 4][grid_x / 3 - 4] == 0) ||
		(board[grid_y - 1][grid_x / 3 - 1] * board[grid_y - 3][grid_x / 3 - 3] == 1 && board[grid_y + 1][grid_x / 3 + 1] == 0 && board[grid_y + 2][grid_x / 3 + 2] == 0 && board[grid_y - 4][grid_x / 3 - 4] == 0) ||

		(board[grid_y + 1][grid_x / 3 + 1] * board[grid_y - 1][grid_x / 3 - 1] == 1 && board[grid_y + 2][grid_x / 3 + 2] == 0 && board[grid_y - 2][grid_x / 3 - 2] == 0) ||
		(board[grid_y + 2][grid_x / 3 + 2] * board[grid_y - 1][grid_x / 3 - 1] == 1 && board[grid_y + 1][grid_x / 3 + 1] == 0 && board[grid_y - 2][grid_x / 3 - 2] == 0 && board[grid_y + 3][grid_x / 3 + 3] == 0) ||
		(board[grid_y + 1][grid_x / 3 + 1] * board[grid_y - 2][grid_x / 3 - 2] == 1 && board[grid_y - 1][grid_x / 3 - 1] == 0 && board[grid_y - 3][grid_x / 3 - 3] == 0 && board[grid_y + 2][grid_x / 3 + 2] == 0)
		) {
		cnt++;
	}		//좌상향대각에 3이있는지

	if (cnt >= 2) {
		board[grid_y][grid_x / 3] = 1;
		if (checkInterrupt(board) == 1) {
			return 1;
		}
	}
	board[grid_y][grid_x / 3] = 0;

	return cnt;
}
int checkInterrupt(int board[][15])
{
	int a = 0, b = 0;

	for (a = 0; a < 15; a++)
		for (b = 0; b < 45; b += 3)
			if (checkSa(board, b, a) >= 2)
				return 1;
	return 2;
}
void alretKim(int* x, int* y, int gameMod)
{
	gotoXY_g(50, 8);
	printf("금수입니다.");
	gotoXY_g(50, 8);
	Sleep(1000);
	printf("               ");
	gotoXY(x, y, gameMod);
}