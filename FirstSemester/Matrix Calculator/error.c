#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "support.h"
#include "error.h"
#include "matrix_function.h"

void cheking_zero(FILE* in) {
	int g = 0;
	char tmp;
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		g++;
	}
	if (g == 0) {
		printf_s("The file is empty\n");
		fclose(in);
		exit(1);
	}
	fseek(in, 0, 0);
}
FILE* cheking_whitespace(FILE* in, const char* name) {
	FILE* mat;
	char tmp;
	int kol_vo = 1;
	fseek(in, 0, 0);
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
			kol_vo++;
	}
	char* arr = malloc(kol_vo * sizeof(char));
	fseek(in, 0, 0);
	int j = 0;
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		arr[j++] = tmp;
	}
	arr[j] = '\0';
	int flag = 0, kol_vo1 = 0;
	for (int i = 0; i < kol_vo; ++i) {
		if (arr[i] == ' ') {
			flag = 1;
		}
		else {
			if (flag == 1) {
				kol_vo1++;
			}
			kol_vo1++;
			flag = 0;
		}
	}

	char* arr1 = malloc(kol_vo1 * sizeof(char));
	flag = 0;
	j = 0;
	for (int i = 0; i < kol_vo; ++i) {
		if (arr[i] == ' ') {
			flag = 1;
		}
		else {
			if (flag == 1) {
				arr1[j] = ' ';
				j++;
			}
			arr1[j] = arr[i];
			j++;
			flag = 0;
		}
	}
	for (int i = 0; i < kol_vo; ++i) {
		printf_s("%c", arr1[i]);

	}
	if (fopen_s(&mat, name, "w")) {
		printf_s(ERROR_FILE);
		exit(1);
	}
	for (int i = 0; i < kol_vo1-1; ++i) {
		fprintf_s(mat, "%c", arr1[i]);
	}
	fclose(mat);
	fopen_s(&mat, name, "r");
	free(arr);
	free(arr1);
	return mat;
}
void cheking_simvol(FILE* in) {
	char tmp; int sup = 0, flag = 0, help = 0, str = 1;
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		sup = tmp;
		if ((sup < 48 || sup > 57) && sup != 32 && sup != 10 && sup != 45 && sup != 46) {
			printf_s(ERR_INCOR_INP_SIMVOL);
			exit(1);
		}
	}
	fseek(in, 0, 0);
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) 
	{
		if (tmp == '\n') {
			str++;
		}
	}
	int sum = 0;
	for (int i = 0; i < str; ++i) {
		sum += MAX_DLINA;
	}
	fseek(in, 0, 0);
	char* arr = malloc(sum * sizeof(char));
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		arr[help++] = tmp;
	}
	arr[help] = '\0';
	for (int i = 0; i < help; ++i) {
		if (i != 0) {
			if (arr[i] == '-') {
				if ((arr[i - 1] != ' ') && (arr[i - 1] != '\n')) {
					printf_s(ERR_INCOR_INP_SIMVOL);
					exit(1);
				}
			}
		}
	}
	fseek(in, 0, 0);
	for (int i = 0; i < help; ++i) {
		if (i == 0) {
			if (arr[i] == 46) {
				printf_s(ERR_INCOR_INP_SIMVOL);
				exit(1);
			}
		}
		else {
			if (arr[i] == 46) {
				if ((arr[i - 1] < 48 || arr[i - 1] > 57)) {
					printf_s(ERR_INCOR_INP_SIMVOL);
					exit(1);
				}
				if (arr[i + 1] < 48 || arr[i + 1] > 57) {
					printf_s(ERR_INCOR_INP_SIMVOL);
					exit(1);
				}
			}
		}
	}
	free(arr);
	fseek(in, 0, 0);
}
void cheking_col_matrix(FILE* in) {
	char tmp; int count_str = 1, count_col = 0, j = 0;
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		if (tmp == '\n') {
			count_str++;
		}
	}
	fseek(in, 0, 0);
	int* arr_sup = malloc(count_str * sizeof(int));
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		if (tmp == ' ' || tmp == '\n') {
			count_col++;
		}
		if (tmp == '\n') {
			arr_sup[j++] = count_col;
			count_col = 0;
		}
	}
	arr_sup[j] = count_col + 1;
	int tmp1 = arr_sup[0];
	for (int i = 0; i < count_str; ++i) {
		if (arr_sup[i] != tmp1) {
			printf_s(ERR_INCOR_INP_MATRIX);
			exit(1);
		}
	}
	fseek(in, 0, 0);
	free(arr_sup);
}
void cheking_all(FILE* in1, FILE* in2) {
	cheking_simvol(in1);
	cheking_simvol(in2);
	cheking_col_matrix(in1);
	cheking_col_matrix(in2);
}