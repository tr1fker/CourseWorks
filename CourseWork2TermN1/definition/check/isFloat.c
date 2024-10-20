#include <string.h>

int isFloat(char* line) {
	int countPoints = 0, lengthLine = strlen(line);
	for (int _char = 0; _char < lengthLine; _char++)
		if (line[_char] == ',') {
			if (countPoints)
				return 0;
			countPoints++;
		}
		else if (line[_char] < '0' || line[_char] > '9')
			return 0;
	return 1;
}