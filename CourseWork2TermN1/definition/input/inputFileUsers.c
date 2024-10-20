#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/input.h"
#include "../../include/struct.h"
#include "../../include/functions.h"

int inputFileUsers(struct User** arrayUsers, int* countUsers) {
	FILE* users;
	if (!fopen_s(&users, "file/users.txt", "r+t")) {
		if (!fscanf_s(users, "%d", countUsers)) {
			printf("\nНе удалось прочитать файл users!");
			pressAnyButton();
			return 0;
		}
		if (*arrayUsers = (struct User*)malloc(sizeof(struct User) * *countUsers)) {
			for (int _user = 0; _user < *countUsers; _user++) {
				(*arrayUsers)[_user].login = (char*)malloc(sizeof(char) * (LENGTHMAXLOGIN + 1));
				(*arrayUsers)[_user].solid = (char*)malloc(sizeof(char) * (LENGTHMAXSOLID + 1));
				(*arrayUsers)[_user].hash = (char*)malloc(sizeof(char) * (LENGTHMAXPASSWORD + 1));
				if ((*arrayUsers)[_user].login && (*arrayUsers)[_user].solid && (*arrayUsers)[_user].hash) {
					(*arrayUsers)[_user].login[0] = '\0';
					(*arrayUsers)[_user].solid[0] = '\0';
					(*arrayUsers)[_user].hash[0] = '\0';
					if (fscanf(users, "%d%s%s%s%d%d", &(*arrayUsers)[_user].id, (*arrayUsers)[_user].login, (*arrayUsers)[_user].hash, (*arrayUsers)[_user].solid, &(*arrayUsers)[_user].privilege, &(*arrayUsers)[_user].blocked)) {
						continue;
					}
					else
						printf("\nНе удалось прочитать файл users пользователя!");
				}
				else
					printf("\nНе удалось выделить память для пользователя user!");
				fclose(users);
				pressAnyButton();
				return 0;
			}
		}
		else {
			printf("\nНе удалось выделить память для массива users!");
			fclose(users);
			pressAnyButton();
			return 0;
		}
		fclose(users);
		return 1;
	}
	printf("\nНе удалось открыть файл с users!");
	pressAnyButton();
	return 0;
}