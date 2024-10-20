
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../include/functions.h"
#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/struct.h"
#include "../../include/output.h"

void registerUser() {
	int programIsWork = 1, admin = 0, blocked = 0;
	char* newLogin = NULL, * newPassword = NULL;
	while (programIsWork) {
		clearConsole();
		int choice = inputFirstNatural(6, REGISTERUSERMENU);
		switch (choice) {
		case 1:
			clearConsole();
			printf_s("Введите новый логин:");
			if (newLogin)
				free(newLogin);
			newLogin = getPressedCharacters(LENGTHMAXLOGIN);
			break;
		case 2:
			clearConsole();
			printf_s("Введите новый пароль:");
			if (newPassword)
				free(newPassword);
			newPassword = getPressedCharacters(LENGTHMAXPASSWORD);
			break;
		case 3:
			clearConsole();
			printf_s("Нажмите '1', чтобы дать администратора пользователю, иначе нажмите любую другую клавишу.");
			if (getPressedCharacter() == '1')
				admin = 1;
			else
				admin = 0;
			break;
		case 4:
			clearConsole();
			printf_s("Нажмите '1', чтобы дать блокировку пользователю, иначе нажмите любую другую клавишу.");
			if (getPressedCharacter() == '1')
				blocked = 1;
			else
				blocked = 0;
			break;
		case 5: {
			int lengthNewLogin = 0, lengthNewPassword = 0;
			if (newLogin)
				lengthNewLogin = (int)strlen(newLogin);
			if (newPassword)
				lengthNewPassword = (int)strlen(newPassword);
			if (!lengthNewLogin && !lengthNewPassword)
				printf_s("\nВведите логин и пароль!\n");
			else if (!lengthNewLogin)
				printf_s("\nВведите логин!\n");
			else if (!lengthNewPassword)
				printf_s("\nВведите пароль!\n");
			else if (lengthNewLogin < LENGTHMINLOGIN)
				printf_s("\nЛогин слишком короткий!\n");
			else if (lengthNewPassword < LENGTHMINPASSWORD)
				printf_s("\nПароль слишком короткий!\n");
			else {
				struct User* arrayUsers = NULL;
				int countUsers = 0, loginFree = 1;
				if (inputFileUsers(&arrayUsers, &countUsers)) {
					for (int _user = 0; _user < countUsers; _user++)
						if (!strcmp(arrayUsers[_user].login, newLogin)) {
							printf_s("\nЛогин уже занят!\n");
							loginFree = 0;
							break;
						}
				}
				if (loginFree) {
					struct User newUser;
					newUser.blocked = blocked;
					newUser.privilege = admin;
					newUser.login = newLogin;
					newUser.solid = generateSolid();
					newUser.hash = toHash(newPassword, newUser.solid);
					if (addUserFileUsers(&newUser)) {
						printf("\nПользователь успешно зарегистрирован!\n");
						programIsWork = 0;
					}
					free(newUser.solid);
					free(newUser.hash);
					newUser.login = NULL;
				}
				if (arrayUsers)
					free(arrayUsers);
			}
			pressAnyButton();
		}
			break;
		case 6:
			programIsWork = 0;
			break;
		}
	}
	if (newLogin)
		free(newLogin);
	if (newPassword)
		free(newPassword);
	return;
}