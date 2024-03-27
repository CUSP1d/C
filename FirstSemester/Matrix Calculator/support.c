#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "support.h"
#include "error.h"
#include "matrix_function.h"

double** record_matrix(FILE* in, matrix_all* matrix) {
	fseek(in, 0, 0);
	char tmp; int count_str = 1, count_col = 0;
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		if (tmp == '\n') {
			count_str++;
		}
	}
	fseek(in, 0, 0);
	matrix->str = count_str;
	while (fscanf_s(in, "%c", &tmp, 1) != EOF) {
		if (tmp == ' ' || tmp == '\n') {
			count_col++;
		}
		if (tmp == '\n') {
			matrix->col = count_col;
			break;
		}
	}
	printf_s("%d  %d", matrix->str, matrix->col);
	fseek(in, 0, 0);
	double** arr_sup = creature_arr_2d_int(matrix->str, matrix->col);
	for (int i = 0; i < matrix->str; ++i) {
		for (int j = 0; j < matrix->col; ++j) {
			fscanf_s(in, "%lf", &arr_sup[i][j]);

		}
	}
	return arr_sup;
}
double** creature_arr_2d_int(int str, int col) {
	double** arr = malloc(str * sizeof(double*));
	if (!arr) {
		free(arr);
		perror(ERROR_MEMORY);
		exit(1);
	}
	for (int i = 0; i < str; ++i) {
		arr[i] = malloc(col * sizeof(double));
		if (!arr[i]) {
			for (int j = 0; j < i; ++j) {
				free(arr[j]);
			}
			perror(ERROR_MEMORY);
			free(arr);
			exit(1);
		}
	}
	return arr;
}
double** det_matrix_sup(double** matrix, int n, int h) {
	double** det = creature_arr_2d_int(n - 1, n - 1);
	for (int i = 1; i < n; ++i) {
		for (int j = 0, k = 0; j < n; ++j, ++k) {
			if (j == h) {
				--k;
				continue;
			}
			det[i-1][k] = matrix[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		free(matrix[i]);
	}
	free(matrix);
	return det;
}