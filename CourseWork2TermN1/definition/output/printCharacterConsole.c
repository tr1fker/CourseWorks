#include <stdio.h>


void printCharacterNConsole(char character, int number) {
	for (int _char = 0; _char < number; _char++)
		printf("%c", character);
	return;
}

void printCharacterConsole(char character) {
	printf("%c", character);
}