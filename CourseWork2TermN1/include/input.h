#ifndef INPUT_H
#define INPUT_H

#include "../include/struct.h"

int getPressedCharacter();
char* getPressedCharacters(int limit);

//int inputFirstNatural();
//int inputFirstNatural(int limit);
int inputFirstNatural(int limit, char* condition);

int inputFileUsers(struct User** arrayUsers, int* countUsers);

int inputFileTransportations(struct Transportations** transportations, int* countTransportaions);

int inputInteger(int SIGN);

char* inputWord(int limit);

#endif INPUT_H