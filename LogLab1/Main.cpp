#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>

struct student
{
	char famil[20];
	char name[20], facult[20];
	int Nomzach;
};

void findBy(student st[]) {
	//index 1 for name, 2 for famil, 3 for facul, 4 for nomzach
	printf("������� �������� ������");
	printf("1 - ��� \n 2 - ������\n 3 - ��������� \n 4 - ����� �������");
	int index;
	int paramz;
	char param[20];
	scanf("%d", &index);

	if ((index > 0) && (index < 4)) {
		printf("������� �������� ������");
		scanf("%20s", &param);
	}
	else if (index == 4) {
		printf("������� �����");
		scanf("%d", &paramz);
	}

	int len = sizeof(*st) / sizeof(student);

	if (index == 4) {
		for (int i = 0; i < len; i++) {
			student* stud = st + (64 * i);
			if (stud->Nomzach == paramz) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", st[i].famil, st[i].name, st[i].facult, st[i].Nomzach);
			}
		}
	}
	else {
		for (int i = 0; i < len; i++) {
			student* stud = st + (sizeof(student) * i);
			void* stpar = stud + (20 * (index - 1));
			if (stpar == param) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", st[i].famil, st[i].name, st[i].facult, st[i].Nomzach);
			}
		}
	}
}

int maxDiffMin(int mas[]) {

	int len = sizeof(*mas) / sizeof(mas[0]);

	int max = mas[0];
	int min = mas[0];
	for (int i = 0; i < len; i++) {
		max = max < mas[i] ? mas[i] : max;
		min = min > mas[i] ? mas[i] : max;
	}

	return max - min;
}

int* randMas(int size) {
	int* mas = (int*)malloc(size * sizeof(int));

	int min = 0;
	int max = 100;

	for (int i = 0; i < size; i++) {
		mas[i] = min + rand() % (max - min + 1);
	}

	return mas;
}

int* randMas2() {
	int size;
	scanf("%d", &size);
	int* mas = (int*)malloc(size * sizeof(int));

	int min = 0;
	int max = 100;

	for (int i = 0; i < size; i++) {
		mas[i] = min + rand() % (max - min + 1);
	}

	return mas;
}

void sumRowCol(int mas[50][50]) {
	int rowsum = 0;
	int colsum = 0;

	for (int i = 0; i < 50; i++) {
		rowsum = rowsum + mas[i][0];
	}

	for (int i = 0; i < 50; i++) {
		colsum = colsum + mas[0][i];
	}

	printf("� ������ ������: %d", rowsum);
	printf("� ������ �������: %d", colsum);
}

void createStudents(student stud[]){
	for (int i = 0; i < 3; i++) {
		printf("������� ������� ��������\n");
		scanf("%20s", stud[i].famil);

		printf(";������� ��� �������� %s\n", stud[i].famil);
		scanf("%20s", stud[i].name);

		printf(";������� �������� ��������� �������� %s%s\n", stud[i].famil, stud[i].name);
		scanf("%20s", stud[i].facult);

		printf(";������� ����� �������� ������ �������� %s%s\n", stud[i].famil, stud[i].name);
		scanf("%d", &stud[i].Nomzach);
	}
}

void studentsList(student stud[]){
	for (int i = 0; i < 3; i++) {
		printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
	}
}

int main() {
	struct student stud[3];
	setlocale(LC_ALL, "Rus");

	createStudents(stud);

	findBy(stud);
	getchar();

	return 0;
}