#ifndef STRUCT_H
#define STRUCT_H

#include "../include/constants.h"

struct User {
	int id, privilege, blocked;
	char* login, *solid, *hash;
};

struct Product {
	int id, codeIdentification, number;
	float weight;
	char* name;
};

struct ProductTransportation {
	int id, numberProducts, numberStops;
	float priceGeneral, fuelConsumed, distanceTraveled;
	char* typeTransport, *countryOrigin, *countryDelivery, *townOrigin, *townDelivery, *addressOrigin, *addressDelivery,
		*dateOrigin, *dateDelivery, *timeOrigin, *timeDelivery;
	struct Product* products;
};

struct Transportations {
	int id, number;
	struct ProductTransportation* arrayProductTransportation;
};

#endif STRUCT_H