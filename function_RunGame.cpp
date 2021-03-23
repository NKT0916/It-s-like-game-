#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

#define U 72
#define D 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13

extern int Plane[2][14], Map[60][40], Bullet_Start_Path[2], key, Enemy_Spawn, score, Move;

extern void Clear_Consol();

void RunGame_SetEnemy()
{
	int i, j, Enemy_StartPath_Y = 0, Enemy_StartPath_X = 0, check = 0;

	Enemy_StartPath_Y = rand() % 38 + 1;
	Enemy_StartPath_X = rand() % 52 + 1;

}

void RunGame_Draw()
{
	Clear_Consol();

	int i, j, basket_Draw;

	printf("STAGE\n");

	for (i = 0; i < 60; i++)
	{
		for (j = 0; j < 40; j++)
		{
			switch (Map[i][j])
			{
			case 0:
				printf("ㅤ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("◈");
				if (Map[i - 1][j] == 3 || Map[i - 1][j] == 4)
				{
					Map[i][j] = 0;
					break;
				}
				else {
					if (Map[i - 1][j] == 5)
					{
						basket_Draw = Map[i][j];
						Map[i][j] = Map[i - 2][j];
						Map[i - 2][j] = basket_Draw;
					}
					else {
						basket_Draw = Map[i][j];
						Map[i][j] = Map[i - 1][j];
						Map[i - 1][j] = basket_Draw;
					}
				}
				break;
			case 3:
				printf("□");
				break;
			case 4:
				printf("●");
				if (i == 48 || Map[i + 1][j] == 2)
				{
					Map[i][j] = 0;
					break;
				}
				else {
					//if (Move == 10)
					//{
					basket_Draw = Map[i][j];
					Map[i][j] = Map[i + 1][j];
					Map[i + 1][j] = basket_Draw;
					//}
				}
				break;
			default:
				break;
			}
		}
		printf("\n");
		//	Move++;
	}
	//Move++;
	//if (Move == 10)
		//Move = 0;
	//Enemy_Spawn++;
	printf("SCORE = %d %70s", score, "강제종료하려면 ENTER를...");
}

void RunGameGetkey_moveblock(int Direction, int change_X_path, int plus_or_minus)
{
	int i, temp;

	switch (Direction)
	{
	case 0:
		for (i = 0; i < 14; i++)
		{
			Map[Plane[1][i]][Plane[0][i]] = 1;

			temp = Map[Plane[1][i]][Plane[0][i]];
			Map[Plane[1][i]][Plane[0][i]] = Map[Plane[1][i]][Plane[0][i] + change_X_path];
			Map[Plane[1][i]][Plane[0][i] + change_X_path] = temp;

			if (plus_or_minus == 0)
				Plane[0][i]++;
			else
				Plane[0][i]--;
		}
		break;
	case 1:
		for (i = 13; i >= 0; i--)
		{
			Map[Plane[1][i]][Plane[0][i]] = 1;

			temp = Map[Plane[1][i]][Plane[0][i]];
			Map[Plane[1][i]][Plane[0][i]] = Map[Plane[1][i]][Plane[0][i] + change_X_path];
			Map[Plane[1][i]][Plane[0][i] + change_X_path] = temp;

			if (plus_or_minus == 0)
				Plane[0][i]++;
			else
				Plane[0][i]--;
		}
		break;
	}
}

void ExitTheGame()
{
	Sleep(100);
	Clear_Consol();

	system("mode con cols=35 lines=18");
	printf("         ┏━━━┳━┓  ┏┳━━━┓\n");
	printf("         ┃┏━━┫┃┗┓┃┣┓┏┓┃\n");
	printf("         ┃┗━━┫┏┓┗┛┃┃┃┃┃\n");
	printf("         ┃┏━━┫┃┗┓┃┃┃┃┃┃\n");
	printf("         ┃┗━━┫┃  ┃┃┣┛┗┛┃\n");
	printf("         ┗━━━┻┛  ┗━┻━━━┛\n");
	printf("   ----------------------------\n");
	printf("   |       SCORE : %d          |\n", score);
	printf("   ----------------------------\n");

	exit(0);
}

void RunGame_Getkey()
{
	if (_kbhit())
	{
		key = _getch();

		switch (key)
		{
		case LEFT:
			if (Plane[0][3] != 2 && Plane[0][0] != 2 && Map[Plane[1][5] - 1][Plane[0][0] + 1] != 2)
				RunGameGetkey_moveblock(0, -1, 1);
			break;
		case RIGHT:
			if (Plane[0][6] != 38 && Map[Plane[1][4] - 1][Plane[0][0] + 1] != 2)
				RunGameGetkey_moveblock(1, 1, 0);
			break;
		case SPACE:
			if (Map[Plane[1][4] - 1][Plane[0][0] + 1] != 2)
			{
				Bullet_Start_Path[0] = Plane[1][4] - 1;
				Bullet_Start_Path[1] = Plane[0][0] + 1;
				Map[Bullet_Start_Path[0]][Bullet_Start_Path[1]] = 2;
			}
			break;
		case ENTER:
			ExitTheGame();
		default:
			break;
		}
	}
}

void RunGame()
{
	while (1)
	{
		RunGame_SetEnemy();
		RunGame_Draw();
		RunGame_Getkey();
	}
}