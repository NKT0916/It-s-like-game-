#include <stdio.h>
#include <time.h>
#include <stdlib.h>

extern int Map[60][40], Plane[2][14];

void GameSetting()
{
	srand((unsigned)time(NULL));
	system("mode con cols=80 lines=70");

	int i, j;

	for (i = 0; i < 60; i++)
	{
		for (j = 0; j < 40; j++)
		{
			if (i > 0 && i < 59 && j>0 && j < 39)
				Map[i][j] = 0;
			else
				Map[i][j] = 3;
		}
	}
	for (i = 0; i < 16; i++)
		Map[Plane[1][i]][Plane[0][i]] = 1;
}
