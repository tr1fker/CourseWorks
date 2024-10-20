#ifndef INTERFACE_H
#define INTERFACE_H

#include "../include/struct.h"

void basicMenu();
void authorizationMenu();
void adminMenu(struct User currentUser);
void userMenu(struct User currentUser);
void CRUDUser(int currentId);
void CRUDProductTransportation(int currentId);
void listUsersMenu();
void listProductsTransportationMenu(int currentId);
void choiceFilterMenu(int* idFilterPtr, char** loginFilterPtr, int* privilegeFilterPtr, int* blockedFilterPtr);
void choiceFilterProductsTransportationMenu(int*idFilter, int*numberProductsFilter, int*numberStopsFilter,
	float*minPriceGeneralFilter, float*maxPriceGeneralFilter, float*minFuelConsumedFilter,
	float*maxFuelConsumedFilter, float*minDistanceTraveledFilter, float*maxDistanceTraveledFilter,
	char**countryOriginFilterPtr, char**countryDeliveryFilterPtr, char**townOriginFilterPtr,
	char**townDeliveryFilterPtr, char**dateOriginFilterPtr, char**dateDeliveryFilterPtr,
	char**timeOriginFilterPtr, char**timeDeliveryFilterPtr, char**typeTransportFilterPtr);
int choiceFilterByPrivilegeMenu();
int choiceFilterByBlockedMenu();
void choiceColumnSortMenu(int* columnSort, int* increase);
void choiceColumnSortProductsTransportationMenu(int* columnSort, int* increase);

#endif INTERFACE_H