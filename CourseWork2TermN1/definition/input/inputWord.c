#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>


#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/functions.h"
#include "../../include/convert.h"

char* inputWord(int limit) {
	char* line;
	if (line = (char*)malloc(sizeof(char) * (limit + 1))) {
		int lengthLine = 0;
		while (1) {
			int code = getPressedCharacter();
			if (code == 8 && lengthLine) {
				line[--lengthLine] = '\0';
				printf("\b \b");
			}
			else if (code == 13) {
				return line;
			}
			else if (lengthLine < limit && (code >= 'A' && code <= 'Z' || code >= 'a' && code <= 'z')) {
					line[lengthLine++] = (char)code;
					line[lengthLine] = '\0';
					printf("%c", (char)code);
			}
		}
	}
	clearConsole();
	printf_s("\nНе удалось выделить память в inputCapitalizedWord!\n");
	pressAnyButton();
	return NULL;
}