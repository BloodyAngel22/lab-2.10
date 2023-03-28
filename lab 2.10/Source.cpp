#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <time.h>

//Удалить из текста все цифры. Определить количество удаленных цифр.

/*Дана строка. Определить, какой символ в ней встречается
раньше: 'x' или 'w'. Если какого-то из символов нет, вывести
сообщение об этом.*/

/*Дана строка. Вставить после каждого символа два случайных
символа.*/

int remove_numbers(char* str, char* storageStr,int counter) {
	int numbers = 0; int countsyb = 0;
	int j = 0;
	for (int i = 0; i < counter; i++) {
		if (str[i] > '9') {
			storageStr[j] = str[i];
			j++;
		}
		if (str[i] >= '0' and str[i] <= '9') {
			numbers++;
		}
	}
	storageStr[counter - numbers] = '\0';
	printf("Вывод строки с удаленными цифрами\n");
	for (int i = 0; storageStr[i] != '\0'; i++)
		printf("%c", storageStr[i]);
	printf("\n");
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
	if (Xposition < Wposition) printf("x идет раньше чем w");
	else if (Wposition < Xposition) printf("w идет раньше чем x");

	if (flag_x == 0) {
		printf("x нет в массиве\n");
	}
	if (flag_w == 0) {
		printf("w нет в массиве\n");
	}
}

void insert_two_random_symbol(char* str, char* storageStr, int counter) {
	counter = counter * 3;
	for (int i = 0, j = 0; i <= counter; i+=3, j++) {
		storageStr[i] = str[j];
		storageStr[i + 1] = rand() % 205 + 50;
		storageStr[i + 2] = rand() % 205 + 50;
	}

	printf("Вывод строки с 2 рандомными симваолами\n");
	printf("%s\n", storageStr);
}


int main() {
	srand(time(NULL));
	system("chcp 1251");
	char str[100];
	char storageStr[100];

	printf("1 - Удалить из текста все цифры. Определить количество удаленных цифр\n");
	printf("2 - Дана строка. Определить, какой символ в ней встречается раньше: 'x' или 'w'.Если какого - то из символов нет, вывести сообщение об этом\n");
	printf("3 - Дана строка. Вставить после каждого символа два случайных символа\n");
	int choice_task;
	do {
		printf("Выберите № задания  от 1 до 3\n"); scanf_s("%d", &choice_task);
	} while (choice_task < 1 or choice_task > 3);

	printf("Введите строку\n");
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
		storage = remove_numbers(str, storageStr, counter);
		printf("Количество удаленных цифр: %d\n", storage);
		break;

	case 2:
		early_symbol(str, counter);
		break;

	case 3:
		insert_two_random_symbol(str, storageStr, counter);
		break;
	}
}