#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "../../include/input.h"
#include "../../include/struct.h"
#include "../../include/constants.h"
#include "../../include/functions.h"
#include "../../include/output.h"
#include "../../include/convert.h"

static void printLine() {
	printf("+");
	printCharacterNConsole('-', LENGTHNUMBERTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHIDTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHLOGINTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHHASHTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHSOLIDTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHPRIVILEGETABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHBLOCKEDTABLE);
	printf("+");
}

static void printCell(char** line, int LENGTH, int length, int* index) {
	printf("|");
	if (LENGTH + *index <= length) {
		printFromIndexLineNCharacters(*line, LENGTH, *index);
		*index += LENGTH;
	}
	else if (*index != length) {
		printFromIndexLineNCharacters(*line, LENGTH, *index);
		printCharacterNConsole(' ', LENGTH - (length - *index));
		*index = length;
	}
	else {
		printCharacterNConsole(' ', LENGTH);
	}
}

void printUsersConsole(int* columnSort, char** loginFilter, int* idFilter, int* privilegeFilter, int* blockedFilter, int* increase) {
	struct User* arrayUsers = NULL;
	int counterUsers = 0;
	if (inputFileUsers(&arrayUsers, &counterUsers)) {
		int counter = 0, filterFits = 1;
		struct User* filteredArrayUsers = NULL;
		for (int _user = 0; _user < counterUsers; _user++) {
			if (!arrayUsers)
				continue;
			if (arrayUsers[_user].login)
				if (!strstr(arrayUsers[_user].login, *loginFilter))
					continue;
			if (*idFilter && *idFilter != arrayUsers[_user].id)
				continue;
			if (*privilegeFilter && *privilegeFilter != 3) {
				if (*privilegeFilter == 1 && arrayUsers[_user].privilege || *privilegeFilter == 2 && !arrayUsers[_user].privilege)
					continue;
			}
			if (*blockedFilter && *blockedFilter != 3) {
				if (*blockedFilter == 1 && arrayUsers[_user].blocked || *blockedFilter == 2 && !arrayUsers[_user].blocked)
					continue;
			}
			struct User* buffer = (struct User*)malloc(sizeof(struct User) * (counter + 1));
			if (buffer) {
				for (int _userBuffer = 0; _userBuffer < counter; _userBuffer++)
					buffer[_userBuffer] = filteredArrayUsers[_userBuffer];
				buffer[counter++] = arrayUsers[_user];
				if (filteredArrayUsers)
					free(filteredArrayUsers);
				filteredArrayUsers = buffer;
				buffer = NULL;
			}
			else {
				if (arrayUsers)
					free(arrayUsers);
				if (filteredArrayUsers)
					free(filteredArrayUsers);
				clearConsole();
				printf("Не удалось выделить память в printUsersConsole!\n");
				pressAnyButton();
				return;
			}
		}

		if (counter) {
			if (*columnSort) {
				for (int step = 0; step < counter - 1; step++)
					for (int cell = 0; cell < counter - step - 1; cell++) {
						struct User buffer = filteredArrayUsers[cell];
						int swap = 0;
						switch (*columnSort) {
						case 1:
							if ((*increase && buffer.id > filteredArrayUsers[cell + 1].id) || (!*increase && buffer.id < filteredArrayUsers[cell + 1].id))
								swap = 1;
							break;
						case 2:
							if (*increase && strcmp(buffer.login, filteredArrayUsers[cell + 1].login) > 0 || !*increase && strcmp(buffer.login, filteredArrayUsers[cell + 1].login) < 0)
								swap = 1;
							break;
						case 3:
							if (*increase && strcmp(buffer.hash, filteredArrayUsers[cell + 1].hash) > 0 || !*increase && strcmp(buffer.hash, filteredArrayUsers[cell + 1].hash) < 0)
								swap = 1;
							break;
						case 4:
							if (*increase && strcmp(buffer.solid, filteredArrayUsers[cell + 1].solid) > 0 || !*increase && strcmp(buffer.solid, filteredArrayUsers[cell + 1].solid) < 0)
								swap = 1;
							break;
						case 5:
							if (*increase && buffer.privilege > filteredArrayUsers[cell + 1].privilege || !*increase && buffer.privilege < filteredArrayUsers[cell + 1].privilege)
								swap = 1;
							break;
						case 6:
							if (*increase && buffer.blocked > filteredArrayUsers[cell + 1].blocked || !*increase && buffer.blocked < filteredArrayUsers[cell + 1].blocked)
								swap = 1;
							break;
						}
						if (swap) {
							struct User buffer = filteredArrayUsers[cell];
							filteredArrayUsers[cell] = filteredArrayUsers[cell + 1];
							filteredArrayUsers[cell + 1] = buffer;
						}
					}
			}
			clearConsole();
			printLine();
			printf("\n|№");
			printCharacterNConsole(' ', LENGTHNUMBERTABLE - 1);
			printf("|ид");
			printCharacterNConsole(' ', LENGTHIDTABLE - 2);
			printf("|логин");
			printCharacterNConsole(' ', LENGTHLOGINTABLE - 5);
			printf("|хэш");
			printCharacterNConsole(' ', LENGTHHASHTABLE - 3);
			printf("|соль");
			printCharacterNConsole(' ', LENGTHSOLIDTABLE - 4);
			printf("|Администратор");
			printCharacterNConsole(' ', LENGTHPRIVILEGETABLE - 13);
			printf("|Блокировка");
			printCharacterNConsole(' ', LENGTHBLOCKEDTABLE - 10);
			printf("|\n");
			printLine();
			printf("\n");
			for (int _user = 0; _user < counter; _user++) {
				char* id = convertIntegerToPtrChar(filteredArrayUsers[_user].id),
					* number = convertIntegerToPtrChar(_user + 1),
					* login = filteredArrayUsers[_user].login,
					* hash = filteredArrayUsers[_user].hash,
					* solid = filteredArrayUsers[_user].solid;
				int lengthId = (int)strlen(id), indexId = 0,
					lengthNumber = (int)strlen(number), indexNumber = 0,
					lengthLogin = (int)strlen(login), indexLogin = 0,
					lengthHash = (int)strlen(hash), indexHash = 0,
					lengthSolid = (int)strlen(solid), indexSolid = 0,
					indexPrivilege = 0, indexBlocked = 0;
				while (lengthId > indexId + 1 || lengthNumber > indexNumber + 1 || lengthLogin > indexLogin + 1 || lengthHash > indexHash + 1 || lengthSolid > indexSolid + 1) {
					printCell(&number, LENGTHNUMBERTABLE, lengthNumber, &indexNumber);
					printCell(&id, LENGTHIDTABLE, lengthId, &indexId);
					printCell(&login, LENGTHLOGINTABLE, lengthLogin, &indexLogin);
					printCell(&hash, LENGTHHASHTABLE, lengthHash, &indexHash);
					printCell(&solid, LENGTHSOLIDTABLE, lengthSolid, &indexSolid);
					printf("|");
					if (!indexPrivilege) {
						printf("%s", (filteredArrayUsers[_user].privilege ? "Да" : "Нет"));
						printCharacterNConsole(' ', LENGTHPRIVILEGETABLE - (filteredArrayUsers[_user].privilege ? 2 : 3));
						indexPrivilege = 1;
					}
					else {
						printCharacterNConsole(' ', LENGTHPRIVILEGETABLE);
					}
					printf("|");
					if (!indexBlocked) {
						printf("%s", (filteredArrayUsers[_user].blocked ? "Да" : "Нет"));
						printCharacterNConsole(' ', LENGTHBLOCKEDTABLE - (filteredArrayUsers[_user].blocked ? 2 : 3));
						indexBlocked = 1;
					}
					else {
						printCharacterNConsole(' ', LENGTHBLOCKEDTABLE);
					}
					printf("|\n");
				}
				printLine();
				printf("\n");
				if (id)
					free(id);
				if (number)
					free(number);
			}
			pressAnyButton();
		}
		else {
			clearConsole();
			printf("Таблица пуста!\n");
			pressAnyButton();
		}
		if (arrayUsers)
			free(arrayUsers);
		if (filteredArrayUsers)
			free(filteredArrayUsers);
	}
}