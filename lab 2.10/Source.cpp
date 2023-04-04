#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include <limits.h>

//������� �� ������ ��� �����. ���������� ���������� ��������� ����.

/*���� ������. ����������, ����� ������ � ��� �����������
������: 'x' ��� 'w'. ���� ������-�� �� �������� ���, �������
��������� �� ����.*/

/*���� ������. �������� ����� ������� ������� ��� ���������
�������.*/

void remove_numbers(char* str, char* storageStr,int counter) {
	int numbers = 0;
	int j = 0;
	for (int i = 0; i <= counter; i++) {
		if (str[i] > '9' or str[i] < '0') {
			storageStr[j] = str[i];
			j++;
		}
		/*if (str[i] >= '0' and str[i] <= '9') {
			numbers++;
		}*/
		else numbers++;
	}
	printf("����� ������ � ���������� �������\n");
	printf("%s", storageStr);
	printf("\n");
	printf("���������� �������� %d", numbers);
}

void early_symbol(char* str, int counter) {
	//int flag_x = 0, flag_w = 0;
	int Xposition = -1, Wposition = -1;
	for (int i = 0; i < counter; i++) {
		if (str[i] == 'x' and Xposition < 0) {
			Xposition = i;
		}
		if (str[i] == 'w' and Wposition < 0) {
			Wposition = i;
		}
	}
	//if (Xposition < 0) Xposition = INT_MAX;
	//if (Wposition < 0) Wposition = INT_MAX;

	if (Xposition < Wposition and Xposition >= 0) printf("x ���� ������ ��� w\n");
	if (Wposition < Xposition and Wposition >= 0) printf("w ���� ������ ��� x\n");

	if (Xposition < 0) {
		printf("x ��� � �������\n");
	}
	if (Wposition < 0) {
		printf("w ��� � �������\n");
	}
}

void insert_two_random_symbol(char* str, char* storageStr, int counter) {
	for (int i = 0, j = 0; j <= counter; i+=3, j++) {
		storageStr[i] = str[j];
		storageStr[i + 1] = rand() % ('Z' - 'A' + 1) + 'A';
		storageStr[i + 2] = rand() % ('Z' - 'A' + 1) + 'A';
	}

	printf("����� ������ � 2 ���������� ���������\n");
	printf("%s\n", storageStr);
}


int main() {
	srand(time(NULL));
	system("chcp 1251");
	char str[100];
	char storageStr[100];

	printf("1 - ������� �� ������ ��� �����. ���������� ���������� ��������� ����\n");
	printf("2 - ���� ������. ����������, ����� ������ � ��� ����������� ������: 'x' ��� 'w'.���� ������ - �� �� �������� ���, ������� ��������� �� ����\n");
	printf("3 - ���� ������. �������� ����� ������� ������� ��� ��������� �������\n");
	int choice_task;
	do {
		printf("�������� � �������  �� 1 �� 3\n"); scanf_s("%d", &choice_task);
	} while (choice_task < 1 or choice_task > 3);

	printf("������� ������\n");
	//scanf_s("%s", &str, 100);
	while (getchar() != '\n');
	gets_s(str);
	int storage;
	int counter = 0;
	while (str[counter] != '\0') {
		counter++;
	}

	switch (choice_task)
	{
	case 1:
		remove_numbers(str, storageStr, counter);
		break;

	case 2:
		early_symbol(str, counter);
		break;

	case 3:
		insert_two_random_symbol(str, storageStr, counter);
		break;
	}
}