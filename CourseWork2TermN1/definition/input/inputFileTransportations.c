#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/input.h"
#include "../../include/struct.h"
#include "../../include/functions.h"
#include "../../include/convert.h"

int inputFileTransportations(struct Transportations** transportations, int* countTransportations) {
	FILE* transportationsFile;
	if (!fopen_s(&transportationsFile, "file/transportations.txt", "r+t")) {
		if (!fscanf_s(transportationsFile, "%d", countTransportations)) {
			printf("\nНе удалось прочитать файл transportations!\n");
			pressAnyButton();
			return 0;
		}
		if (*transportations = (struct Transportations*)malloc(sizeof(struct Transportations) * *countTransportations)) {
			for (int _transportations = 0; _transportations < *countTransportations; _transportations++) {
				if (!fscanf(transportationsFile, "%d%d", &(*transportations)[_transportations].id, &(*transportations)[_transportations].number)) {
					printf("\nНе удалось прочитать файл transportations!\n");
					pressAnyButton();
					return 0;
				}
				if ((*transportations)[_transportations].arrayProductTransportation = (struct ProductTransportation*)malloc(sizeof(struct ProductTransportation) * (*transportations)[_transportations].number)) {
					for (int _transportation = 0; _transportation < (*transportations)[_transportations].number; _transportation++) {
						struct ProductTransportation* currentPT = &((*transportations)[_transportations].arrayProductTransportation[_transportation]);
						currentPT->products = NULL;
						currentPT->countryOrigin = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->countryDelivery = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->townOrigin = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->townDelivery = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->addressOrigin = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->addressDelivery = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->dateOrigin = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->dateDelivery = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->timeOrigin = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->timeDelivery = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						currentPT->typeTransport = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						char* priceGeneral = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1)),
							* fuelConsumed = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1)),
							* distanceTraveled = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
						if (currentPT->countryOrigin && currentPT->countryDelivery && currentPT->townOrigin &&
							currentPT->townDelivery && currentPT->addressOrigin && currentPT->addressDelivery &&
							currentPT->dateOrigin && currentPT->dateDelivery && currentPT->timeOrigin &&
							currentPT->timeDelivery && currentPT->typeTransport && priceGeneral &&
							fuelConsumed && distanceTraveled) {
							currentPT->countryOrigin[0] = '\0';
							currentPT->countryDelivery[0] = '\0';
							currentPT->townOrigin[0] = '\0';
							currentPT->townDelivery[0] = '\0';
							currentPT->addressOrigin[0] = '\0';
							currentPT->addressDelivery[0] = '\0';
							currentPT->dateOrigin[0] = '\0';
							currentPT->dateDelivery[0] = '\0';
							currentPT->timeOrigin[0] = '\0';
							currentPT->timeDelivery[0] = '\0';
							currentPT->typeTransport[0] = '\0';
							priceGeneral[0] = '\0';
							fuelConsumed[0] = '\0';
							distanceTraveled[0] = '\0';
							if (fscanf(transportationsFile, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%d%d%d",
								currentPT->countryOrigin, currentPT->countryDelivery,
								currentPT->townOrigin, currentPT->townDelivery,
								currentPT->addressOrigin, currentPT->addressDelivery,
								currentPT->dateOrigin, currentPT->dateDelivery,
								currentPT->timeOrigin, currentPT->timeDelivery,
								currentPT->typeTransport, priceGeneral,
								fuelConsumed, distanceTraveled,
								&currentPT->id, &currentPT->numberProducts, &currentPT->numberStops)) {
								currentPT->products = (struct Product*)malloc(sizeof(struct Product) * currentPT->numberProducts);
								if (currentPT->products) {
									currentPT->priceGeneral = convertPtrCharToFloat(priceGeneral);
									currentPT->fuelConsumed = convertPtrCharToFloat(fuelConsumed);
									currentPT->distanceTraveled = convertPtrCharToFloat(distanceTraveled);
									free(priceGeneral);
									free(fuelConsumed);
									free(distanceTraveled);
									for (int _product = 0; _product < currentPT->numberProducts; _product++) {
										struct Product* currentProductPtr = &currentPT->products[_product];
										char* weight = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
										currentProductPtr->name = (char*)malloc(sizeof(char) * (MAXLENGTHCREATEPRODUCT + 1));
										if (weight && currentProductPtr->name) {
											if (fscanf(transportationsFile, "%d%d%d%s%s", &currentProductPtr->id,
												&currentProductPtr->codeIdentification, &currentProductPtr->number,
												weight, currentProductPtr->name)) {
												currentProductPtr->weight = convertPtrCharToFloat(weight);
												free(weight);
												continue;
											}
											else
												printf("\nНе удалось прочитать файл prductsTransportation!\n");
										}
										else
											printf("\nНе удалось выделить память в inputFileTransportations!\n");
										//вылет
									}
									continue;
								}
								else
									printf("\nНе удалось прочитать файл prductsTransportation!\n");
							}
							else
								printf("\nНе удалось прочитать файл productsTransportation пользователя!");
						}
						else
							printf("\nНе удалось выделить память для пользователя productTransportation!\n");
						//очистка
						fclose(transportationsFile);
						pressAnyButton();
						return 0;
					}
				}
				else 
					printf("\nНе удалось выделить память для пользователя productTransportation!\n");
			}
		}
		else {
			printf("\nНе удалось выделить память для массива arrayProductsTransportation!\n");
			fclose(transportationsFile);
			pressAnyButton();
			return 0;
		}
		fclose(transportationsFile);
		return 1;
	}
	printf("\nНе удалось открыть файл с productTransportation!");
	pressAnyButton();
	return 0;
}