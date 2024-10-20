#include <string.h>

int isTime(char* line) {
	int lengthLine = strlen(line);
	int hours = 0, _char = 0;
	if (_char >= lengthLine)
		return 0;
	while (_char < lengthLine) {
		if (line[_char] >= '0' && line[_char] <= '9')
			hours = hours * 10 + line[_char] - '0';
		else if (line[_char] == ':')
			break;
		else
			return 0;
		_char++;
	}
	_char++;
	if (_char >= lengthLine || hours > 23)
		return 0;
	int minutes = 0;
	while (_char < lengthLine) {
		if (line[_char] >= '0' && line[_char] <= '9')
			minutes = minutes * 10 + line[_char] - '0';
		else if (line[_char] == ':')
			break;
		else
			return 0;
		_char++;
	}
	_char++;
	if (_char >= lengthLine || minutes > 59)
		return 0;
	int seconds = 0;
	while (_char < lengthLine) {
		if (line[_char] >= '0' && line[_char] <= '9')
			seconds = seconds * 10 + line[_char] - '0';
		else if (line[_char] == ':')
			break;
		else
			return 0;
		_char++;
	}
	if (seconds > 59)
		return 0;
	return 1;
}