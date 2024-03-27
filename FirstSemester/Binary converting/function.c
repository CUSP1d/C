#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mylib.h"

void max_strlen(char* name1, char* name2) {
	if (strlen(name1) > 100 || strlen(name2) > 100) {
		printf_s(ERROR_NAME_LEN);
		exit(1);
	}
}
void print_arr(int arr[32], FILE* input) {
	int t = 0;
	for (int i = 0; i < SIZE; ++i) {
		t += 1;
		fprintf_s(input, "%d", arr[i]);
		printf_s("%d", arr[i]);
		if (t % 4 == 0) {
			fprintf_s(input, " ");
			printf_s(" ");
		}
	}
}
void dop_cod_arr(int t, int arr[32]) {
	int tp = t, position = 31, size = 0;
	while (tp > 0) {
		size += 1;
		arr[position] = tp % 2;
		tp /= 2;
		--position;
	}
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = arr[i] ^ 1;
	}
	int y = SIZE-1;
	for (int i = 0; i < size-1; ++i) {
		if (arr[y] == 0) {
			arr[y] = 1; 
			break;
		}
		arr[y] = 0;
		--y;
	}
}
void binar_cod(int arr[32], int y) {
	int position = SIZE - 1;
	while (y > 0) {
		arr[position] = y % 2;
		y /= 2;
		--position;
	}
}
int check_simvol(FILE* i) {
	char tmp;
	int count = 0, count_n = 0, tmp1 = 0, chislo= 0;
	while (fscanf_s(i, "%c", &tmp, 1) != EOF) {
		if (tmp == '-') {
			if (count != 0) {
				printf_s(ERROR_NUMBER);
				exit(1);
			}
		}
		else {
			if (tmp < 48 || tmp > 57) {
				printf_s(ERROR_NUMBER);
				exit(1);
			}
		}
		count += 1;
	}
	fseek(i, SEEK_CUR-1, 0);
	while (fscanf_s(i, "%c", &tmp, 1) != EOF) {
		if (tmp != '0') {
			count_n += 1;
		}
	}
	if (count_n > 11) {
		printf_s(ERROR_NUMBER);
		exit(1);
	}
	fseek(i, SEEK_CUR - 1, 0);
	fscanf_s(i, "%d", &tmp1);
	chislo = tmp1;
	return chislo;
}
int sum_number(int y) {
	int sum = 0;
	while (y > 0) {
		sum += y % 10;
		y /= 10;
	}
	return sum;
}