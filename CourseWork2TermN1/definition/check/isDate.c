#include <string.h>

static int daysOfMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isDate(char* line) {
	int lengthLine = (int)strlen(line);
	int day = 0, _char = 0;
	if (_char >= lengthLine)
		return 0;
	while (_char < lengthLine) {
		if (line[_char] >= '0' && line[_char] <= '9')
			day = day * 10 + line[_char] - '0';
		else if (line[_char] == '.')
			break;
		else
			return 0;
		_char++;
	}
	_char++;
	if (_char >= lengthLine)
		return 0;
	int month = 0;
	while (_char < lengthLine) {
		if (line[_char] >= '0' && line[_char] <= '9')
			month = month * 10 + line[_char] - '0';
		else if (line[_char] == '.')
			break;
		else
			return 0;
		_char++;
	}
	_char++;
	if (_char >= lengthLine)
		return 0;
	int year = 0;
	while (_char < lengthLine) {
		if (line[_char] >= '0' && line[_char] <= '9')
			year = year * 10 + line[_char] - '0';
		else if (line[_char] == '.' || line[_char] == '\0')
			break;
		else
			return 0;
		_char++;
	}
	if (month > 12 || !month || daysOfMonth[month - 1] < day)
		return 0;
	return 1;
}