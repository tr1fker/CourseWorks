#include <stdio.h>
#include <malloc.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/convert.h"
#include "../../include/functions.h"
#include "../../include/output.h"

void blockUser(int currentId) {
	clearConsole();
	printf("������� �� ������������:");
	char* inputId = getPressedCharacters(LENGTHID);
	int id = convertPtrCharToInteger(inputId);
	if (inputId)
		free(inputId);
	if (id == currentId) {
		printf("\n�� ����� ���� ��!\n");
	}
	else {
		struct User* arrayUsers = NULL;
		int countUsers = 0;
		if (inputFileUsers(&arrayUsers, &countUsers)) {
			for (int _user = 0; _user < countUsers; _user++)
				if (arrayUsers[_user].id == id) {
					if (arrayUsers[_user].privilege == 1 && currentId != 0) {
						printf("\n�� �� ������ ����������� ���������������!\n");
					}
					else {
						if (arrayUsers[_user].blocked) {
							arrayUsers[_user].blocked = 0;
							printf("\n�����������[Enter], �����[����� ������ �������].\n");
							if (getPressedCharacter() == 13)
								printf("\n������������ ������� �������������!\n");
							else
								printf("\n������������ �� ��� �������������!\n");
						}
						else {
							arrayUsers[_user].blocked = 1;
							printf("\n�����������[Enter], �����[����� ������ �������].\n");
							if (getPressedCharacter() == 13)
								printf("\n������������ ������� ������������!\n");
							else
								printf("\n������������ �� ��� ������������!\n");
						}
						saveFileUsers(&arrayUsers, &countUsers);
					}
					break;
				}else if (_user + 1 == countUsers)
					printf("\n������������ �� ������!\n");
		}
		if (arrayUsers)
			free(arrayUsers);
	}
	pressAnyButton();
}