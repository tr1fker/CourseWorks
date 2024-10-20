#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/interface.h"
#include "../../include/functions.h"
#include "../../include/output.h"

void listUsersMenu() {
	int menuIsWork = 1;
	char* loginFilterPtr;
	if (loginFilterPtr = (char*)malloc(sizeof(char))) {
		loginFilterPtr[0] = '\0';
		int columnSort = 0, idFilter = 0, privilegeFilter = 0, blockedFilter = 0, increase = 1;
		while (menuIsWork) {
			int choice = inputFirstNatural(4, LISTUSERSMENU);
			switch (choice) {
			case 1:
				choiceFilterMenu(&idFilter, &loginFilterPtr, &privilegeFilter, &blockedFilter);
				break;
			case 2:
				choiceColumnSortMenu(&columnSort, &increase);
				break;
			case 3:
				printUsersConsole(&columnSort, &loginFilterPtr, &idFilter, &privilegeFilter, &blockedFilter, &increase);
				break;
			case 4:
				menuIsWork = 0;
				break;
			}
		}
		return;
	}
	printf_s("\nНе удалось выделить память в listUserMenu!\n");
	pressAnyButton();
	return;
}