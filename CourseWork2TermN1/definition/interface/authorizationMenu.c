#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "../../include/interface.h"
#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/functions.h"
#include "../../include/struct.h"

void authorizationMenu() {
	int programIsWork = 1;
	char* inputLogin = NULL, * inputPassword = NULL;
	while (programIsWork) {
		clearConsole();
		int choice = inputFirstNatural(4, AUTHORIZATIONMENU);
		switch (choice) {
		case 1:
			clearConsole();
			printf_s("Введите логин:");
			if (inputLogin)
				free(inputLogin);
			inputLogin = getPressedCharacters(LENGTHMAXLOGIN);
			break;
		case 2:
			clearConsole();
			printf_s("Введите пароль:");
			if (inputPassword)
				free(inputPassword);
			inputPassword = getPressedCharacters(LENGTHMAXPASSWORD);
			break;
		case 3: {
			int lengthLogin = 0, lengthPassword = 0;
			if (inputLogin)
				lengthLogin = (int)strlen(inputLogin);
			if (inputPassword)
				lengthPassword = (int)strlen(inputPassword);
			if (!lengthLogin && !lengthPassword)
				printf_s("\nВведите логин и пароль!\n");
			else if (!lengthLogin)
				printf_s("\nВведите логин!\n");
			else if (!lengthPassword)
				printf_s("\nВведите пароль!\n");
			else {
				struct User* arrayUsers = NULL;
				int countUsers = 0;
				if (inputFileUsers(&arrayUsers, &countUsers)) {
					int indexFindedUser = -1;
					for (int _user = 0; _user < countUsers; _user++)
						if (!strcmp(arrayUsers[_user].login, inputLogin) && !strcmp(arrayUsers[_user].hash, toHash(inputPassword, arrayUsers[_user].solid)))
							indexFindedUser = _user;
					if (indexFindedUser != -1) {
						if (arrayUsers[indexFindedUser].blocked)
							printf("\nПользователь заблокирован!\n");
						else {
							printf("\nУспешный вход!\n");
							pressAnyButton();
							if (arrayUsers[indexFindedUser].privilege)
								adminMenu(arrayUsers[indexFindedUser]);
							else
								userMenu(arrayUsers[indexFindedUser]);
							return;
						}
					}
					else {
						printf("\nНеверный логин или пароль!\n");
					}
				}
				if (arrayUsers)
					free(arrayUsers);
			}
			pressAnyButton();
		}
			break;
		case 4:
			programIsWork = 0;
			break;
		}
	}
	if (inputLogin)
		free(inputLogin);
	if (inputPassword)
		free(inputPassword);
}