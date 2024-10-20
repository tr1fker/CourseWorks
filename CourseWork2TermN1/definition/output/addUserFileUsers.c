#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../../include/struct.h"
#include "../../include/functions.h"
#include "../../include/output.h"
#include "../../include/input.h"

int addUserFileUsers(struct User* newUser) {
	struct User* arrayUsers = NULL, *newArrayUsers = NULL;
	int countUsers = 0;
	if (inputFileUsers(&arrayUsers, &countUsers)) {
		if (newArrayUsers = (struct User*)malloc(sizeof(struct User) * (countUsers + 1))) {
			int newId = 0, idFinded = 0;
			while (!idFinded) {
				newId++;
				for (int _id = 0; _id < countUsers; _id++)
					if (arrayUsers[_id].id == newId)
						break;
					else if (_id + 1 == countUsers)
						idFinded = 1;
			}
			newUser->id = newId;
			for (int _user = 0; _user < countUsers; _user++) {
				newArrayUsers[_user].id = arrayUsers[_user].id;
				newArrayUsers[_user].blocked = arrayUsers[_user].blocked;
				newArrayUsers[_user].privilege = arrayUsers[_user].privilege;
				newArrayUsers[_user].login = _strdup(arrayUsers[_user].login);
				newArrayUsers[_user].hash = _strdup(arrayUsers[_user].hash);
				newArrayUsers[_user].solid = _strdup(arrayUsers[_user].solid);
			}
			newArrayUsers[countUsers++] = *newUser;
			if (saveFileUsers(&newArrayUsers, &countUsers)) {
				if (newArrayUsers)
					free(newArrayUsers);
				if (arrayUsers)
					free(arrayUsers);
				return 1;
			}
			if (newArrayUsers)
				free(newArrayUsers);
		}
		else
			printf("\nНе удалось выделить память для нового пользователя!\n");
		if (arrayUsers)
			free(arrayUsers);
	}
	pressAnyButton();
	return 0;
}