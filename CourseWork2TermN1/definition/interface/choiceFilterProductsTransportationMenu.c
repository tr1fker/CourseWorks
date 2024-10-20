
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <malloc.h>

#include "../../include/constants.h"
#include "../../include/input.h"
#include "../../include/functions.h"
#include "../../include/interface.h"

void choiceFilterProductsTransportationMenu(int* idFilterPtr, int* numberProductsFilterPtr, int* numberStopsFilterPtr,
	float* minPriceGeneralFilterPtr, float* maxPriceGeneralFilterPtr, float* minFuelConsumedFilterPtr,
	float* maxFuelConsumedFilterPtr, float* minDistanceTraveledFilterPtr, float* maxDistanceTraveledFilterPtr,
	char** countryOriginFilterPtr, char** countryDeliveryFilterPtr, char** townOriginFilterPtr,
	char** townDeliveryFilterPtr, char** dateOriginFilterPtr, char** dateDeliveryFilterPtr,
	char** timeOriginFilterPtr, char** timeDeliveryFilterPtr, char** typeTransportFilterPtr) {
	int menuIsWork = 1;
	char* countryOriginFilterPtrNew = _strdup(*countryOriginFilterPtr),
		* countryDeliveryFilterPtrNew = _strdup(*countryDeliveryFilterPtr),
		* townOriginFilterPtrNew = _strdup(*townOriginFilterPtr),
		* townDeliveryFilterPtrNew = _strdup(*townDeliveryFilterPtr),
		* dateOriginFilterPtrNew = _strdup(*dateOriginFilterPtr),
		* dateDeliveryFilterPtrNew = _strdup(*dateDeliveryFilterPtr),
		* timeOriginFilterPtrNew = _strdup(*timeOriginFilterPtr),
		* timeDeliveryFilterPtrNew = _strdup(*timeDeliveryFilterPtr),
		* typeTransportFilterPtrNew = _strdup(*typeTransportFilterPtr);
	int idFilter = *idFilterPtr, numberProductsFilter = *numberProductsFilterPtr, numberStopsFilter = *numberStopsFilterPtr;
	float minPriceGeneralFilter = *minPriceGeneralFilterPtr, maxPriceGeneralFilter = *maxPriceGeneralFilterPtr,
		minFuelConsumedFilter = *minFuelConsumedFilterPtr, maxFuelConsumedFilter = *maxFuelConsumedFilterPtr,
		minDistanceTraveledFilter = *minDistanceTraveledFilterPtr, maxDistanceTraveledFilter = *maxDistanceTraveledFilterPtr;
	while (menuIsWork) {
		int choice = inputFirstNatural(20, CHOICEFILTERPRODUCTSTRANSPORTATIONMENU);
		switch (choice) {
		case 1:
			if (countryOriginFilterPtrNew)
				free(countryOriginFilterPtrNew);
			clearConsole();
			printf("¬ведите страну отправки(подстроку):");
			countryOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 2:
			if (countryDeliveryFilterPtrNew)
				free(countryDeliveryFilterPtrNew);
			clearConsole();
			printf("¬ведите страну доставки(подстроку):");
			countryDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 3:
			if (townOriginFilterPtrNew)
				free(townOriginFilterPtrNew);
			clearConsole();
			printf("¬ведите город отправки(подстроку):");
			townOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 4:
			if (townDeliveryFilterPtrNew)
				free(townDeliveryFilterPtrNew);
			clearConsole();
			printf("¬ведите город доставки(подстроку):");
			townDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 5:
			if (dateOriginFilterPtrNew)
				free(dateOriginFilterPtrNew);
			clearConsole();
			printf("¬ведите дату отправки(подстроку):");
			dateOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 6:
			if (dateDeliveryFilterPtrNew)
				free(dateDeliveryFilterPtrNew);
			clearConsole();
			printf("¬ведите дату доставки(подстроку):");
			dateDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 7:
			if (timeOriginFilterPtrNew)
				free(timeOriginFilterPtrNew);
			clearConsole();
			printf("¬ведите врем€ отправки(подстроку):");
			timeOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 8:
			if (timeDeliveryFilterPtrNew)
				free(timeDeliveryFilterPtrNew);
			clearConsole();
			printf("¬ведите врем€ доставки(подстроку):");
			timeDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 9:
			if (typeTransportFilterPtrNew)
				free(typeTransportFilterPtrNew);
			clearConsole();
			printf("¬ведите “—(подстроку):");
			typeTransportFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 10:
			clearConsole();
			printf("¬ведите минимальную стоимость(BYN):");
			minPriceGeneralFilter = (float)inputInteger(POSITIVE);
			break;
		case 11:
			clearConsole();
			printf("¬ведите максимальную стоимость(BYN):");
			maxPriceGeneralFilter = (float)inputInteger(POSITIVE);
			break;
		case 12:
			clearConsole();
			printf("¬ведите минимальное кол-во потраченного топлива(литр):");
			minFuelConsumedFilter = (float)inputInteger(POSITIVE);
			break;
		case 13:
			clearConsole();
			printf("¬ведите максимальное кол-во потраченного топилва(литр):");
			maxFuelConsumedFilter = (float)inputInteger(POSITIVE);
			break;
		case 14:
			clearConsole();
			printf("¬ведите минимальное пройденное рассто€ние(метр):");
			minDistanceTraveledFilter = (float)inputInteger(POSITIVE);
			break;
		case 15:
			clearConsole();
			printf("¬ведите максимальное пройденное рассто€ние(метр):");
			maxDistanceTraveledFilter = (float)inputInteger(POSITIVE);
			break;
		case 16:
			clearConsole();
			printf_s("¬ведите кол-во различных грузов:");
			numberProductsFilter = inputInteger(POSITIVE);
			break;
		case 17:
			clearConsole();
			printf_s("¬ведите кол-во остановок:");
			numberStopsFilter = inputInteger(POSITIVE);
			break;
		case 18:
			clearConsole();
			printf_s("¬ведите ид:");
			idFilter = inputInteger(POSITIVE);
			break;
		case 19:
			free(countryOriginFilterPtrNew);
			free(countryDeliveryFilterPtrNew);
			free(townOriginFilterPtrNew);
			free(townDeliveryFilterPtrNew);
			free(dateOriginFilterPtrNew);
			free(dateDeliveryFilterPtrNew);
			free(timeOriginFilterPtrNew);
			free(timeDeliveryFilterPtrNew);
			free(typeTransportFilterPtrNew);
			if ((countryOriginFilterPtrNew = (char*)malloc(sizeof(char))) && (countryDeliveryFilterPtrNew = (char*)malloc(sizeof(char))) &&
				(townOriginFilterPtrNew = (char*)malloc(sizeof(char))) && (townDeliveryFilterPtrNew = (char*)malloc(sizeof(char))) &&
				(dateOriginFilterPtrNew = (char*)malloc(sizeof(char))) && (dateDeliveryFilterPtrNew = (char*)malloc(sizeof(char))) &&
				(timeOriginFilterPtrNew = (char*)malloc(sizeof(char))) && (timeDeliveryFilterPtrNew = (char*)malloc(sizeof(char))) &&
				(typeTransportFilterPtrNew = (char*)malloc(sizeof(char)))) {
				countryOriginFilterPtrNew[0] = '\0', countryDeliveryFilterPtrNew[0] = '\0',
					townOriginFilterPtrNew[0] = '\0', townDeliveryFilterPtrNew[0] = '\0',
					dateOriginFilterPtrNew[0] = '\0', dateDeliveryFilterPtrNew[0] = '\0',
					timeOriginFilterPtrNew[0] = '\0', timeDeliveryFilterPtrNew[0] = '\0',
					typeTransportFilterPtrNew[0] = '\0';
			}
			else {
				clearConsole();
				printf_s("\nЌе удалось выделить пам€ть в choiceFilterMenu!\n");
				pressAnyButton();
				return;
			}
			clearConsole();
			printf("‘ильтр отключен!\n");
			pressAnyButton();
			idFilter = -1, numberProductsFilter = -1, numberStopsFilter = -1,
				minPriceGeneralFilter = -1, maxPriceGeneralFilter = -1,
				minFuelConsumedFilter = -1, maxFuelConsumedFilter = -1,
				minDistanceTraveledFilter = -1, maxDistanceTraveledFilter = -1;
			break;
		case 20:
			menuIsWork = 0;
			break;
		}
	}
	if (*countryOriginFilterPtr)
		free(*countryOriginFilterPtr);
	if (*countryDeliveryFilterPtr)
		free(*countryDeliveryFilterPtr);
	if (*townOriginFilterPtr)
		free(*townOriginFilterPtr);
	if (*townDeliveryFilterPtr)
		free(*townDeliveryFilterPtr);
	if (*dateOriginFilterPtr)
		free(*dateOriginFilterPtr);
	if (*dateDeliveryFilterPtr)
		free(*dateDeliveryFilterPtr);
	if (*timeOriginFilterPtr)
		free(*timeOriginFilterPtr);
	if (*timeDeliveryFilterPtr)
		free(*timeDeliveryFilterPtr);
	if (*typeTransportFilterPtr)
		free(*typeTransportFilterPtr);
	*countryOriginFilterPtr = countryOriginFilterPtrNew;
	*countryDeliveryFilterPtr = countryDeliveryFilterPtrNew;
	*townOriginFilterPtr = townOriginFilterPtrNew;
	*townDeliveryFilterPtr = townDeliveryFilterPtrNew;
	*dateOriginFilterPtr = dateOriginFilterPtrNew;
	*dateDeliveryFilterPtr = dateDeliveryFilterPtrNew;
	*timeOriginFilterPtr = timeOriginFilterPtrNew;
	*timeDeliveryFilterPtr = timeDeliveryFilterPtrNew;
	*typeTransportFilterPtr = typeTransportFilterPtrNew;
	
	*idFilterPtr = idFilter, * numberProductsFilterPtr = numberProductsFilter, * numberStopsFilterPtr = numberStopsFilter,
		* minPriceGeneralFilterPtr = minPriceGeneralFilter, * maxPriceGeneralFilterPtr = maxPriceGeneralFilter,
		* minFuelConsumedFilterPtr = minFuelConsumedFilter, * maxFuelConsumedFilterPtr = maxFuelConsumedFilter,
		* minDistanceTraveledFilterPtr = minDistanceTraveledFilter, * maxDistanceTraveledFilterPtr = maxDistanceTraveledFilter;
	return;
}