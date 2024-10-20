#include <string.h>

float convertPtrCharToFloat(char* line) {
	int lengthLine = (int)strlen(line), number = 0, _char = 0;
	while (line[_char] != '\0' && line[_char] != ',')
		number = number * 10 + line[_char++] - '0';
	_char++;
	int numberRemainder = 0, discharge = 1;
	while (line[_char] != '\0' && _char < lengthLine)
		numberRemainder = numberRemainder * 10 + line[_char++] - '0', discharge *= 10;
	return (float)number + (float)numberRemainder / discharge;
}