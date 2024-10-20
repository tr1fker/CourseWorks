#include "../../include/check.h"

int isCapitalizedWord(char* line) {
	if (line[0] == '\0') {
		return 0;
	}
	else if (line[0] >= 'A' && line[0] <= 'Z' && isLowerLetters(line + 1)) {
		return 1;
	}
	return 0;
}