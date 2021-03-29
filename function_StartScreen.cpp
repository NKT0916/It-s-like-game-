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

		puts("\n     ┌────────────────────────────────────────────────────┐");
		puts("     │ ┏━━━┳┓ ┏┳━━━┳━━━┳━━━━┓  ┏━━┓┏┓ ┏┳┓  ┏┓  ┏━━━┳━━━━┓ │");
		puts("     │ ┃┏━┓┃┃ ┃┃┏━┓┃┏━┓┃┏┓┏┓┃  ┃┏┓┃┃┃ ┃┃┃  ┃┃  ┃┏━━┫┏┓┏┓┃ │");
		puts("     │ ┃┗━━┫┗━┛┃┃ ┃┃┃ ┃┣┛┃┃┗┛  ┃┗┛┗┫┃ ┃┃┃  ┃┃  ┃┗━━╋┛┃┃┗┛ │");
		puts("     │ ┗━━┓┃┏━┓┃┃ ┃┃┃ ┃┃ ┃┃    ┃┏━┓┃┃ ┃┃┃ ┏┫┃ ┏┫┏━━┛ ┃┃   │");
		puts("     │ ┃┗━┛┃┃ ┃┃┗━┛┃┗━┛┃ ┃┃    ┃┗━┛┃┗━┛┃┗━┛┃┗━┛┃┗━━┓ ┃┃   │");
		puts("     │ ┗━━━┻┛ ┗┻━━━┻━━━┛ ┗┛    ┗━━━┻━━━┻━━━┻━━━┻━━━┛ ┗┛   │");
		puts("     └────────────────────────────────────────────────────┘");

		printf_s("\n\n\n\n%39s", "Press Any Key");

		if (_kbhit())
		{
			key = _getch();
			key = '\0';
			break;
		}

	}
	Sleep(100);
}
