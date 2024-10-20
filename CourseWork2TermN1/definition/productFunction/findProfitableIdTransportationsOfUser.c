#include <stdlib.h>
#include <malloc.h>

#include "../../include/struct.h"
#include "../../include/input.h"

float findProfitableIdTransportationsOfUser(int currentId, int* idPtr) {
	struct Transportations* transportations = NULL;
	int counterTransportations = 0;
	if (inputFileTransportations(&transportations, &counterTransportations)) {
		for (int _transportations = 0; _transportations < counterTransportations; _transportations++)
			if (currentId == transportations[_transportations].id) {
				if (!transportations[_transportations].number) {
					free(transportations);
					return -1;
				}
				float best = 0;
				int id = 1;
				for (int _productTransportation = 0; _productTransportation < transportations[_transportations].number; _productTransportation++) {
					float currentPro = transportations[_transportations].arrayProductTransportation[_productTransportation].priceGeneral / (transportations[_transportations].arrayProductTransportation[_productTransportation].distanceTraveled / 1000);
					if (best < currentPro)
						best = currentPro, id = transportations[_transportations].arrayProductTransportation[_productTransportation].id;
				}
				free(transportations);
				*idPtr = id;
				return best;
			}
	}
	free(transportations);
	return -1;
}