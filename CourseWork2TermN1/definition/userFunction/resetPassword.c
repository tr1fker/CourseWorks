
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "../../include/struct.h"
#include "../../include/functions.h"
#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/output.h"

void resetPassword(struct User currentUser) {
	clearConsole();
	printf_s("Введите новый пароль:");
	char* newPassword = getPressedCharacters(LENGTHMAXPASSWORD);
	if (strlen(newPassword) < LENGTHMINPASSWORD)
		printf_s("\nПароль слишком короткий!\n");
	else {
		printf_s("\nПодтвердить новый пароль[Enter], иначе[любая другая клавиша].\n");
		struct User* arrayUsers = NULL;
		int countUsers = 0;
		if (getPressedCharacter() == 13 && inputFileUsers(&arrayUsers, &countUsers) && arrayUsers) {
			for (int _user = 0; _user < countUsers; _user++)
				if (arrayUsers[_user].id == currentUser.id) {
					if (arrayUsers[_user].login)
						free(arrayUsers[_user].login);
					if (arrayUsers[_user].solid)
						free(arrayUsers[_user].solid);
					if (arrayUsers[_user].hash)
						free(arrayUsers[_user].hash);
					arrayUsers[_user].login = _strdup(currentUser.login);
					arrayUsers[_user].hash = toHash(newPassword, (arrayUsers[_user].solid = generateSolid()));
					arrayUsers[_user].id = currentUser.id;
					arrayUsers[_user].privilege = currentUser.privilege;
					arrayUsers[_user].blocked = currentUser.blocked;
					break;
				}
			if (saveFileUsers(&arrayUsers, &countUsers))
				printf_s("Пароль был изменён!\n");
			else
				printf_s("Пароль не был изменён!\n");
		}
		else
			printf_s("Пароль не был изменён!\n");
		if (arrayUsers)
			free(arrayUsers);
	}
	pressAnyButton();
	if (newPassword)
		free(newPassword);
}