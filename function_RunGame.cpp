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

extern int Plane[2][14], Map[60][40], Enemy[3][5], Bullet_Start_Path[2], key, Enemy_Spawn, score;

extern void Clear_Consol();

void ExitTheGame()
{
	Clear_Consol();

	system("mode con cols=35 lines=20");
	while (1)
	{
		Clear_Consol();

		puts("          ┏━━━┳━┓ ┏┳━━━┓");
		puts("          ┃┏━━┫┃┗┓┃┣┓┏┓┃");
		puts("          ┃┗━━┫┏┓┗┛┃┃┃┃┃");
		puts("          ┃┏━━┫┃┗┓┃┃┃┃┃┃");
		puts("          ┃┗━━┫┃ ┃┃┣┛┗┛┃");
		puts("          ┗━━━┻┛ ┗━┻━━━┛");
		puts("   ┌──────────────────────────┐");
		printf_s("   │         SCORE : %d        │\n", score);
		puts("   └──────────────────────────┘");

		puts("\n한 번 더 누르면 게임이 종료됩니다..");

		Sleep(200);

		if (_kbhit())
		{
			key = _getch();
			key = '\0';
			break;
		}
	}

	system("cls");

	puts("          ┏━━━┳━┓ ┏┳━━━┓");
	puts("          ┃┏━━┫┃┗┓┃┣┓┏┓┃");
	puts("          ┃┗━━┫┏┓┗┛┃┃┃┃┃");
	puts("          ┃┏━━┫┃┗┓┃┃┃┃┃┃");
	puts("          ┃┗━━┫┃ ┃┃┣┛┗┛┃");
	puts("          ┗━━━┻┛ ┗━┻━━━┛");
	puts("   ┌──────────────────────────┐");
	printf_s("   │         SCORE : %d        │\n", score);
	puts("   └──────────────────────────┘");

	exit(0);
}

void RunGame_SetEnemy()
{
	int i, j, Enemy_StartPath_Y = 0, basket_RunGame_SetEnemy/*Enemy_StartPath_X = 0,*/;

	Enemy_StartPath_Y = rand() % (36 + 1 - 3) + 3;
	//Enemy_StartPath_X = rand() % 52 + 1;
	
	Enemy_Spawn++;
	
	if (Enemy_Spawn == 15)
	{
		Enemy_Spawn = 0;
		Map[1][Enemy_StartPath_Y] = 4;
	}

	for (i = 60 - 1; i >= 0; i--)
	{
		for (j = 40 - 1; j >= 0; j--)
		{
			if (Map[i][j] == 4)
			{
				if (Map[i + 1][j] == 1 && i <= 55)
					ExitTheGame();
				else if (Map[i + 1][j] == 3 || Map[i + 1][j] == 2)
				{
					Map[i][j] = 0;

					if (Map[i + 1][j] == 2)
					{
						Map[i + 1][j] = 0;
						score++;
					}
					break;
				}
				else {
						basket_RunGame_SetEnemy = Map[i][j];
						Map[i][j] = Map[i + 1][j];
						Map[i + 1][j] = basket_RunGame_SetEnemy;
				}
			}
		}
	}
}

void RunGame_Draw()
{
	Clear_Consol();

	int i, j, basket_Draw;

	printf_s("SCORE = %d\n", score);

	for (i = 0; i < 60; i++)
	{
		for (j = 0; j < 40; j++)
		{
			switch (Map[i][j])
			{
			case 0:
				printf_s("ㅤ");
				break;
			case 1:
				if (i < 3 && j == 15)
				{
					Map[i][j] = 0;
					printf_s("ㅤ");
					break;
				}
				printf_s("■");
				break;
			case 2:
				printf_s("◈");
				if (Map[i - 1][j] == 3 || Map[i - 1][j] == 5)
				{
					if (Map[i - 1][j] == 5)
					{
						Map[i - 1][j] = 0;
					}
					Map[i][j] = 0;
					break;
				}
				else {
						basket_Draw = Map[i][j];
						Map[i][j] = Map[i - 1][j];
						Map[i - 1][j] = basket_Draw;
				}
				break;
			case 3:
				printf_s("□");
				break;
			case 4:
				printf_s("●");
			default:
				break;
			}
		}
		printf_s("\n");
	}
	puts("강제종료하려면 ENTER를...");
}

void RunGameGetkey_moveblock(int Direction, int change_X_path, int plus_or_minus)
{
	int i, temp;

	if (Direction == 0)
	{
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
	}
	else {
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
	}
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
