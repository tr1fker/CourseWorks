#include <string.h>

int convertPtrCharToInteger(char* line) {
	int lengthLine = strlen(line), negative = line[0] == '-' ? 1 : 0, number = 0;
	for (int _char = negative; _char < lengthLine; _char++)
		number = number * 10 + line[_char] - '0';
	return negative ? -number : number;
}