#include <string.h>

int isDigit(char* line) {
	int lengthLine = strlen(line);
	for (int _char = line[0] == '-' ? 1 : 0; _char < lengthLine; _char++)
		if (line[_char] < '0' || line[_char] > '9')
			return 0;
	return 1;
}