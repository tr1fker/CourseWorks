#include <stdlib.h>
#include <malloc.h>

#include "../../include/struct.h"
#include "../../include/input.h"

float findProfitableIdTransportationsOfUsers(int currentId, int* idPtr) {
	struct Transportations* transportations = NULL;
	int counterTransportations = 0;
	float best = -1;
	int id = 1;
	if (inputFileTransportations(&transportations, &counterTransportations)) {
		for (int _transportations = 0; _transportations < counterTransportations; _transportations++) {
			for (int _productTransportation = 0; _productTransportation < transportations[_transportations].number; _productTransportation++) {
				float currentPro = transportations[_transportations].arrayProductTransportation[_productTransportation].priceGeneral / (transportations[_transportations].arrayProductTransportation[_productTransportation].distanceTraveled / 1000);
				if (best < currentPro)
					best = currentPro, id = transportations[_transportations].id;
			}
		}
	}
	if (transportations)
		free(transportations);
	*idPtr = id;
	return best;
}