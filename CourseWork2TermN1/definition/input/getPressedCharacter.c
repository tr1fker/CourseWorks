#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include <stdio.h>

int getPressedCharacter() {
	int code = _getch();
	if (_kbhit())
		code = _getch();
	return code;
}

char* getPressedCharacters(int number) {
	char* line;
	if (!(line = (char*)malloc(sizeof(char) * (number + 1)))) {
		printf_s("Память не была выделена в getPressedCharacters!");
		exit(1);
	}
	else {
		line[0] = '\0';
		int counter = 0, code = 0;
		while (code != 13) {
			code = _getch();
			if (_kbhit())
				code = _getch();
			if ((code >= 'a' && code <= 'z' || code >= 'A' && code <= 'Z' || code >= '0' && code <= '9' || code == '.' || code == ':' || code == ',') && counter < number) {
				line[counter++] = (char)code;
				line[counter] = '\0';
				printf_s("%c", code);
			}
			else if (code == 8) {
				if (counter) {
					line[--counter] = '\0';
					printf_s("\b \b");
				}
			}
		}
		return line;
	}
	return 0;
}