#include <stdio.h>
#include <malloc.h>

#include "../../include/constants.h"
#include "../../include/input.h"
#include "../../include/functions.h"
#include "../../include/struct.h"
#include "../../include/userFunction.h"
#include "../../include/interface.h"
#include "../../include/transportationFunction.h"

void userMenu(struct User currentUser) {
	int programIsWork = 1;
	while (programIsWork) {
		clearConsole();
		int choice = inputFirstNatural(8, USERMENU);
		switch (choice) {
		case 1:
			resetPassword(currentUser);
			break;
		case 2:
			CRUDProductTransportation(currentUser.id);
			break;
		case 3: {
			clearConsole();
			int counter = counterTransportationsOfUser(currentUser.id);
			if (!counter)
				printf("� ��� ��� �������� ���������!\n");
			else
				printf("���-�� �������� ���������:%d\n", counter);
			pressAnyButton();
		}
			break;
		case 4: {
			clearConsole();
			float sum = sumPricesTransportationsOfUser(currentUser.id);
			if (sum == -1)
				printf("� ��� ��� �������� ���������!\n");
			else
				printf("����� ����������� �� �������� ���������(BYN):%f\n", sum);
			pressAnyButton();
		}
			break;
		case 5: {
			clearConsole();
			float sum = sumDistanceTraveledTransportationsOfUser(currentUser.id);
			if (sum == -1)
				printf("� ��� ��� �������� ���������!\n");
			else
				printf("��������� ������ �� �������� ���������(����):%f\n", sum);
			pressAnyButton();
		}
			break;
		case 6:
		{
			clearConsole();
			float sum = sumFuelConsumedTransportationsOfUser(currentUser.id);
			if (sum == -1)
				printf("� ��� ��� �������� ���������!\n");
			else
				printf("����� ������������ ������� �� �������� ���������(����):%f\n", sum);
			pressAnyButton();
		}
			break;
		case 7:
		{
			clearConsole();
			int id = 0;
			float sum = findProfitableIdTransportationsOfUsers(currentUser.id, &id);
			if (sum == -1)
				printf("� ��� ��� �������� ���������!\n");
			else
				printf("����� �������� �������� ���������(����/���������� � ��):%f\n�� �������� ���������:%d\n", sum, id);
			pressAnyButton();
		}
			break;
		case 8:
			programIsWork = 0;
			printf_s("\n�� ������� ����� �� ��������!\n");
			pressAnyButton();
			break;
		}
	}
	return;
}