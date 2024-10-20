#include <stdio.h>
#include <malloc.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/convert.h"
#include "../../include/functions.h"
#include "../../include/output.h"

void blockUser(int currentId) {
	clearConsole();
	printf("Введите ид пользователя:");
	char* inputId = getPressedCharacters(LENGTHID);
	int id = convertPtrCharToInteger(inputId);
	if (inputId)
		free(inputId);
	if (id == currentId) {
		printf("\nВы ввели свой ид!\n");
	}
	else {
		struct User* arrayUsers = NULL;
		int countUsers = 0;
		if (inputFileUsers(&arrayUsers, &countUsers)) {
			for (int _user = 0; _user < countUsers; _user++)
				if (arrayUsers[_user].id == id) {
					if (arrayUsers[_user].privilege == 1 && currentId != 0) {
						printf("\nВы не можете блокировать администраторов!\n");
					}
					else {
						if (arrayUsers[_user].blocked) {
							arrayUsers[_user].blocked = 0;
							printf("\nПодтвердить[Enter], иначе[любая другая клавиша].\n");
							if (getPressedCharacter() == 13)
								printf("\nПользователь успешно разблокирован!\n");
							else
								printf("\nПользователь не был разблокирован!\n");
						}
						else {
							arrayUsers[_user].blocked = 1;
							printf("\nПодтвердить[Enter], иначе[любая другая клавиша].\n");
							if (getPressedCharacter() == 13)
								printf("\nПользователь успешно заблокирован!\n");
							else
								printf("\nПользователь не был заблокирован!\n");
						}
						saveFileUsers(&arrayUsers, &countUsers);
					}
					break;
				}else if (_user + 1 == countUsers)
					printf("\nПользователь не найден!\n");
		}
		if (arrayUsers)
			free(arrayUsers);
	}
	pressAnyButton();
}