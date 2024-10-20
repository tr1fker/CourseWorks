#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../include/functions.h"


char* convertFloatToPtrChar(float number) {
	int lengthDigit = getLengthInteger((int)number);
	char* line = (char*)malloc(sizeof(char) * (lengthDigit + 6));
	if (line) {
		line[lengthDigit + 5] = '\0';
		int discharge = 1;
		for (int _char = 0; _char < lengthDigit; _char++)
			line[lengthDigit - _char - 1] = (int)(number / discharge) % 10 + '0', discharge *= 10;
		discharge = 10;
		line[lengthDigit] = ',';
		for (int _char = 0; _char < 4; _char++)
			line[lengthDigit + _char + 1] = ((int)(number * discharge)) % 10 + '0', discharge *= 10;
		return line;
	}
	clearConsole();
	printf("Не удалось выделить память в convertFloatToPtrChar()!\n");
	pressAnyButton();
	return NULL;
}