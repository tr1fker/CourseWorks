#include <stdio.h>

#include "../../include/constants.h"
#include "../../include/input.h"
#include "../../include/functions.h"

void choiceColumnSortMenu(int* columnSort, int* increase) {
	int programIsWork = 1;
	while (programIsWork) {
		int choice = inputFirstNatural(10, CHOICECOLUMNSORTMENU);
		switch (choice) {
		case 7:
			*increase = 1;
			break;
		case 8:
			*increase = 0;
			break;
		case 9:
			*columnSort = 0;
			clearConsole();
			printf("Сортировка отключена!\n");
			pressAnyButton();
			break;
		case 10:
			programIsWork = 0;
			break;
		default:
			*columnSort = choice;
			break;
		}
	}
	return;
}