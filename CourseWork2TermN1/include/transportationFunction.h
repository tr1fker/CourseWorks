#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

void createTransportationMenu(int currentId);
void deleteTransportation(int currentId);
int counterTransportationsOfUser(int currentId);
float sumPricesTransportationsOfUser(int currentId);
float sumDistanceTraveledTransportationsOfUser(int currentId);
float sumFuelConsumedTransportationsOfUser(int currentId);
float findProfitableIdTransportationsOfUser(int currentId, int* idPtr);
float findProfitableIdTransportationsOfUsers(int currentId, int* idPtr);
int findMaxNumberProductsIdTransportationsOfUsers(int currentId, int* idPtr);

#endif TRANSPORTATION_H