#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "../../include/input.h"
#include "../../include/struct.h"
#include "../../include/constants.h"
#include "../../include/functions.h"
#include "../../include/output.h"
#include "../../include/convert.h"

static void printLine() {
	printf("+");
	printCharacterNConsole('-', LENGTHIDTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHCOUNTRYTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHCOUNTRYTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHTOWNTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHTOWNTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHDATETABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHDATETABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHTIMETABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHTIMETABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHTYPETRANSPORTTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHPRODUCTSTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHNUMBERSTOPSTABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHGENERALPRICETABLE);
	printf("+");
	printCharacterNConsole('-', LENGTHFUELCONSUMED);
	printf("+");
	printCharacterNConsole('-', LENGTHDISTANCETRAVELEDTABLE);
	printf("+");
}

static void printCell(char** line, int LENGTH, int length, int* index) {
	printf("|");
	if (LENGTH + *index <= length) {
		printFromIndexLineNCharacters(*line, LENGTH, *index);
		*index += LENGTH;
	}
	else if (*index != length) {
		printFromIndexLineNCharacters(*line, LENGTH, *index);
		printCharacterNConsole(' ', LENGTH - (length - *index));
		*index = length;
	}
	else {
		printCharacterNConsole(' ', LENGTH);
	}
}

void printProductsTransportationConsole(int currentId, int* columnSort, int* increase, int*idFilter, int*numberProductsFilter, int*numberStopsFilter,
	float*minPriceGeneralFilter, float*maxPriceGeneralFilter, float*minFuelConsumedFilter,
	float*maxFuelConsumedFilter, float*minDistanceTraveledFilter, float*maxDistanceTraveledFilter,
	char**countryOriginFilterPtr, char** countryDeliveryFilterPtr, char** townOriginFilterPtr,
	char** townDeliveryFilterPtr, char** dateOriginFilterPtr, char** dateDeliveryFilterPtr,
	char** timeOriginFilterPtr, char** timeDeliveryFilterPtr, char** typeTransportFilterPtr) {
	struct Transportations* transportations = NULL;
	int counterTransportations = 0;
	if (inputFileTransportations(&transportations, &counterTransportations)) {
		int counter = 0;
		struct ProductTransportation* filteredArrayTransportations = NULL;
		for (int _transportations = 0; _transportations < counterTransportations; _transportations++) {
			if (transportations[_transportations].id == currentId) {
				for (int _productTransportation = 0; _productTransportation < transportations[_transportations].number; _productTransportation++) {
					if (!transportations[_transportations].arrayProductTransportation)
						continue;
					struct ProductTransportation* currentPT = &(transportations[_transportations].arrayProductTransportation[_productTransportation]);
					if (currentPT->countryOrigin)
						if (!strstr(currentPT->countryOrigin, *countryOriginFilterPtr))
							continue;
					if (currentPT->countryDelivery)
						if (!strstr(currentPT->countryDelivery, *countryDeliveryFilterPtr))
							continue;
					if (currentPT->townOrigin)
						if (!strstr(currentPT->townOrigin, *townOriginFilterPtr))
							continue;
					if (currentPT->townDelivery)
						if (!strstr(currentPT->townDelivery, *townDeliveryFilterPtr))
							continue;
					if (currentPT->dateOrigin)
						if (!strstr(currentPT->dateOrigin, *dateOriginFilterPtr))
							continue;
					if (currentPT->dateDelivery)
						if (!strstr(currentPT->dateDelivery, *dateDeliveryFilterPtr))
							continue;
					if (currentPT->timeOrigin)
						if (!strstr(currentPT->timeOrigin, *timeOriginFilterPtr))
							continue;
					if (currentPT->timeDelivery)
						if (!strstr(currentPT->timeDelivery, *timeDeliveryFilterPtr))
							continue;
					if (currentPT->typeTransport)
						if (!strstr(currentPT->typeTransport, *typeTransportFilterPtr))
							continue;
					if (*idFilter != -1 && *idFilter != currentPT->id)
						continue;
					if (*numberProductsFilter != -1 && *numberProductsFilter != currentPT->numberProducts)
						continue;
					if (*numberStopsFilter != -1 && *numberStopsFilter != currentPT->numberStops)
						continue;
					if (*minPriceGeneralFilter != -1 && currentPT->priceGeneral < *minPriceGeneralFilter)
						continue;
					if (*maxPriceGeneralFilter != -1 && currentPT->priceGeneral > *maxPriceGeneralFilter)
						continue;
					if (*minFuelConsumedFilter != -1 && currentPT->fuelConsumed < *minFuelConsumedFilter)
						continue;
					if (*maxFuelConsumedFilter != -1 && currentPT->fuelConsumed > *maxFuelConsumedFilter)
						continue;
					if (*minDistanceTraveledFilter != -1 && currentPT->distanceTraveled < *minDistanceTraveledFilter)
						continue;
					if (*maxDistanceTraveledFilter != -1 && currentPT->distanceTraveled > *maxDistanceTraveledFilter)
						continue;
					struct ProductTransportation* buffer = (struct ProductTransportation*)malloc(sizeof(struct ProductTransportation) * (counter + 1));
					if (buffer) {
						for (int _PTBuffer = 0; _PTBuffer < counter; _PTBuffer++)
							buffer[_PTBuffer] = filteredArrayTransportations[_PTBuffer];
						buffer[counter++] = *currentPT;
						//if (filteredArrayTransportations)
							//free(filteredArrayTransportations);
						filteredArrayTransportations = buffer;
						buffer = NULL;
					}
					else {
						if (transportations)
							free(transportations);
						if (filteredArrayTransportations)
							free(filteredArrayTransportations);
						clearConsole();
						printf("Не удалось выделить память в printProductsTransportationConsole!\n");
						pressAnyButton();
						return;
					}
				}

				if (counter) {
					if (*columnSort) {
						for (int step = 0; step < counter - 1; step++)
							for (int cell = 0; cell < counter - step - 1; cell++) {
								struct ProductTransportation buffer = filteredArrayTransportations[cell];
								int swap = 0;
								switch (*columnSort) {
								case 1:
									if (*increase && strcmp(buffer.countryOrigin, filteredArrayTransportations[cell + 1].countryOrigin) > 0 || !*increase && strcmp(buffer.countryOrigin, filteredArrayTransportations[cell + 1].countryOrigin) < 0)
										swap = 1;
									break;
								case 2:
									if (*increase && strcmp(buffer.countryDelivery, filteredArrayTransportations[cell + 1].countryDelivery) > 0 || !*increase && strcmp(buffer.countryDelivery, filteredArrayTransportations[cell + 1].countryDelivery) < 0)
										swap = 1;
									break;
								case 3:
									if (*increase && strcmp(buffer.townOrigin, filteredArrayTransportations[cell + 1].townOrigin) > 0 || !*increase && strcmp(buffer.townOrigin, filteredArrayTransportations[cell + 1].townOrigin) < 0)
										swap = 1;
									break;
								case 4:
									if (*increase && strcmp(buffer.townDelivery, filteredArrayTransportations[cell + 1].townDelivery) > 0 || !*increase && strcmp(buffer.townDelivery, filteredArrayTransportations[cell + 1].townDelivery) < 0)
										swap = 1;
									break;
								case 5:
									if (*increase && strcmp(buffer.dateOrigin, filteredArrayTransportations[cell + 1].dateOrigin) > 0 || !*increase && strcmp(buffer.dateOrigin, filteredArrayTransportations[cell + 1].dateOrigin) < 0)
										swap = 1;
									break;
								case 6:
									if (*increase && strcmp(buffer.dateDelivery, filteredArrayTransportations[cell + 1].dateDelivery) > 0 || !*increase && strcmp(buffer.dateDelivery, filteredArrayTransportations[cell + 1].dateDelivery) < 0)
										swap = 1;
									break;
								case 7:
									if (*increase && strcmp(buffer.timeOrigin, filteredArrayTransportations[cell + 1].timeOrigin) > 0 || !*increase && strcmp(buffer.timeOrigin, filteredArrayTransportations[cell + 1].timeOrigin) < 0)
										swap = 1;
									break;
								case 8:
									if (*increase && strcmp(buffer.timeDelivery, filteredArrayTransportations[cell + 1].timeDelivery) > 0 || !*increase && strcmp(buffer.timeDelivery, filteredArrayTransportations[cell + 1].timeDelivery) < 0)
										swap = 1;
									break;
								case 9:
									if (*increase && strcmp(buffer.typeTransport, filteredArrayTransportations[cell + 1].typeTransport) > 0 || !*increase && strcmp(buffer.typeTransport, filteredArrayTransportations[cell + 1].typeTransport) < 0)
										swap = 1;
									break;
								case 10:
									if (*increase && buffer.priceGeneral > filteredArrayTransportations[cell + 1].priceGeneral || (!*increase && buffer.priceGeneral < filteredArrayTransportations[cell + 1].priceGeneral))
										swap = 1;
								case 11:
									if (*increase && buffer.fuelConsumed > filteredArrayTransportations[cell + 1].fuelConsumed || (!*increase && buffer.fuelConsumed < filteredArrayTransportations[cell + 1].fuelConsumed))
										swap = 1;
								case 12:
									if (*increase && buffer.distanceTraveled > filteredArrayTransportations[cell + 1].distanceTraveled || (!*increase && buffer.distanceTraveled < filteredArrayTransportations[cell + 1].distanceTraveled))
										swap = 1;
								case 13:
									if (*increase && buffer.numberProducts > filteredArrayTransportations[cell + 1].numberProducts || (!*increase && buffer.numberProducts < filteredArrayTransportations[cell + 1].numberProducts))
										swap = 1;
								case 14:
									if (*increase && buffer.numberStops > filteredArrayTransportations[cell + 1].numberStops || (!*increase && buffer.numberStops < filteredArrayTransportations[cell + 1].numberStops))
										swap = 1;
								case 15:
									if (*increase && buffer.id > filteredArrayTransportations[cell + 1].id || (!*increase && buffer.id < filteredArrayTransportations[cell + 1].id))
										swap = 1;
									if (swap) {
										struct ProductTransportation buffer = filteredArrayTransportations[cell];
										filteredArrayTransportations[cell] = filteredArrayTransportations[cell + 1];
										filteredArrayTransportations[cell + 1] = buffer;
									}
								}
							}
					}
					clearConsole();
					printLine();
					printf("\n|ид");
					printCharacterNConsole(' ', LENGTHIDTABLE - 2);
					printf("|страна>");
					printCharacterNConsole(' ', LENGTHCOUNTRYTABLE - 7);
					printf("|страна<");
					printCharacterNConsole(' ', LENGTHCOUNTRYTABLE - 7);
					printf("|город>");
					printCharacterNConsole(' ', LENGTHTOWNTABLE - 6);
					printf("|город<");
					printCharacterNConsole(' ', LENGTHTOWNTABLE - 6);
					printf("|дата>");
					printCharacterNConsole(' ', LENGTHDATETABLE - 5);
					printf("|дата<");
					printCharacterNConsole(' ', LENGTHDATETABLE - 5);
					printf("|время>");
					printCharacterNConsole(' ', LENGTHTIMETABLE - 6);
					printf("|время<");
					printCharacterNConsole(' ', LENGTHTIMETABLE - 6);
					printf("|ТС");
					printCharacterNConsole(' ', LENGTHTYPETRANSPORTTABLE - 2);
					printf("|грузов");
					printCharacterNConsole(' ', LENGTHPRODUCTSTABLE - 6);
					printf("|остановок");
					printCharacterNConsole(' ', LENGTHNUMBERSTOPSTABLE - 9);
					printf("|стоимость");
					printCharacterNConsole(' ', LENGTHGENERALPRICETABLE - 9);
					printf("|топливо");
					printCharacterNConsole(' ', LENGTHFUELCONSUMED - 7);
					printf("|Расстояние");
					printCharacterNConsole(' ', LENGTHDISTANCETRAVELEDTABLE - 10);
					printf("|\n");
					printLine();
					printf("\n");
					for (int _productTransportation = 0; _productTransportation < counter; _productTransportation++) {
						struct ProductTransportation* currentPT = &(filteredArrayTransportations[_productTransportation]);
						char* id = convertIntegerToPtrChar(currentPT->id),
							* countryOrigin = currentPT->countryOrigin,
							* countryDelivery = currentPT->countryDelivery,
							* townOrigin = currentPT->townOrigin,
							* townDelivery = currentPT->townDelivery,
							* dateOrigin = currentPT->dateOrigin,
							* dateDelivery = currentPT->dateDelivery,
							* timeOrigin = currentPT->timeOrigin,
							* timeDelivery = currentPT->timeDelivery,
							* typeTransport = currentPT->typeTransport,
							* numberProducts = convertIntegerToPtrChar(currentPT->numberProducts),
							* numberStops = convertIntegerToPtrChar(currentPT->numberStops),
							* priceGeneral = convertFloatToPtrChar(currentPT->priceGeneral),
							* fuelConsumed = convertFloatToPtrChar(currentPT->fuelConsumed),
							* distanceTraveled = convertFloatToPtrChar(currentPT->distanceTraveled);
						int lengthId = (int)strlen(id), indexId = 0,
							lengthCountryOrigin = (int)strlen(countryOrigin), indexCountryOrigin = 0,
							lengthCountryDelivery = (int)strlen(countryDelivery), indexCountryDelivery = 0,
							lengthTownOrigin = (int)strlen(townOrigin), indexTownOrigin = 0,
							lengthTownDelivery = (int)strlen(townDelivery), indexTownDelivery = 0,
							lengthDateOrigin = (int)strlen(dateOrigin), indexDateOrigin = 0,
							lengthDateDelivery = (int)strlen(dateDelivery), indexDateDelivery = 0,
							lengthTimeOrigin = (int)strlen(timeOrigin), indexTimeOrigin = 0,
							lengthTimeDelivery = (int)strlen(timeDelivery), indexTimeDelivery = 0,
							lengthTypeTransport = (int)strlen(typeTransport), indexTypeTransport = 0,
							lengthNumberProducts = (int)strlen(numberProducts), indexNumberProducts = 0,
							lengthNumberStops = (int)strlen(numberStops), indexNumberStops = 0,
							lengthPriceGeneral = (int)strlen(priceGeneral), indexPriceGeneral = 0,
							lengthFuelConsumed = (int)strlen(fuelConsumed), indexFuelConsumed = 0,
							lengthDistanceTraveled = (int)strlen(distanceTraveled), indexDistanceTraveled = 0;
						while (lengthId > indexId + 1 || lengthCountryOrigin > indexCountryOrigin + 1 ||
							lengthCountryDelivery > indexCountryDelivery + 1 || lengthTownOrigin > indexTownOrigin + 1 ||
							lengthTownDelivery > indexTownDelivery + 1 || lengthDateOrigin > indexDateOrigin + 1 ||
							lengthDateDelivery > indexDateDelivery + 1 || lengthTimeOrigin > indexTimeOrigin + 1 ||
							lengthTimeDelivery > indexTimeDelivery + 1 || lengthTypeTransport > indexTypeTransport + 1 ||
							lengthNumberProducts > indexNumberProducts + 1 || lengthNumberStops > indexNumberStops + 1 ||
							lengthPriceGeneral > indexPriceGeneral + 1 || lengthFuelConsumed > indexFuelConsumed + 1 ||
							lengthDistanceTraveled > indexDistanceTraveled + 1) {
							printCell(&id, LENGTHIDTABLE, lengthId, &indexId);
							printCell(&countryOrigin, LENGTHCOUNTRYTABLE, lengthCountryOrigin, &indexCountryOrigin);
							printCell(&countryDelivery, LENGTHCOUNTRYTABLE, lengthCountryDelivery, &indexCountryDelivery);
							printCell(&townOrigin, LENGTHTOWNTABLE, lengthTownOrigin, &indexTownOrigin);
							printCell(&townDelivery, LENGTHTOWNTABLE, lengthTownDelivery, &indexTownDelivery);
							printCell(&dateOrigin, LENGTHDATETABLE, lengthDateOrigin, &indexDateOrigin);
							printCell(&dateDelivery, LENGTHDATETABLE, lengthDateDelivery, &indexDateDelivery);
							printCell(&timeOrigin, LENGTHTIMETABLE, lengthTimeOrigin, &indexTimeOrigin);
							printCell(&timeDelivery, LENGTHTIMETABLE, lengthTimeDelivery, &indexTimeDelivery);
							printCell(&typeTransport, LENGTHTYPETRANSPORTTABLE, lengthTypeTransport, &indexTypeTransport);
							printCell(&numberProducts, LENGTHPRODUCTSTABLE, lengthNumberProducts, &indexNumberProducts);
							printCell(&numberStops, LENGTHNUMBERSTOPSTABLE, lengthNumberStops, &indexNumberStops);
							printCell(&priceGeneral, LENGTHGENERALPRICETABLE, lengthPriceGeneral, &indexPriceGeneral);
							printCell(&fuelConsumed, LENGTHFUELCONSUMED, lengthFuelConsumed, &indexFuelConsumed);
							printCell(&distanceTraveled, LENGTHDISTANCETRAVELEDTABLE, lengthDistanceTraveled, &indexDistanceTraveled);
							printf("|\n");
						}
						printLine();
						printf("\n");
						//чистка
					}
					pressAnyButton();
				}
				else {
					clearConsole();
					printf("Таблица пуста!\n");
					pressAnyButton();
				}
				if (transportations)
					free(transportations);
				if (filteredArrayTransportations)
					free(filteredArrayTransportations);
				break;
			}
		}
	}
}