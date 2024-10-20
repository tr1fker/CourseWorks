
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>

#include "../../include/constants.h"
#include "../../include/input.h"
#include "../../include/functions.h"
#include "../../include/interface.h"

void choiceFilterMenu(int* idFilterPtr, char** loginFilterPtr, int* privilegeFilterPtr, int* blockedFilterPtr) {
	int menuIsWork = 1;
	char* loginFilterPtrNew = _strdup(*loginFilterPtr);
	int idFilter = *idFilterPtr, privilegeFilter = *privilegeFilterPtr, blockedFilter = *blockedFilterPtr;
	while (menuIsWork) {
		int choice = inputFirstNatural(6, CHOICEFILTERMENU);
		switch (choice) {
		case 1:
			if (loginFilterPtrNew)
				free(loginFilterPtrNew);
			clearConsole();
			printf("Введите логин(подстроку):");
			loginFilterPtrNew = getPressedCharacters(LENGTHMAXLOGIN);
			break;
		case 2:
			privilegeFilter = choiceFilterByPrivilegeMenu();
			break;
		case 3:
			blockedFilter = choiceFilterByBlockedMenu();
			break;
		case 4:
			clearConsole();
			printf_s("Введите ид:");
			idFilter = inputInteger(POSITIVE);
			break;
		case 5:
			if (loginFilterPtrNew)
				free(loginFilterPtrNew);
			if (loginFilterPtrNew = (char*)malloc(sizeof(char)))
				loginFilterPtrNew[0] = '\0';
			else {
				clearConsole();
				printf_s("\nНе удалось выделить память в choiceFilterMenu!\n");
				pressAnyButton();
				return;
			}
			clearConsole();
			printf("Фильтр отключен!\n");
			pressAnyButton();
			privilegeFilter = 0, blockedFilter = 0, idFilter = 0;
			break;
		case 6:
			menuIsWork = 0;
			break;
		}
	}
	if (*loginFilterPtr)
		free(*loginFilterPtr);
	*loginFilterPtr = loginFilterPtrNew;
	*idFilterPtr = idFilter, * privilegeFilterPtr = privilegeFilter, * blockedFilterPtr = blockedFilter;
	return;
}