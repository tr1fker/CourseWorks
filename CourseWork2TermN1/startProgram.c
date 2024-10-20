#include <locale.h>

#include "include/interface.h"

#include <stdio.h>
#include <time.h>

#include "include/struct.h"
#include "include/input.h"
#include "include/output.h"


int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	basicMenu();
	return 0;
}