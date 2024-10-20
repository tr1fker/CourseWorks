#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#include "../../include/functions.h"
#include "../../include/input.h"
#include "../../include/convert.h"
#include "../../include/struct.h"
#include "../../include/output.h"

void deleteTransportation(int currentId) {
	clearConsole();
	printf("������� �� �������� ���������:");
	int id = inputInteger(POSITIVE);
	struct Transportations* transportations = NULL;
	int counterTransportations = 0;
	if (inputFileTransportations(&transportations, &counterTransportations)) {
		for (int _transportations = 0; _transportations < counterTransportations; _transportations++)
			if (transportations[_transportations].id == currentId) {
				if (!transportations[_transportations].number)
					printf("\n�������� ��������� �� ������ �� �� ����������!\n");
				for (int _transportation = 0; _transportation < transportations[_transportations].number; _transportation++)
					if (transportations[_transportations].arrayProductTransportation[_transportation].id == id) {
						printf("\n�����������[Enter], �����[����� ������ �������].\n");
						if (getPressedCharacter() == 13) {
							printf("\n�������� ��������� ������� �������!\n");
							struct ProductTransportation* newProductTransportations = (struct ProductTransportation*)malloc(sizeof(struct ProductTransportation) * (transportations[_transportations].number - 1));
							if (newProductTransportations) {
								int counter = 0;
								for (int _productTransportation = 0; _productTransportation < transportations[_transportations].number; _productTransportation++) {
									if (transportations[_transportations].arrayProductTransportation[_productTransportation].id != id)
										newProductTransportations[counter++] = transportations[_transportations].arrayProductTransportation[_productTransportation];
								}
								transportations[_transportations].number--;
								free(transportations[_transportations].arrayProductTransportation);
								transportations[_transportations].arrayProductTransportation = newProductTransportations;
								saveFileTransportations(&transportations, &counterTransportations);
							}
							else
								printf("\n�� ������� �������� ������ � deleteTransportation!\n");
						}
						else
							printf("\n�������� ��������� ������� �� �������!\n");
						break;
					}
					else if (_transportation + 1 == transportations[_transportations].number)
						printf("\n�������� ��������� �� ������ �� �� ����������!\n");
				break;
			}
			else if (_transportations + 1 == counterTransportations)
				printf("\n� ��� ��� �������� ���������!\n");
	}
	pressAnyButton();
}