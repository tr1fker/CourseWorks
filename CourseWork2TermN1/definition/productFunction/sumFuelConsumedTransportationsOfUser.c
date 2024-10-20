#include <stdlib.h>
#include <malloc.h>

#include "../../include/struct.h"
#include "../../include/input.h"

float sumFuelConsumedTransportationsOfUser(int currentId) {
	struct Transportations* transportations = NULL;
	int counterTransportations = 0;
	if (inputFileTransportations(&transportations, &counterTransportations)) {
		for (int _transportations = 0; _transportations < counterTransportations; _transportations++)
			if (currentId == transportations[_transportations].id) {
				if (!transportations[_transportations].number) {
					free(transportations);
					return -1;
				}
				float sum = 0;
				for (int _productTransportation = 0; _productTransportation < transportations[_transportations].number; _productTransportation++)
					sum += transportations[_transportations].arrayProductTransportation[_productTransportation].fuelConsumed;
				free(transportations);
				return sum;
			}
	}
	free(transportations);
	return 0;
}