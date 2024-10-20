#include <stdio.h>
#include <malloc.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/convert.h"
#include "../../include/functions.h"
#include "../../include/output.h"

void deleteUser(int currentId) {
	clearConsole();
	printf("Введите ид пользователя:");
	int id = inputInteger(POSITIVE);
	if (id == currentId) {
		printf("\nВы ввели свой ид!\n");
	}
	else {
		struct User* arrayUsers = NULL;
		int countUsers = 0;
		if (inputFileUsers(&arrayUsers, &countUsers)) {
			int userFinded = 0, canDelete = 1;
			for (int _user = 0; _user < countUsers; _user++)
				if (arrayUsers[_user].id == id) {
					if (arrayUsers[_user].privilege == 1 && currentId != 0) {
						printf("\nВы не можете удалять администраторов!\n");
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
						printf("\nПодтвердить[Enter], иначе[любая другая клавиша].\n");
						if (getPressedCharacter() == 13)
							printf("\nПользователь успешно удален!\n");
						else
							printf("\nПользователь не был удален!\n");
					}
					else {
						printf("\nНе удалось выделить память в deleteUser!\n");
					}
				}
			}
			else {
				printf("\nПользователь не найден!\n");
			}
		}
		if (arrayUsers)
			free(arrayUsers);
	}
	pressAnyButton();
}