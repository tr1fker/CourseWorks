#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "../../include/struct.h"
#include "../../include/functions.h"

int saveFileTransportations(struct Transportations** transportations, int* countTransportations) {
	FILE* transportationsFile;
	if (!fopen_s(&transportationsFile, "file/transportations.txt", "w+t")) {
		if (!fprintf(transportationsFile, "%d\n", *countTransportations)) {
			printf("\nНе удалось записать в файл transportations!");
			pressAnyButton();
			fclose(transportationsFile);
			return 0;
		}
		for (int _transportations = 0; _transportations < *countTransportations; _transportations++) {
			if (!fprintf(transportationsFile, "%d %d\n", (*transportations)[_transportations].id, (*transportations)[_transportations].number)) {
				printf("\nНе удалось записать в файл transportations!");
				pressAnyButton();
				fclose(transportationsFile);
				return 0;
			}
			for (int _transportation = 0; _transportation < (*transportations)[_transportations].number; _transportation++) {
				if ((*transportations)[_transportations].arrayProductTransportation) {
					struct ProductTransportation* currentPT = &((*transportations)[_transportations].arrayProductTransportation[_transportation]);
					if (!fprintf(transportationsFile, "%s %s %s %s %s %s %s %s %s %s %s\n%f %f %f\n%d %d %d\n",
						currentPT->countryOrigin, currentPT->countryDelivery,
						currentPT->townOrigin, currentPT->townDelivery,
						currentPT->addressOrigin, currentPT->addressDelivery,
						currentPT->dateOrigin, currentPT->dateDelivery,
						currentPT->timeOrigin, currentPT->timeDelivery,
						currentPT->typeTransport, currentPT->priceGeneral,
						currentPT->fuelConsumed, currentPT->distanceTraveled,
						currentPT->id, currentPT->numberProducts, currentPT->numberStops)) {
						printf("\nНе удалось прочитать файл transportations!");
						pressAnyButton();
						fclose(transportationsFile);
						return 0;
					}
					else {
						for (int _product = 0; _product < currentPT->numberProducts; _product++) {
							struct Product* currentProductPtr = &currentPT->products[_product];
							if (fprintf(transportationsFile, "%d %d %d %f %s\n", currentProductPtr->id,
								currentProductPtr->codeIdentification, currentProductPtr->number,
								currentProductPtr->weight, currentProductPtr->name)) {
								continue;
							}
							else
								printf("\nНе удалось прочитать файл productsTransportation!\n");
						}
					}
				}
			}
		}
		fclose(transportationsFile);
		return 1;
	}
	printf("\nНе удалось открыть файл transportations!");
	pressAnyButton();
	return 0;
}