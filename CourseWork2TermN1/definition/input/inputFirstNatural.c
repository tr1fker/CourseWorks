#include <malloc.h>
#include <stdio.h>

#include "../../include/constants.h"
#include "../../include/input.h"
#include "../../include/functions.h"
#include "../../include/convert.h"
#include "../../include/check.h"


int inputFirstNatural(int limit, char* condition) {
	char* line;
	if (!(line = (char*)malloc(sizeof(char) * (LENGTHMAXINT + 1)))) {
		printf_s("Память не была выделена в inputFirstNatural!");
		return 0;
	}
	else {
		int counter = 0, number = 1;
		line[0] = '\0';
		do {
			clearConsole();
			printf_s("%s%s", condition, line);
			line[0] = '\0';
			if (number != 1) {
				printf_s("\nНекорретное значение!\n");
				pressAnyButton();
				number = 1;
			}
			else {
				counter = 0;
				line[0] = '\0';
				int code = 0;
				while (code != 13) {
					code = getPressedCharacter();
					if (code >= '0' && code <= '9' && counter != LENGTHMAXINT) {
						line[counter++] = code;
						printf_s("%c", code);
						line[counter] = '\0';
					}
					else if (code == 8) {
						if (counter) {
							line[--counter] = '\0';
							printf_s("\b \b");
						}
					}
				}
				number = 0;
				if (isDigit(line)) {
					number = convertPtrCharToInteger(line);
				}
				if (!(number < 1 || number > limit)) {
					free(line);
					return number;
				}
			}
		} while (1);
	}
	return 0;
}