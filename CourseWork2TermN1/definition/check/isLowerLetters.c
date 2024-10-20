#include <string.h>

int isLowerLetters(char* line) {
	int lengthLine = strlen(line);
	for (int _char = 0; _char < lengthLine; _char++)
		if (!(line[_char] >= 'a' && line[_char] <= 'z' || line[_char] >= 'à' && line[_char] <= 'ÿ'))
			return 0;
	return 1;
}