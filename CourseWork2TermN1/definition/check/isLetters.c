
#include <string.h>

int isLetters(char* line) {
	int lengthLine = strlen(line);
	for (int _char = 0; _char < lengthLine; _char++)
		if (!(line[_char] >= 'a' && line[_char] <= 'z' || line[_char] >= 'A' && line[_char] <= 'Z'))
			return 0;
	return 1;
}