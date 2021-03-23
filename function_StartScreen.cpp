#include <stdio.h>
#include <Windows.h>
#include <conio.h>

extern int key;

extern void Clear_Consol();
extern void HideTypingCusor(bool show);

void StartScreen()
{
	HideTypingCusor(false);
	system("mode con cols=65 lines=20");

	while (1)
	{
		Clear_Consol();

		printf("\n     忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("     弛 旨收收收有旬 旨有收收收有收收收有收收收收旬  旨收收旬旨旬 旨有旬  旨旬  旨收收收有收收收收旬 弛\n");
		printf("     弛 早旨收旬早早 早早旨收旬早旨收旬早旨旬旨旬早  早旨旬早早早 早早早  早早  早旨收收朽旨旬旨旬早 弛\n");
		printf("     弛 早曲收收朽曲收旭早早 早早早 早曳旭早早曲旭  早曲旭曲朽早 早早早  早早  早曲收收朱旭早早曲旭 弛\n");
		printf("     弛 曲收收旬早旨收旬早早 早早早 早早 早早    早旨收旬早早 早早早 旨朽早 旨朽旨收收旭 早早   弛\n");
		printf("     弛 早曲收旭早早 早早曲收旭早曲收旭早 早早    早曲收旭早曲收旭早曲收旭早曲收旭早曲收收旬 早早   弛\n");
		printf("     弛 曲收收收朴旭 曲朴收收收朴收收收旭 曲旭    曲收收收朴收收收朴收收收朴收收收朴收收收旭 曲旭   弛\n");
		printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

		printf("\n\n\n\n%39s", "Press Any Key");

		if (_kbhit())
		{
			key = _getch();
			key = '\0';
			break;
		}

	}
	Sleep(100);
}