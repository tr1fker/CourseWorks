#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#include "../../include/input.h"
#include "../../include/constants.h"
#include "../../include/interface.h"
#include "../../include/functions.h"
#include "../../include/output.h"

void listProductsTransportationMenu(int currentId) {
	int menuIsWork = 1;
	char* countryOriginFilterPtr, *countryDeliveryFilterPtr,
		* townOriginFilterPtr, *townDeliveryFilterPtr,
		* dateOriginFilterPtr, *dateDeliveryFilterPtr,
		* timeOriginFilterPtr, *timeDeliveryFilterPtr,
		* typeTransportFilterPtr;
	if ((countryOriginFilterPtr = (char*)malloc(sizeof(char))) && (countryDeliveryFilterPtr = (char*)malloc(sizeof(char))) &&
		(townOriginFilterPtr = (char*)malloc(sizeof(char))) && (townDeliveryFilterPtr = (char*)malloc(sizeof(char))) &&
		(dateOriginFilterPtr = (char*)malloc(sizeof(char))) && (dateDeliveryFilterPtr = (char*)malloc(sizeof(char))) &&
		(timeOriginFilterPtr = (char*)malloc(sizeof(char))) && (timeDeliveryFilterPtr = (char*)malloc(sizeof(char))) &&
		(typeTransportFilterPtr = (char*)malloc(sizeof(char)))) {
		countryOriginFilterPtr[0] = '\0', countryDeliveryFilterPtr[0] = '\0',
			townOriginFilterPtr[0] = '\0', townDeliveryFilterPtr[0] = '\0',
			dateOriginFilterPtr[0] = '\0', dateDeliveryFilterPtr[0] = '\0',
			timeOriginFilterPtr[0] = '\0', timeDeliveryFilterPtr[0] = '\0',
			typeTransportFilterPtr[0] = '\0';
		int columnSort = 0, idFilter = -1, increase = 1, numberProductsFilter = -1, numberStopsFilter = -1;
		float minPriceGeneralFilter = -1, maxPriceGeneralFilter = -1, minFuelConsumedFilter = -1, maxFuelConsumedFilter = -1, minDistanceTraveledFilter = -1, maxDistanceTraveledFilter = -1;
		while (menuIsWork) {
			int choice = inputFirstNatural(4, LISTPRODUCTSTRANSPORTATIONMENU);
			switch (choice) {
			case 1:
				choiceFilterProductsTransportationMenu(&idFilter, &numberProductsFilter, &numberStopsFilter,
					&minPriceGeneralFilter, &maxPriceGeneralFilter, &minFuelConsumedFilter,
					&maxFuelConsumedFilter, &minDistanceTraveledFilter, &maxDistanceTraveledFilter,
					&countryOriginFilterPtr, &countryDeliveryFilterPtr, &townOriginFilterPtr,
					&townDeliveryFilterPtr, &dateOriginFilterPtr, &dateDeliveryFilterPtr,
					&timeOriginFilterPtr, &timeDeliveryFilterPtr, &typeTransportFilterPtr);
				break;
			case 2:
				choiceColumnSortProductsTransportationMenu(&columnSort, &increase);
				break;
			case 3:
				printProductsTransportationConsole(currentId, &columnSort, &increase, &idFilter, &numberProductsFilter, &numberStopsFilter,
					&minPriceGeneralFilter, &maxPriceGeneralFilter, &minFuelConsumedFilter,
					&maxFuelConsumedFilter, &minDistanceTraveledFilter, &maxDistanceTraveledFilter,
					&countryOriginFilterPtr, &countryDeliveryFilterPtr, &townOriginFilterPtr,
					&townDeliveryFilterPtr, &dateOriginFilterPtr, &dateDeliveryFilterPtr,
					&timeOriginFilterPtr, &timeDeliveryFilterPtr, &typeTransportFilterPtr);
				break;
			case 4:
				menuIsWork = 0;
				break;
			}
		}
		return;
	}
	printf_s("\nНе удалось выделить память в listProductsTransportationMenu!\n");
	pressAnyButton();
	return;
}