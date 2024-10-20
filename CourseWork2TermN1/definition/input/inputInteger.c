#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/functions.h"
#include "../../include/convert.h"

int inputInteger(int SIGN) {
	char* line;
	if (line = (char*)malloc(sizeof(char) * ((SIGN ? LENGTHMININT : LENGTHMAXINT) + 1))) {
		int lengthLine = 0;
		while (1) {
			int code = getPressedCharacter();
			if (code == 8 && lengthLine) {
				line[--lengthLine] = '\0';
				printf("\b \b");
			}
			else if ((code == '-' && !lengthLine && !SIGN) || (code >= '0' && code <= '9' && lengthLine < (!SIGN ? LENGTHMININT : LENGTHMAXINT))) {
				line[lengthLine++] = (char)code;
				line[lengthLine] = '\0';
				printf("%c", (char)code);
			}
			else if (code == 13) {
				return convertPtrCharToInteger(line);
			}
		}
	}
	clearConsole();
	printf_s("\nНе удалось выделить память в inputInteger!\n");
	pressAnyButton();
	return 0;
}