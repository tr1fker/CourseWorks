#include <stdio.h>

#include "../../include/constants.h"
#include "../../include/input.h"
#include "../../include/functions.h"

void choiceColumnSortProductsTransportationMenu(int* columnSort, int* increase) {
	int programIsWork = 1;
	while (programIsWork) {
		int choice = inputFirstNatural(19, CHOICECOLUMNSORTPRODUCTSTRANSPORTATIONMENU);
		switch (choice) {
		case 16:
			*increase = 1;
			break;
		case 17:
			*increase = 0;
			break;
		case 18:
			*columnSort = 0;
			clearConsole();
			printf("Сортировка отключена!\n");
			pressAnyButton();
			break;
		case 19:
			programIsWork = 0;
			break;
		default:
			*columnSort = choice;
			break;
		}
	}
	return;
}