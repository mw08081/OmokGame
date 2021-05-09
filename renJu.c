#include <stdio.h>
#include <Windows.h>

#include "renJu.h"

extern void gotoXY_g(int x, int y);
extern void gotoXY(int* x, int* y, int gameMod);

extern int board[15][15];

int checkJang(int gridX, int gridY)
{
	int res = 0;

	if (243 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] * board[gridY][gridX / 3 + 4] * board[gridY][gridX / 3 - 1] ||
		243 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] ||
		243 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] ||
		243 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 4] * board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 1] ||

		243 == board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] * board[gridY + 4][gridX / 3] * board[gridY - 1][gridX / 3] ||
		243 == board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] ||
		243 == board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY - 3][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] ||
		243 == board[gridY + 1][gridX / 3] * board[gridY - 4][gridX / 3] * board[gridY - 3][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 1][gridX / 3] ||

		243 == board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] * board[gridY - 4][gridX / 3 + 4] * board[gridY + 1][gridX / 3 - 1] ||
		243 == board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 - 1] ||
		243 == board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY + 3][gridX / 3 - 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 - 1] ||
		243 == board[gridY - 1][gridX / 3 + 1] * board[gridY + 4][gridX / 3 - 4] * board[gridY + 3][gridX / 3 - 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 - 1] ||

		243 == board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] * board[gridY - 4][gridX / 3 - 4] * board[gridY + 1][gridX / 3 + 1] ||
		243 == board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 + 1] ||
		243 == board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 + 1] ||
		243 == board[gridY - 1][gridX / 3 - 1] * board[gridY + 4][gridX / 3 + 4] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 1][gridX / 3 + 1]) {
		return 1;
	}
	return 0;
}
int checkSa(int gridX, int gridY)
{
	int cnt = 0;
	if (gridX / 3 - 4 < 0 || gridX / 3 + 4 > 15 || gridY < 0 || gridY > 15)
		return 0;

	if ((27 == board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 4] && board[gridY][gridX / 3 - 1] == 0) && !(board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 5] == 4) ||
		(27 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 - 4] && board[gridY][gridX / 3 - 2] == 0) && !(board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 5] == 4) ||
		(27 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 4] && board[gridY][gridX / 3 - 3] == 0) && !(board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 5] == 4) ||
		(27 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 3]) && !(board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 4] == 4) ||
		(27 == board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] * board[gridY][gridX / 3 + 4] && board[gridY][gridX / 3 + 1] == 0) && !(board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 5] == 4) ||
		(27 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 3] * board[gridY][gridX / 3 + 4] && board[gridY][gridX / 3 + 2] == 0) && !(board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 5] == 4) ||
		(27 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 4] && board[gridY][gridX / 3 + 3] == 0) && !(board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 5] == 4) ||
		(27 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3]) && !(board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 4] == 4) ||

		(27 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2]) && !(board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 + 3] == 4) ||
		(27 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 3] && board[gridY][gridX / 3 + 2] == 0) && !(board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 + 4] == 4) ||
		(27 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] && board[gridY][gridX / 3 + 1] == 0) && !(board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 + 4] == 4) ||
		(27 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 2]) && !(board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 - 3] == 4) ||
		(27 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 3] && board[gridY][gridX / 3 - 2] == 0) && !(board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 - 4] == 4) ||
		(27 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 3] && board[gridY][gridX / 3 - 1] == 0) && !(board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 - 4] == 4) ||

		(27 == board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 - 2] && board[gridY][gridX / 3 - 1] == 0) && !(board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 + 3] == 4) ||
		(27 == board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 + 2] && board[gridY][gridX / 3 + 1] == 0) && !(board[gridY][gridX / 3 - 3] * board[gridY][gridX / 3 + 3] == 4)) {
		cnt++;
	}

	if ((27 == board[gridY - 2][gridX / 3] * board[gridY - 3][gridX / 3] * board[gridY - 4][gridX / 3] && board[gridY - 1][gridX / 3] == 0) && !(board[gridY + 1][gridX / 3] * board[gridY - 5][gridX / 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3] * board[gridY - 3][gridX / 3] * board[gridY - 4][gridX / 3] && board[gridY - 2][gridX / 3] == 0) && !(board[gridY + 1][gridX / 3] * board[gridY - 5][gridX / 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 4][gridX / 3] && board[gridY - 3][gridX / 3] == 0) && !(board[gridY + 1][gridX / 3] * board[gridY - 5][gridX / 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 3][gridX / 3]) && !(board[gridY + 1][gridX / 3] * board[gridY - 4][gridX / 3] == 4) ||
		(27 == board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] * board[gridY + 4][gridX / 3] && board[gridY + 1][gridX / 3] == 0) && !(board[gridY - 1][gridX / 3] * board[gridY + 5][gridX / 3] == 4) ||
		(27 == board[gridY + 1][gridX / 3] * board[gridY + 3][gridX / 3] * board[gridY + 4][gridX / 3] && board[gridY + 2][gridX / 3] == 0) && !(board[gridY - 1][gridX / 3] * board[gridY + 5][gridX / 3] == 4) ||
		(27 == board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 4][gridX / 3] && board[gridY + 3][gridX / 3] == 0) && !(board[gridY - 1][gridX / 3] * board[gridY + 5][gridX / 3] == 4) ||
		(27 == board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3]) && !(board[gridY - 1][gridX / 3] * board[gridY + 4][gridX / 3] == 4) ||

		(27 == board[gridY - 1][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3]) && !(board[gridY - 2][gridX / 3] * board[gridY + 3][gridX / 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3] * board[gridY + 1][gridX / 3] * board[gridY + 3][gridX / 3] && board[gridY + 2][gridX / 3] == 0) && !(board[gridY - 2][gridX / 3] * board[gridY + 4][gridX / 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] && board[gridY + 1][gridX / 3] == 0) && !(board[gridY - 2][gridX / 3] * board[gridY + 4][gridX / 3] == 4) ||
		(27 == board[gridY + 1][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY - 2][gridX / 3]) && !(board[gridY + 2][gridX / 3] * board[gridY - 3][gridX / 3] == 4) ||
		(27 == board[gridY + 1][gridX / 3] * board[gridY - 1][gridX / 3] * board[gridY - 3][gridX / 3] && board[gridY - 2][gridX / 3] == 0) && !(board[gridY + 2][gridX / 3] * board[gridY - 4][gridX / 3] == 4) ||
		(27 == board[gridY + 1][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY - 3][gridX / 3] && board[gridY - 1][gridX / 3] == 0) && !(board[gridY + 2][gridX / 3] * board[gridY - 4][gridX / 3] == 4) ||

		(27 == board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] * board[gridY - 2][gridX / 3] && board[gridY - 1][gridX / 3] == 0) && !(board[gridY - 3][gridX / 3] * board[gridY + 3][gridX / 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3] * board[gridY - 2][gridX / 3] * board[gridY + 2][gridX / 3] && board[gridY + 1][gridX / 3] == 0) && !(board[gridY - 3][gridX / 3] * board[gridY + 3][gridX / 3] == 4)) {
		cnt++;
	}
	if ((27 == board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] * board[gridY - 4][gridX / 3 + 4] && board[gridY - 1][gridX / 3 + 1] == 0) && !(board[gridY + 1][gridX / 3 - 1] * board[gridY - 5][gridX / 3 + 5] == 4) ||
		(27 == board[gridY - 1][gridX / 3 + 1] * board[gridY - 3][gridX / 3 + 3] * board[gridY - 4][gridX / 3 + 4] && board[gridY - 2][gridX / 3 + 2] == 0) && !(board[gridY + 1][gridX / 3 - 1] * board[gridY - 5][gridX / 3 + 5] == 4) ||
		(27 == board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 4][gridX / 3 + 4] && board[gridY - 3][gridX / 3 + 3] == 0) && !(board[gridY + 1][gridX / 3 - 1] * board[gridY - 5][gridX / 3 + 5] == 4) ||
		(27 == board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3]) && !(board[gridY + 1][gridX / 3 - 1] * board[gridY - 4][gridX / 3 + 4] == 4) ||
		(27 == board[gridY + 2][gridX / 3 - 2] * board[gridY + 3][gridX / 3 - 3] * board[gridY + 4][gridX / 3 - 4] && board[gridY + 1][gridX / 3 - 1] == 0) && !(board[gridY + 5][gridX / 3 - 5] * board[gridY - 1][gridX / 3 + 1] == 4) ||
		(27 == board[gridY + 1][gridX / 3 - 1] * board[gridY + 3][gridX / 3 - 3] * board[gridY + 4][gridX / 3 - 4] && board[gridY + 2][gridX / 3 - 2] == 0) && !(board[gridY + 5][gridX / 3 - 5] * board[gridY - 1][gridX / 3 + 1] == 4) ||
		(27 == board[gridY + 1][gridX / 3 - 1] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 4][gridX / 3 - 4] && board[gridY + 3][gridX / 3 - 3] == 0) && !(board[gridY + 5][gridX / 3 - 5] * board[gridY - 1][gridX / 3 + 1] == 4) ||
		(27 == board[gridY + 1][gridX / 3 - 1] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 3][gridX / 3 - 3]) && !(board[gridY + 4][gridX / 3 - 4] * board[gridY - 1][gridX / 3 + 1] == 4) ||

		(27 == board[gridY + 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] && board[gridY - 1][gridX / 3 + 1] == 0) && !(board[gridY + 2][gridX / 3 - 2] * board[gridY - 4][gridX / 3 + 4] == 4) ||
		(27 == board[gridY + 1][gridX / 3 - 1] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 3][gridX / 3 + 3] && board[gridY - 2][gridX / 3 + 2] == 0) && !(board[gridY + 2][gridX / 3 - 2] * board[gridY - 4][gridX / 3 + 4] == 4) ||
		(27 == board[gridY + 1][gridX / 3 - 1] * board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2]) && !(board[gridY + 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 + 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3 + 1] * board[gridY + 2][gridX / 3 - 2] * board[gridY + 3][gridX / 3 - 3] && board[gridY + 1][gridX / 3 - 1] == 0) && !(board[gridY - 2][gridX / 3 + 2] * board[gridY + 4][gridX / 3 - 4] == 4) ||
		(27 == board[gridY - 1][gridX / 3 + 1] * board[gridY + 1][gridX / 3 - 1] * board[gridY + 3][gridX / 3 - 3] && board[gridY + 2][gridX / 3 - 2] == 0) && !(board[gridY - 2][gridX / 3 + 2] * board[gridY + 4][gridX / 3 - 4] == 4) ||
		(27 == board[gridY - 1][gridX / 3 + 1] * board[gridY + 1][gridX / 3 - 1] * board[gridY + 2][gridX / 3 - 2]) && !(board[gridY - 2][gridX / 3 + 2] * board[gridY + 4][gridX / 3 - 4] == 4) ||

		(27 == board[gridY + 1][gridX / 3 - 1] * board[gridY + 2][gridX / 3 - 2] * board[gridY - 2][gridX / 3 + 2] && board[gridY - 1][gridX / 3 + 1] == 0) && !(board[gridY - 3][gridX / 3 + 3] * board[gridY + 3][gridX / 3 - 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] * board[gridY + 2][gridX / 3 - 2] && board[gridY + 1][gridX / 3 - 1] == 0) && !(board[gridY - 3][gridX / 3 + 3] * board[gridY + 3][gridX / 3 - 3] == 4)) {
		cnt++;
	}
	if ((27 == board[gridY + 2][gridX / 3 + 2] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 4][gridX / 3 + 4] && board[gridY + 1][gridX / 3 + 1] == 0) && !(board[gridY - 1][gridX / 3 - 1] * board[gridY + 5][gridX / 3 + 5] == 4) ||
		(27 == board[gridY + 1][gridX / 3 + 1] * board[gridY + 3][gridX / 3 + 3] * board[gridY + 4][gridX / 3 + 4] && board[gridY + 2][gridX / 3 + 2] == 0) && !(board[gridY - 1][gridX / 3 - 1] * board[gridY + 5][gridX / 3 + 5] == 4) ||
		(27 == board[gridY + 1][gridX / 3 + 1] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 4][gridX / 3 + 4] && board[gridY + 3][gridX / 3 + 3] == 0) && !(board[gridY - 1][gridX / 3 - 1] * board[gridY + 5][gridX / 3 + 5] == 4) ||
		(27 == board[gridY + 1][gridX / 3 + 1] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 3][gridX / 3 + 3]) && !(board[gridY - 1][gridX / 3 - 1] * board[gridY + 4][gridX / 3 + 4] == 4) ||
		(27 == board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] * board[gridY - 4][gridX / 3 - 4] && board[gridY - 1][gridX / 3 - 1] == 0) && !(board[gridY - 5][gridX / 3 - 5] * board[gridY + 1][gridX / 3 + 1] == 4) ||
		(27 == board[gridY - 1][gridX / 3 - 1] * board[gridY - 3][gridX / 3 - 3] * board[gridY - 4][gridX / 3 - 4] && board[gridY - 2][gridX / 3 - 2] == 0) && !(board[gridY - 5][gridX / 3 - 5] * board[gridY + 1][gridX / 3 + 1] == 4) ||
		(27 == board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 4][gridX / 3 - 4] && board[gridY - 3][gridX / 3 - 3] == 0) && !(board[gridY - 5][gridX / 3 - 5] * board[gridY + 1][gridX / 3 + 1] == 4) ||
		(27 == board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3]) && !(board[gridY - 4][gridX / 3 - 4] * board[gridY + 1][gridX / 3 + 1] == 4) ||

		(27 == board[gridY - 1][gridX / 3 - 1] * board[gridY + 2][gridX / 3 + 2] * board[gridY + 3][gridX / 3 + 3] && board[gridY + 1][gridX / 3 + 1] == 0) && !(board[gridY - 2][gridX / 3 - 2] * board[gridY + 4][gridX / 3 + 4] == 4) ||
		(27 == board[gridY - 1][gridX / 3 - 1] * board[gridY + 1][gridX / 3 + 1] * board[gridY + 3][gridX / 3 + 3] && board[gridY + 2][gridX / 3 + 2] == 0) && !(board[gridY - 2][gridX / 3 - 2] * board[gridY + 4][gridX / 3 + 4] == 4) ||
		(27 == board[gridY - 1][gridX / 3 - 1] * board[gridY + 1][gridX / 3 + 1] * board[gridY + 2][gridX / 3 + 2]) && !(board[gridY - 2][gridX / 3 - 2] * board[gridY + 3][gridX / 3 + 3] == 4) ||
		(27 == board[gridY + 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] && board[gridY - 1][gridX / 3 - 1] == 0) && !(board[gridY + 2][gridX / 3 + 2] * board[gridY - 4][gridX / 3 - 4] == 4) ||
		(27 == board[gridY + 1][gridX / 3 + 1] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 3][gridX / 3 - 3] && board[gridY - 2][gridX / 3 - 2] == 0) && !(board[gridY + 2][gridX / 3 + 2] * board[gridY - 4][gridX / 3 - 4] == 4) ||
		(27 == board[gridY + 1][gridX / 3 + 1] * board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2]) && !(board[gridY + 2][gridX / 3 + 2] * board[gridY - 4][gridX / 3 - 4] == 4) ||

		(27 == board[gridY + 1][gridX / 3 + 1] * board[gridY + 2][gridX / 3 + 2] * board[gridY - 2][gridX / 3 - 2] && board[gridY - 1][gridX / 3 - 1] == 0) && !(board[gridY + 3][gridX / 3 + 3] * board[gridY - 3][gridX / 3 - 3] == 4) ||
		(27 == board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] * board[gridY + 2][gridX / 3 + 2] && board[gridY + 1][gridX / 3 + 1] == 0) && !(board[gridY + 3][gridX / 3 + 3] * board[gridY - 3][gridX / 3 - 3] == 4)) {
		cnt++;
	}

	return cnt;
}
int checkSam(int gridX, int gridY)
{
	int cnt = 0;
	if (gridX / 3 - 4 < 0 || gridX / 3 + 4 > 15 || gridY < 0 || gridY > 15)
		return 0;

	if ((board[gridY - 1][gridX / 3] * board[gridY - 2][gridX / 3] == 9 && board[gridY - 3][gridX / 3] == 0 && board[gridY + 1][gridX / 3] == 0) ||
		(board[gridY - 2][gridX / 3] * board[gridY - 3][gridX / 3] == 9 && board[gridY - 4][gridX / 3] == 0 && board[gridY + 1][gridX / 3] == 0 && board[gridY - 1][gridX / 3] == 0) ||
		(board[gridY - 1][gridX / 3] * board[gridY - 3][gridX / 3] == 9 && board[gridY - 4][gridX / 3] == 0 && board[gridY + 1][gridX / 3] == 0 && board[gridY - 2][gridX / 3] == 0) ||

		(board[gridY + 1][gridX / 3] * board[gridY + 2][gridX / 3] == 9 && board[gridY + 3][gridX / 3] == 0 && board[gridY - 1][gridX / 3] == 0) ||
		(board[gridY + 2][gridX / 3] * board[gridY + 3][gridX / 3] == 9 && board[gridY + 4][gridX / 3] == 0 && board[gridY - 1][gridX / 3] == 0 && board[gridY + 1][gridX / 3] == 0) ||
		(board[gridY + 1][gridX / 3] * board[gridY + 3][gridX / 3] == 9 && board[gridY + 4][gridX / 3] == 0 && board[gridY - 1][gridX / 3] == 0 && board[gridY + 2][gridX / 3] == 0) ||

		(board[gridY + 1][gridX / 3] * board[gridY - 1][gridX / 3] == 9 && board[gridY + 2][gridX / 3] == 0 && board[gridY - 2][gridX / 3] == 0) ||
		(board[gridY - 2][gridX / 3] * board[gridY + 1][gridX / 3] == 9 && board[gridY - 1][gridX / 3] == 0 && board[gridY + 2][gridX / 3] == 0 && board[gridY - 3][gridX / 3] == 0) ||
		(board[gridY - 1][gridX / 3] * board[gridY + 2][gridX / 3] == 9 && board[gridY + 1][gridX / 3] == 0 && board[gridY + 3][gridX / 3] == 0 && board[gridY - 2][gridX / 3] == 0)
		) {
		cnt++;
	}		//세로에 3이있는지
	if ((board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 2] == 9 && board[gridY][gridX / 3 + 3] == 0 && board[gridY][gridX / 3 - 1] == 0) ||
		(board[gridY][gridX / 3 + 2] * board[gridY][gridX / 3 + 3] == 9 && board[gridY][gridX / 3 - 1] == 0 && board[gridY][gridX / 3 + 1] == 0 && board[gridY][gridX / 3 + 4] == 0) ||
		(board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 + 3] == 9 && board[gridY][gridX / 3 - 1] == 0 && board[gridY][gridX / 3 + 2] == 0 && board[gridY][gridX / 3 + 4] == 0) ||

		(board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 2] == 9 && board[gridY][gridX / 3 - 3] == 0 && board[gridY][gridX / 3 + 1] == 0) ||
		(board[gridY][gridX / 3 - 2] * board[gridY][gridX / 3 - 3] == 9 && board[gridY][gridX / 3 + 1] == 0 && board[gridY][gridX / 3 - 1] == 0 && board[gridY][gridX / 3 - 4] == 0) ||
		(board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 - 3] == 9 && board[gridY][gridX / 3 + 1] == 0 && board[gridY][gridX / 3 - 2] == 0 && board[gridY][gridX / 3 - 4] == 0) ||

		(board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 1] == 9 && board[gridY][gridX / 3 + 2] == 0 && board[gridY][gridX / 3 - 2] == 0) ||
		(board[gridY][gridX / 3 + 1] * board[gridY][gridX / 3 - 2] == 9 && board[gridY][gridX / 3 + 2] == 0 && board[gridY][gridX / 3 - 1] == 0 && board[gridY][gridX / 3 - 3] == 0) ||
		(board[gridY][gridX / 3 - 1] * board[gridY][gridX / 3 + 2] == 9 && board[gridY][gridX / 3 - 2] == 0 && board[gridY][gridX / 3 + 1] == 0 && board[gridY][gridX / 3 + 3] == 0)
		) {
		cnt++;
	}		//가로에 3이있는지
	if ((board[gridY - 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 + 2] == 9 && board[gridY - 3][gridX / 3 + 3] == 0 && board[gridY + 1][gridX / 3 - 1] == 0) ||
		(board[gridY - 2][gridX / 3 + 2] * board[gridY - 3][gridX / 3 + 3] == 9 && board[gridY + 1][gridX / 3 - 1] == 0 && board[gridY - 1][gridX / 3 + 1] == 0 && board[gridY - 4][gridX / 3 + 4] == 0) ||
		(board[gridY - 1][gridX / 3 + 1] * board[gridY - 3][gridX / 3 + 3] == 9 && board[gridY + 1][gridX / 3 - 1] == 0 && board[gridY - 2][gridX / 3 + 2] == 0 && board[gridY - 4][gridX / 3 + 4] == 0) ||

		(board[gridY + 1][gridX / 3 - 1] * board[gridY + 2][gridX / 3 - 2] == 9 && board[gridY + 3][gridX / 3 - 3] == 0 && board[gridY - 1][gridX / 3 + 1] == 0) ||
		(board[gridY + 2][gridX / 3 - 2] * board[gridY + 3][gridX / 3 - 3] == 9 && board[gridY - 1][gridX / 3 + 1] == 0 && board[gridY + 1][gridX / 3 - 1] == 0 && board[gridY + 4][gridX / 3 - 4] == 0) ||
		(board[gridY + 1][gridX / 3 - 1] * board[gridY + 3][gridX / 3 - 3] == 9 && board[gridY - 1][gridX / 3 + 1] == 0 && board[gridY + 2][gridX / 3 - 2] == 0 && board[gridY + 4][gridX / 3 - 4] == 0) ||

		(board[gridY + 1][gridX / 3 - 1] * board[gridY - 1][gridX / 3 + 1] == 9 && board[gridY + 2][gridX / 3 - 2] == 0 && board[gridY - 2][gridX / 3 + 2] == 0) ||
		(board[gridY + 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 + 2] == 9 && board[gridY + 2][gridX / 3 - 2] == 0 && board[gridY - 1][gridX / 3 + 1] == 0 && board[gridY - 3][gridX / 3 + 3] == 0) ||
		(board[gridY + 2][gridX / 3 - 2] * board[gridY - 1][gridX / 3 + 1] == 9 && board[gridY + 3][gridX / 3 - 3] == 0 && board[gridY + 1][gridX / 3 - 1] == 0 && board[gridY - 2][gridX / 3 + 2] == 0)
		) {
		cnt++;
	}		//우상향대각에 3이있는지
	if ((board[gridY + 1][gridX / 3 + 1] * board[gridY + 2][gridX / 3 + 2] == 9 && board[gridY + 3][gridX / 3 + 3] == 0 && board[gridY - 1][gridX / 3 - 1] == 0) ||
		(board[gridY + 2][gridX / 3 + 2] * board[gridY + 3][gridX / 3 + 3] == 9 && board[gridY - 1][gridX / 3 - 1] == 0 && board[gridY + 1][gridX / 3 + 1] == 0 && board[gridY + 4][gridX / 3 + 4] == 0) ||
		(board[gridY + 1][gridX / 3 + 1] * board[gridY + 3][gridX / 3 + 3] == 9 && board[gridY - 1][gridX / 3 - 1] == 0 && board[gridY + 2][gridX / 3 + 2] == 0 && board[gridY + 4][gridX / 3 + 4] == 0) ||

		(board[gridY - 1][gridX / 3 - 1] * board[gridY - 2][gridX / 3 - 2] == 9 && board[gridY - 3][gridX / 3 - 3] == 0 && board[gridY + 1][gridX / 3 + 1] == 0) ||
		(board[gridY - 2][gridX / 3 - 2] * board[gridY - 3][gridX / 3 - 3] == 9 && board[gridY + 1][gridX / 3 + 1] == 0 && board[gridY - 1][gridX / 3 - 1] == 0 && board[gridY - 4][gridX / 3 - 4] == 0) ||
		(board[gridY - 1][gridX / 3 - 1] * board[gridY - 3][gridX / 3 - 3] == 9 && board[gridY + 1][gridX / 3 + 1] == 0 && board[gridY + 2][gridX / 3 + 2] == 0 && board[gridY - 4][gridX / 3 - 4] == 0) ||

		(board[gridY + 1][gridX / 3 + 1] * board[gridY - 1][gridX / 3 - 1] == 9 && board[gridY + 2][gridX / 3 + 2] == 0 && board[gridY - 2][gridX / 3 - 2] == 0) ||
		(board[gridY + 2][gridX / 3 + 2] * board[gridY - 1][gridX / 3 - 1] == 9 && board[gridY + 1][gridX / 3 + 1] == 0 && board[gridY - 2][gridX / 3 - 2] == 0 && board[gridY + 3][gridX / 3 + 3] == 0) ||
		(board[gridY + 1][gridX / 3 + 1] * board[gridY - 2][gridX / 3 - 2] == 9 && board[gridY - 1][gridX / 3 - 1] == 0 && board[gridY - 3][gridX / 3 - 3] == 0 && board[gridY + 2][gridX / 3 + 2] == 0)
		) {
		cnt++;
	}		//좌상향대각에 3이있는지

	if (cnt >= 2) {
		board[gridY][gridX / 3] = 3;
		if (checkInterrupt(board) == 1) {
			return 1;
		}
	}
	board[gridY][gridX / 3] = 0;

	return cnt;
}
int checkInterrupt()
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