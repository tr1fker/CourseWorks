#include <malloc.h>
#include <stdio.h>

#include "../../include/constants.h"
#include "../../include/functions.h"
#include "../../include/input.h"
#include "../../include/struct.h"
#include "../../include/check.h"
#include "../../include/convert.h"
#include "../../include/output.h"

void createTransportationMenu(int currentId) {
	int menuIsWork = 1;
	struct ProductTransportation productTransportation;
	productTransportation.countryOrigin = NULL,
		productTransportation.countryDelivery = NULL,
		productTransportation.townOrigin = NULL,
		productTransportation.townDelivery = NULL,
		productTransportation.dateOrigin = NULL,
		productTransportation.dateDelivery = NULL,
		productTransportation.timeOrigin = NULL,
		productTransportation.timeDelivery = NULL,
		productTransportation.addressOrigin = NULL,
		productTransportation.addressDelivery = NULL,
		productTransportation.typeTransport = NULL;
	while (menuIsWork) {
		clearConsole();
		int choice = inputFirstNatural(18, CREATEPRODUCTTRANSPORTATIONMENU);
		switch (choice) {
		case 1: {
			clearConsole();
			printf("¬ведите страну отправки:");
			char* countryOrigin = inputWord(MAXLENGTHCREATEPRODUCT);
			if (countryOrigin && isCapitalizedWord(countryOrigin)) {
				if (productTransportation.countryOrigin)
					free(productTransportation.countryOrigin);
				productTransportation.countryOrigin = countryOrigin;
			}
			else {
				printf("\n¬ведена некорретна€ страна!\n");
				pressAnyButton();
				if (productTransportation.countryOrigin)
					free(productTransportation.countryOrigin);
			}
		}
			break;
		case 2: {
			clearConsole();
			printf("¬ведите страну отправки:");
			char* countryDelivery = inputWord(MAXLENGTHCREATEPRODUCT);
			if (countryDelivery && isCapitalizedWord(countryDelivery)) {
				if (productTransportation.countryDelivery)
					free(productTransportation.countryDelivery);
				productTransportation.countryDelivery = countryDelivery;
			}
			else {
				printf("\n¬ведена некорретна€ страна!\n");
				pressAnyButton();
				if (countryDelivery)
					free(countryDelivery);
			}
		}
			break;
		case 3:
		{
			clearConsole();
			printf("¬ведите город отправки:");
			char* townOrigin = inputWord(MAXLENGTHCREATEPRODUCT);
			if (townOrigin && isCapitalizedWord(townOrigin)) {
				if (productTransportation.townOrigin)
					free(productTransportation.townOrigin);
				productTransportation.townOrigin = townOrigin;
			}
			else {
				printf("\n¬веден некорретный город!\n");
				pressAnyButton();
				if (townOrigin)
					free(townOrigin);
			}
		}
			break;
		case 4:
		{
			clearConsole();
			printf("¬ведите город доставки:");
			char* townDelivery = inputWord(MAXLENGTHCREATEPRODUCT);
			if (townDelivery && isCapitalizedWord(townDelivery)) {
				if (productTransportation.townDelivery)
					free(productTransportation.townDelivery);
				productTransportation.townDelivery = townDelivery;
			}
			else {
				printf("\n¬веден некорретный город!\n");
				pressAnyButton();
				if (townDelivery)
					free(townDelivery);
			}
		}
			break;
		case 5:
			clearConsole();
			printf("¬ведите адрес отправки:");
			if (productTransportation.addressOrigin)
				free(productTransportation.addressOrigin);
			productTransportation.addressOrigin = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 6:
			clearConsole();
			printf("¬ведите адрес доставки:");
			if (productTransportation.addressDelivery)
				free(productTransportation.addressDelivery);
			productTransportation.addressDelivery = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 7:
			clearConsole();
			printf("¬ведите дату отправки:");
			char* dateOrigin = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			if (isDate(dateOrigin)) {
				if (productTransportation.dateOrigin)
					free(productTransportation.dateOrigin);
				productTransportation.dateOrigin = dateOrigin;
			}
			else if (dateOrigin) {
				printf("\n¬ведена некорретна€ дата!\n"); 
				pressAnyButton();
				free(dateOrigin);
			}
			break;
		case 8:
			clearConsole();
			printf("¬ведите дату доставки:");
			char* dateDelivery = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			if (isDate(dateDelivery)) {
				if (productTransportation.dateDelivery)
					free(productTransportation.dateDelivery);
				productTransportation.dateDelivery = dateDelivery;
			}
			else if (dateDelivery) {
				printf("\n¬ведена некорретна€ дата!\n");
				pressAnyButton();
				free(dateDelivery);
			}
			break;
		case 9:
			clearConsole();
			printf("¬ведите врем€ отправки:");
			char* timeOrigin = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			if (isTime(timeOrigin)) {
				if (productTransportation.timeOrigin)
					free(productTransportation.timeOrigin);
				productTransportation.timeOrigin = timeOrigin;
			}
			else if (timeOrigin) {
				printf("\n¬ведено некорретное врем€!\n");
				pressAnyButton();
				free(timeOrigin);
			}
			break;
		case 10:
			clearConsole();
			printf("¬ведите врем€ доставки:");
			char* timeDelivery = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			if (isTime(timeDelivery)) {
				if (productTransportation.timeDelivery)
					free(productTransportation.timeDelivery);
				productTransportation.timeDelivery = timeDelivery;
			}
			else if (timeDelivery) {
				printf("\n¬ведено некорретное врем€!\n");
				pressAnyButton();
				free(timeDelivery);
			}
			break;
		case 11:
			clearConsole();
			printf("¬ведите тип “—:");
			if (productTransportation.typeTransport)
				free(productTransportation.typeTransport);
			productTransportation.typeTransport = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			break;
		case 12:
			clearConsole();
			printf("¬ведите кол-во затраченного топлива:");
			char* fuelConsumed = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			if (isFloat(fuelConsumed)) {
				productTransportation.fuelConsumed = convertPtrCharToFloat(fuelConsumed);
			}
			else {
				printf("\n¬ведена некорретна€ запись!\n");
				pressAnyButton();
			}
			if (fuelConsumed)
				free(fuelConsumed);
			break;
		case 13:
			clearConsole();
			printf("¬ведите пройденное рассто€ние:");
			char* distanceTraveled = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			if (isFloat(distanceTraveled)) {
				productTransportation.distanceTraveled = convertPtrCharToFloat(distanceTraveled);
			}
			else {
				printf("\n¬ведена некорретна€ запись!\n");
				pressAnyButton();
			}
			if (distanceTraveled)
				free(distanceTraveled);
			break;
		case 14:
			clearConsole();
			printf("¬ведите кол-во остановок:");
			productTransportation.numberStops = inputInteger(POSITIVE);
			break;
		case 15:
			clearConsole();
			printf("¬ведите общие затраты на перевозку:");
			char* priceGeneral = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
			if (isFloat(priceGeneral)) {
				productTransportation.priceGeneral = convertPtrCharToFloat(priceGeneral);
			}
			else {
				printf("\n¬ведена некорретна€ запись!\n");
				pressAnyButton();
			}
			if (priceGeneral)
				free(priceGeneral);
			break;
		case 16:
			clearConsole();
			printf("¬ведите кол-во рализчных грузов:");
			productTransportation.numberProducts = inputInteger(POSITIVE);
			if (!productTransportation.numberProducts) {
				printf("\n¬ведена некорретна€ запись!\n");
				pressAnyButton();
			}
			else {
				productTransportation.products = (struct Product*)malloc(sizeof(struct Product) * productTransportation.numberProducts);
				int currentCountProducts = 0;
				if (productTransportation.products) {
					int creatingProductIs = 1;
					for (int _product = 0; _product < productTransportation.numberProducts; _product++) {
						struct Product* currentProductPtr = &productTransportation.products[_product];
						currentProductPtr->codeIdentification = 0;
						currentProductPtr->number = 0;
						currentProductPtr->weight = 0;
						currentProductPtr->name = NULL;
					}
					while (creatingProductIs && currentCountProducts != productTransportation.numberProducts) {
						int choice = inputFirstNatural(8, CREATEPRODUCTSMENU);
						struct Product* currentProductPtr = &productTransportation.products[currentCountProducts];
						currentProductPtr->id = currentCountProducts + 1;
						switch (choice) {
						case 1:
							clearConsole();
							printf("¬ведите название груза:");
							currentProductPtr->name = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
							break;
						case 2:
							clearConsole();
							printf("¬ведите индентификационный номер груза:");
							currentProductPtr->codeIdentification = inputInteger(POSITIVE);
							break;
						case 3:
							clearConsole();
							printf("¬ведите вес груза:");
							char* weightProduct = getPressedCharacters(MAXLENGTHCREATEPRODUCT);
							if (isFloat(weightProduct)) {
								currentProductPtr->weight = convertPtrCharToFloat(weightProduct);
								free(weightProduct);
							}
							else if (weightProduct) {
								printf("\n¬ведена некорретна€ запись!\n");
								pressAnyButton();
								free(weightProduct);
							}
							break;
						case 4:
							clearConsole();
							printf("¬ведите кол-во грузов:");
							currentProductPtr->number = inputInteger(POSITIVE);
							break;
						case 5:
							creatingProductIs = 0;
							productTransportation.numberProducts = currentCountProducts;
							break;
						case 6:
							creatingProductIs = 0;
							productTransportation.numberProducts = 0;
							free(productTransportation.products);
							break;
						case 7:
							if (currentProductPtr->name == NULL)
								printf("\n¬ведите название!\n");
							else if (currentProductPtr->codeIdentification == 0)
								printf("\n¬ведите индефикационный номер!\n");
							else if (currentProductPtr->weight == 0)
								printf("\n¬ведите вес груза!\n");
							else if (!currentProductPtr->number)
								printf("\n¬ведите кол-во грузов!\n");
							else {
								printf("\n√руз успешно создан!(#%d груз - #%d)\n", ++currentCountProducts, productTransportation.numberProducts);
							}
							pressAnyButton();
							break;
						}
					}
				}
				else {
					printf("\nЌе удалось выделить пам€ть в CreateProductTransportationMenu!\n");
					pressAnyButton();
				}
			}
			break;
		case 17:
			menuIsWork = 0;
			break;
		case 18:
			if (!productTransportation.countryOrigin)
				printf("\n¬ведите страну отправки!\n");
			else if (!productTransportation.countryDelivery)
				printf("\n¬ведите страну доставки!\n");
			else if (!productTransportation.townOrigin)
				printf("\n¬ведите город отправки!\n");
			else if (!productTransportation.townDelivery)
				printf("\n¬ведите город доставки!\n");
			else if (!productTransportation.addressOrigin)
				printf("\n¬ведите адрес отправки!\n");
			else if (!productTransportation.addressDelivery)
				printf("\n¬ведите адрес доставки!\n");
			else if (!productTransportation.dateOrigin)
				printf("\n¬ведите дату отправки!\n");
			else if (!productTransportation.dateDelivery)
				printf("\n¬ведите дату доставки!\n");
			else if (!productTransportation.timeOrigin)
				printf("\n¬ведите врем€ отправки!\n");
			else if (!productTransportation.timeDelivery)
				printf("\n¬ведите врем€ доставки!\n");
			else if (productTransportation.distanceTraveled == 0)
				printf("\n¬ведите пройденное рассто€ние!\n");
			else if (productTransportation.fuelConsumed == 0)
				printf("\n¬ведите затраченное топливо!\n");
			else if (productTransportation.numberProducts == 0)
				printf("\n¬ведите количество продуктов!\n");
			else if (!productTransportation.typeTransport)
				printf("\n¬ведите тип транспорта!\n");
			else if (productTransportation.priceGeneral == 0)
				printf("\n¬ведите стоимость перевозки!\n");
			else {
				struct Transportations* transportations = NULL;
				int countTransportations = 0;
				if (inputFileTransportations(&transportations, &countTransportations)) {
					int addedPT = 0;
					for (int _transportations = 0; _transportations < countTransportations; _transportations++) {
						if (transportations[_transportations].id == currentId) {
							struct ProductTransportation* newArrayProductTransportation = (struct ProductTransportation*)malloc(sizeof(struct ProductTransportation) * (transportations[_transportations].number + 1));
							if (newArrayProductTransportation) {
								for (int _PT = 0; _PT < transportations[_transportations].number; _PT++) {
									newArrayProductTransportation[_PT] = transportations[_transportations].arrayProductTransportation[_PT];
								}
								int freeId = 0, idFinded = 0;
								while (!idFinded) {
									freeId++;
									if (!transportations[_transportations].number)
										idFinded = 1;
									for (int _productTransportation = 0; _productTransportation < transportations[_transportations].number; _productTransportation++)
										if (transportations[_transportations].arrayProductTransportation[_productTransportation].id == freeId) {
											break;
										}
										else if (_productTransportation + 1 == transportations[_transportations].number)
											idFinded = 1;
								}
								productTransportation.id = freeId;
								newArrayProductTransportation[(transportations[_transportations].number)++] = productTransportation;
								addedPT = 1;
								free(transportations[_transportations].arrayProductTransportation);
								transportations[_transportations].arrayProductTransportation = newArrayProductTransportation;
							}
							else {
								//problem
							}
							break;
						}
					}
					if (!addedPT) {
						struct Transportations* newTransportations = (struct Transportations*)malloc(sizeof(struct Transportations) * (countTransportations + 1));
						if (newTransportations) {
							for (int _transportations = 0; _transportations < countTransportations; _transportations++) {
								newTransportations[_transportations] = transportations[_transportations];
							}
							/*int freeId = 0, idFinded = 0;
							while (!idFinded) {
								freeId++;
								if (!countTransportations)
									idFinded = 1;
								for (int _transportations = 0; _transportations < countTransportations; _transportations++)
									if (newTransportations[_transportations].id == freeId) {
										break;
									}
									else if (_transportations + 1 == countTransportations)
										idFinded = 1;
							}*/
							newTransportations[countTransportations].arrayProductTransportation = (struct ProductTransportation*)malloc(sizeof(struct ProductTransportation));
							if (newTransportations[countTransportations].arrayProductTransportation) {
								newTransportations[countTransportations].id = currentId;
								newTransportations[countTransportations].number = 1;
								productTransportation.id = 1;
								newTransportations[countTransportations++].arrayProductTransportation = &productTransportation;
								free(transportations);
								transportations = newTransportations;
							}
							else {
								printf("\nЌе удалось выделить пам€ть в createProductTransportation!\n");
								break;
							}
						}
						else {
							printf("\nЌе удалось выделить пам€ть в createProductTransportation!\n");
							break;
						}
					}
					if (saveFileTransportations(&transportations, &countTransportations)) {
						printf("\n√рузова€ перевозка успешно создана!\n");
						menuIsWork = 0;
					}
				}
			}
			pressAnyButton();
			break;
		}
	}
}