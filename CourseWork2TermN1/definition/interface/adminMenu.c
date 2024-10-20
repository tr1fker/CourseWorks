
#include <stdio.h>
#include <malloc.h>

#include "../../include/constants.h"
#include "../../include/input.h"
#include "../../include/functions.h"
#include "../../include/struct.h"
#include "../../include/userFunction.h"
#include "../../include/interface.h"

void adminMenu(struct User currentUser) {
	int programIsWork = 1;
	while (programIsWork) {
		clearConsole();
		int choice = inputFirstNatural(8, ADMINMENU);
		switch (choice) {
		case 1:
			resetPassword(currentUser);
			break;
		case 2:
			CRUDUser(currentUser.id);
			break;
		case 3:
		{
			struct User* users = NULL;
			int counterUsers = 0;
			if (inputFileUsers(&users, &counterUsers)) {
				clearConsole();
				printf("Количество пользователей:%d\n", counterUsers);
				pressAnyButton();
			}
			if (users)
				free(users);
		}
			break;
		case 4:
		{
			struct User* users = NULL;
			int counterUsers = 0;
			if (inputFileUsers(&users, &counterUsers)) {
				clearConsole();
				int counterAdmin = 0;
				for (int _user = 0; _user < counterUsers; _user++)
					if (users[_user].privilege)
						counterAdmin++;

				printf("Количество администраторов:%d\n", counterAdmin);
				pressAnyButton();
			}
			if (users)
				free(users);
		}
			break;
		case 5:
		{
			struct User* users = NULL;
			int counterUsers = 0;
			if (inputFileUsers(&users, &counterUsers)) {
				clearConsole();
				int counterBlocked = 0;
				for (int _user = 0; _user < counterUsers; _user++)
					if (users[_user].blocked)
						counterBlocked++;
				if (!counterBlocked)
					printf("Заблокированных пользователей нет!\n");
				else
					printf("Количество заблокированных пользователей:%d\n", counterBlocked);
				pressAnyButton();
			}
			if (users)
				free(users);
		}
			break;
		case 6:
		{
			clearConsole();
			int id = 0;
			float sum = findProfitableIdTransportationsOfUsers(currentUser.id, &id);
			if (sum == -1)
				printf("У пользователей нет грузовых перевозок!\n");
			else
				printf("Самый выгодная грузовая перевозка(цена/расстояние в км):%f\nИд пользователя:%d\n", sum, id);
			pressAnyButton();
		}
			break;
		case 7:
			{
				clearConsole();
				int id = 0, number = findMaxNumberProductsIdTransportationsOfUsers(currentUser.id, &id);
				if (number == -1)
					printf("У пользователей нет грузовых перевозок!\n");
				else
					printf("Самое большое количество грузовых перевозок:%d\nИд пользователя:%d\n", number, id);
				pressAnyButton();
			}
			break;
		case 8:
			programIsWork = 0;
			printf_s("\nВы успешно вышли из аккаунта!\n");
			pressAnyButton();
			break;
		}
	}
	return;
}