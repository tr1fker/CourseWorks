#include <stdlib.h>
#include <malloc.h>

#include "../../include/struct.h"
#include "../../include/input.h"

int findMaxNumberProductsIdTransportationsOfUsers(int currentId, int* idPtr) {
	struct Transportations* transportations = NULL;
	int counterTransportations = 0, best = -1;
	int id = 1;
	if (inputFileTransportations(&transportations, &counterTransportations)) {
		for (int _transportations = 0; _transportations < counterTransportations; _transportations++) {
			for (int _productTransportation = 0; _productTransportation < transportations[_transportations].number; _productTransportation++) {
				if (best < transportations[_transportations].number)
					best = transportations[_transportations].number, id = transportations[_transportations].id;
			}
		}
	}
	if (transportations)
		free(transportations);
	*idPtr = id;
	return best;
}