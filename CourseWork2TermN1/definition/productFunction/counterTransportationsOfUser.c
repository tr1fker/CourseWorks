#include <stdlib.h>
#include <malloc.h>

#include "../../include/struct.h"
#include "../../include/input.h"

int counterTransportationsOfUser(int currentId) {
	struct Transportations* transportations = NULL;
	int counterTransportations = 0;
	if (inputFileTransportations(&transportations, &counterTransportations)) {
		for (int _transportations = 0; _transportations < counterTransportations; _transportations++)
			if (currentId == transportations[_transportations].id) {
				int number = transportations[_transportations].number;
				free(transportations);
				return number;
			}
	}
	free(transportations);
	return 0;
}