#include <malloc.h>
#include <stdio.h>

#include "../../include/functions.h"

char* convertIntegerToPtrChar(int number) {
	int lengthNumber = getLengthInteger(number), discharge = 1;
	char* line = (char*)malloc(sizeof(char) * (lengthNumber + 1));
	if (line) {
		line[lengthNumber] = '\0';
		while (lengthNumber--) {
			line[lengthNumber] = (number / discharge) % 10 + '0';
			discharge *= 10;
		}
		return line;
	}
	clearConsole();
	printf("Не удалось выделить память в convertIntegerToPtrChar!\n");
	pressAnyButton();
	return NULL;
}