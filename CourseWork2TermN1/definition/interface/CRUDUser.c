

#include "../../include/functions.h"
#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/userFunction.h"
#include "../../include/interface.h"

void CRUDUser(int currentId) {
	int programIsWork = 1;
	while (programIsWork) {
		clearConsole();
		int choice = inputFirstNatural(5, CRUDUSERMENU);
		switch (choice) {
		case 1:
			registerUser();
			break;
		case 2:
			deleteUser(currentId);
			break;
		case 3:
			blockUser(currentId);
			break;
		case 4:
			listUsersMenu();
			break;
		case 5:
			programIsWork = 0;
			break;
		}
	}
	return;
}