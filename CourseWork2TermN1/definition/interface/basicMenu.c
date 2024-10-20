#include <stdio.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/interface.h"
#include "../../include/functions.h"

void basicMenu() {
	int programIsWork = 1;
	while (programIsWork) {
		clearConsole();
		int choice = inputFirstNatural(2, BASICMENU);
		switch (choice) {
		case 1:
			authorizationMenu();
			break;
		case 2:
			programIsWork = 0;
			clearConsole();
			printf_s("Вы успешно вышли из системы!");
			break;
		}
	}
	return;
}