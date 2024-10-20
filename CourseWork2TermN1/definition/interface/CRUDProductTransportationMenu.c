

#include "../../include/functions.h"
#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/interface.h"
#include "../../include/transportationFunction.h"

void CRUDProductTransportation(int currentId) {
	int programIsWork = 1;
	while (programIsWork) {
		clearConsole();
		int choice = inputFirstNatural(4, CRUDPRODUCTTRANSPORTATIONMENU);
		switch (choice) {
		case 1:
			createTransportationMenu(currentId);
			break;
		case 2:
			deleteTransportation(currentId);
			break;
		case 3:
			listProductsTransportationMenu(currentId);
			break;
		case 4:
			programIsWork = 0;
			break;
		}
	}
	return;
}