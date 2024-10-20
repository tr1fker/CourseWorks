
#include <stdio.h>

void printFromIndexLineNCharacters(char* line, int number, int index) {
	while (number-- && line[index] != '\0')
		printf("%c", line[index++]);
	return;
}