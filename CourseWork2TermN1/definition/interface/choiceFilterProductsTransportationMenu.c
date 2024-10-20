
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
			printf("������� ������ ��������(���������):");
			countryOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 2:
			if (countryDeliveryFilterPtrNew)
				free(countryDeliveryFilterPtrNew);
			clearConsole();
			printf("������� ������ ��������(���������):");
			countryDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 3:
			if (townOriginFilterPtrNew)
				free(townOriginFilterPtrNew);
			clearConsole();
			printf("������� ����� ��������(���������):");
			townOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 4:
			if (townDeliveryFilterPtrNew)
				free(townDeliveryFilterPtrNew);
			clearConsole();
			printf("������� ����� ��������(���������):");
			townDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 5:
			if (dateOriginFilterPtrNew)
				free(dateOriginFilterPtrNew);
			clearConsole();
			printf("������� ���� ��������(���������):");
			dateOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 6:
			if (dateDeliveryFilterPtrNew)
				free(dateDeliveryFilterPtrNew);
			clearConsole();
			printf("������� ���� ��������(���������):");
			dateDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 7:
			if (timeOriginFilterPtrNew)
				free(timeOriginFilterPtrNew);
			clearConsole();
			printf("������� ����� ��������(���������):");
			timeOriginFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 8:
			if (timeDeliveryFilterPtrNew)
				free(timeDeliveryFilterPtrNew);
			clearConsole();
			printf("������� ����� ��������(���������):");
			timeDeliveryFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 9:
			if (typeTransportFilterPtrNew)
				free(typeTransportFilterPtrNew);
			clearConsole();
			printf("������� ��(���������):");
			typeTransportFilterPtrNew = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 10:
			clearConsole();
			printf("������� ����������� ���������(BYN):");
			minPriceGeneralFilter = (float)inputInteger(POSITIVE);
			break;
		case 11:
			clearConsole();
			printf("������� ������������ ���������(BYN):");
			maxPriceGeneralFilter = (float)inputInteger(POSITIVE);
			break;
		case 12:
			clearConsole();
			printf("������� ����������� ���-�� ������������ �������(����):");
			minFuelConsumedFilter = (float)inputInteger(POSITIVE);
			break;
		case 13:
			clearConsole();
			printf("������� ������������ ���-�� ������������ �������(����):");
			maxFuelConsumedFilter = (float)inputInteger(POSITIVE);
			break;
		case 14:
			clearConsole();
			printf("������� ����������� ���������� ����������(����):");
			minDistanceTraveledFilter = (float)inputInteger(POSITIVE);
			break;
		case 15:
			clearConsole();
			printf("������� ������������ ���������� ����������(����):");
			maxDistanceTraveledFilter = (float)inputInteger(POSITIVE);
			break;
		case 16:
			clearConsole();
			printf_s("������� ���-�� ��������� ������:");
			numberProductsFilter = inputInteger(POSITIVE);
			break;
		case 17:
			clearConsole();
			printf_s("������� ���-�� ���������:");
			numberStopsFilter = inputInteger(POSITIVE);
			break;
		case 18:
			clearConsole();
			printf_s("������� ��:");
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
				printf_s("\n�� ������� �������� ������ � choiceFilterMenu!\n");
				pressAnyButton();
				return;
			}
			clearConsole();
			printf("������ ��������!\n");
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