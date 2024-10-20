

#include "../../include/constants.h"
#include "../../include/input.h"

int choiceFilterByPrivilegeMenu() {
	while (1) {
		int choice = inputFirstNatural(4, CHOICEFILTERBYPRIVILEGEMENU);
		if (choice > 0 && choice < 5)
			return choice;
	}
}