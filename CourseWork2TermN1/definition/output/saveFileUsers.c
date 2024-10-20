#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "../../include/struct.h"
#include "../../include/functions.h"

int saveFileUsers(struct User** arrayUsers, int* countUsers) {
	FILE* users;
	if (!fopen_s(&users, "file/users.txt", "r+t")) {
		if (!fprintf(users, "%d\n", *countUsers)) {
			printf("\nНе удалось записать в файл users!");
			pressAnyButton();
			fclose(users);
			return 0;
		}
		for (int _user = 0; _user < *countUsers; _user++) {
			if (!fprintf(users, "%d %s %s %s %d %d\n", (*arrayUsers)[_user].id, (*arrayUsers)[_user].login, (*arrayUsers)[_user].hash, (*arrayUsers)[_user].solid, (*arrayUsers)[_user].privilege, (*arrayUsers)[_user].blocked)) {
				printf("\nНе удалось записать в файл users!");
				pressAnyButton();
				fclose(users);
				return 0;
			}
		}
		fclose(users);
		return 1;
	}
	printf("\nНе удалось открыть файл users!\n");
	pressAnyButton();
	return 0;
}