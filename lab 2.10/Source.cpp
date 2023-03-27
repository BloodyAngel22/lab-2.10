#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <time.h>

//������� �� ������ ��� �����. ���������� ���������� ��������� ����.

/*���� ������. ����������, ����� ������ � ��� �����������
������: 'x' ��� 'w'. ���� ������-�� �� �������� ���, �������
��������� �� ����.*/

/*���� ������. �������� ����� ������� ������� ��� ���������
�������.*/

int remove_numbers(char* str,int counter) {
	int numbers = 0;
	for (int i = 0; i < counter; i++) {
		if (str[i] == '1' or str[i] == '2' or str[i] == '3' or str[i] == '4' or str[i] == '5' or str[i] == '6' or str[i] == '7' or
			str[i] == '8' or str[i] == '9' or str[i] == '0') {
			numbers++;
			str[i] = ' ';
		}
	}
	return numbers;
}

void early_symbol(char* str, int counter) {
	int flag_x = 0, flag_w = 0;
	int Xposition = 0, Wposition = 0;
	for (int i = 0; i < counter; i++) {
		if (str[i] == 'x') {
			if (flag_x == 0)
				Xposition = i;
			flag_x = 1;
		}
		if (str[i] == 'w') {
			if (flag_w == 0)
				Wposition = i;
			flag_w = 1;
		}
	}
	if (Xposition < Wposition) printf("x ���� ������ ��� w");
	else if (Wposition < Xposition) printf("w ���� ������ ��� x");

	if (flag_x == 0) {
		printf("x ��� � �������\n");
	}
	if (flag_w == 0) {
		printf("w ��� � �������\n");
	}
}

void insert_two_random_symbol(char* str, char* storageStr, int counter) {
	counter = counter * 3;
	for (int i = 0, j = 0; i <= counter; i+=3, j++) {
		storageStr[i] = str[j];
		storageStr[i + 1] = rand() % 205 + 50;
		storageStr[i + 2] = rand() % 205 + 50;
	}

	printf("����� ������ � 2 ���������� ����������\n");
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
	scanf_s("%s", &str, 100);
	int storage;
	int counter = 0;
	while (str[counter] != '\0') {
		counter++;
	}

	switch (choice_task)
	{
	case 1:
		storage = remove_numbers(str, counter);
		printf("����� ������\n");
		printf("%s\n", str);
		printf("���������� ��������� ����: %d\n", storage);
		break;

	case 2:
		early_symbol(str, counter);
		break;

	case 3:
		insert_two_random_symbol(str, storageStr, counter);
		break;
	}
}