

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "../include/input.h"
#include "../include/constants.h"

void clearConsole() {
	system("cls");
}

void pressAnyButton() {
	printf_s("Нажмите любую клавишу...\n");
	getPressedCharacter();
}

char* generateSolid() {
	int lengthSolid = rand() % (LENGTHMAXSOLID + 1 - LENGTHMINSOLID) + LENGTHMINSOLID;
	char* solid;
	if (solid = (char*)malloc(sizeof(char) * (lengthSolid + 1))) {
		solid[lengthSolid] = '\0';
		for (int _char = 0; _char < lengthSolid; _char++)
			solid[_char] = rand() % 2 ? (rand() % 10 + '0') : ((rand() % 2 ? 'a' : 'A') + rand() % 26);
		return solid;
	}
	else {
		printf("\nНе удалось выделить память в generateSolid!");
		return "";
	}
}

char* toHash(char* password, char* solid) {
	int lengthSolid = (int)strlen(solid), lengthPassword = (int)strlen(password);
	char* hash;
	if (hash = (char*)malloc(sizeof(char) * (lengthPassword + 1))) {
		hash[lengthPassword] = '\0';
		for (int _char = 0; _char < lengthPassword; _char++) {
			char characterSolid = solid[_char % lengthSolid], characterPassword = password[_char];
			char characterSolidRemainder = characterSolid - (characterSolid <= '9' ? '0' : (characterSolid <= 'Z' ? 'A' : 'a'));
			char characterPasswordRemainder = characterPassword - (characterPassword <= '9' ? '0' : (characterPassword <= 'Z' ? 'A' : 'a'));
			char sumRemainders = characterPasswordRemainder + characterSolidRemainder;
			hash[_char] = (char)(characterSolid <= '9' ? (sumRemainders % 10 + '0') : (characterSolid <= 'Z' ? ((sumRemainders) % 26 + 'A') : (sumRemainders % 26 + 'a')));
		}
		return hash;
	}
	else {
		printf("\nНе удалось выделить память в toHash!");
		pressAnyButton();
		return "";
	}
}

int getLengthInteger(int number) {
	if (!number)
		return 1;
	int length = 0;
	while (number)
		length++, number /= 10;
	return length;
}