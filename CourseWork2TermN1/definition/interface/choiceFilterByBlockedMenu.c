

#include "../../include/constants.h"
#include "../../include/input.h"

int choiceFilterByBlockedMenu() {
	while (1) {
		int choice = inputFirstNatural(4, CHOICEFILTERBYBLOCKEDMENU);
		if (choice > 0 && choice < 5)
			return choice;
	}
}