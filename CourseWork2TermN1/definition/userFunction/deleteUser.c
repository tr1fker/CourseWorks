#include <stdio.h>
#include <malloc.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/convert.h"
#include "../../include/functions.h"
#include "../../include/output.h"

void deleteUser(int currentId) {
	clearConsole();
	printf("������� �� ������������:");
	int id = inputInteger(POSITIVE);
	if (id == currentId) {
		printf("\n�� ����� ���� ��!\n");
	}
	else {
		struct User* arrayUsers = NULL;
		int countUsers = 0;
		if (inputFileUsers(&arrayUsers, &countUsers)) {
			int userFinded = 0, canDelete = 1;
			for (int _user = 0; _user < countUsers; _user++)
				if (arrayUsers[_user].id == id) {
					if (arrayUsers[_user].privilege == 1 && currentId != 0) {
						printf("\n�� �� ������ ������� ���������������!\n");
						canDelete = 0;
					}
					userFinded = 1;
					break;
				}
			if (userFinded) {
				if (canDelete) {
					struct User* newArrayUsers = (struct User*)malloc(sizeof(struct User) * (countUsers - 1));
					if (newArrayUsers) {
						int counter = 0;
						for (int _user = 0; _user < countUsers; _user++)
							if (arrayUsers[_user].id != id)
								newArrayUsers[counter++] = arrayUsers[_user];
						saveFileUsers(&newArrayUsers, &counter);
						if (newArrayUsers)
							free(newArrayUsers);
						printf("\n�����������[Enter], �����[����� ������ �������].\n");
						if (getPressedCharacter() == 13)
							printf("\n������������ ������� ������!\n");
						else
							printf("\n������������ �� ��� ������!\n");
					}
					else {
						printf("\n�� ������� �������� ������ � deleteUser!\n");
					}
				}
			}
			else {
				printf("\n������������ �� ������!\n");
			}
		}
		if (arrayUsers)
			free(arrayUsers);
	}
	pressAnyButton();
}