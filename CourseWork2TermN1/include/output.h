#ifndef PRINTINTERFACES_H
#define PRINTINTERFACES_H

int saveFileUsers(struct User** arrayUsers, int* countUsers);
int saveFileTransportations(struct Transportations** transportations, int* countTransportations);

int addUserFileUsers(struct User* newUser);

void printUsersConsole(int* columnSort, char** loginFilter, int* idFilter, int* privilegeFilter, int* blockedFilter, int* increase);

void printProductsTransportationConsole(int currentId, int* columnSort, int* increase, int* idFilter, int* numberProductsFilter, int* numberStopsFilter,
	float* minPriceGeneralFilter, float* maxPriceGeneralFilter, float* minFuelConsumedFilter,
	float* maxFuelConsumedFilter, float* minDistanceTraveledFilter, float* maxDistanceTraveledFilter,
	char** countryOriginFilterPtr, char** countryDeliveryFilterPtr, char** townOriginFilterPtr,
	char** townDeliveryFilterPtr, char** dateOriginFilterPtr, char** dateDeliveryFilterPtr,
	char** timeOriginFilterPtr, char** timeDeliveryFilterPtr, char** typeTransportFilterPtr);

void printCharacterNConsole(char character, int number);
void printCharacterConsole(char character);

void printFromIndexLineNCharacters(char* line, int number, int index);


#endif PRINTINTERFACES_H