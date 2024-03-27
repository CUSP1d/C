#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "support.h"
#include "error.h"
#include "matrix_function.h"

void Addition(matrix_all* matrix1, matrix_all* matrix2) {
	if ((matrix1->str != matrix2->str) || (matrix1->col != matrix2->col)) {
		printf_s("You can only add matrices of the same size\n");
		exit(1);
	}
	double** arr_result = creature_arr_2d_int(matrix1->str, matrix1->col);
	for (int i = 0; i < matrix1->str; ++i) {
		for (int j = 0; j < matrix1->col; ++j) {
			arr_result[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
		}
	}
	for (int i = 0; i < matrix1->str; ++i) {
		for (int j = 0; j < matrix1->col; ++j) {
			printf_s("%.2f ", arr_result[i][j]);
		}
		printf_s("\n");
	}
	for (int i = 0; i < matrix1->str; ++i) {
		free(arr_result[i]);
	}
	free(arr_result);
	system("pause");
	glavnoe_menu(matrix1, matrix2);
}
void Deduction(matrix_all* matrix1, matrix_all* matrix2) {
	system("cls");
	if ((matrix1->str != matrix2->str) || (matrix1->col != matrix2->col)) {
		printf_s("You can only add matrices of the same size\n");
		system("pause");
		glavnoe_menu(matrix1, matrix2);
		exit(1);
	}
	double** arr_result = creature_arr_2d_int(matrix1->str, matrix1->col);
	for (int i = 0; i < matrix1->str; ++i) {
		for (int j = 0; j < matrix1->col; ++j) {
			arr_result[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
		}
	}
	for (int i = 0; i < matrix1->str; ++i) {
		for (int j = 0; j < matrix1->col; ++j) {
			printf_s("%.2f ", arr_result[i][j]);
		}
		printf_s("\n");
	}
	for (int i = 0; i < matrix1->str; ++i) {
		free(arr_result[i]);
	}
	free(arr_result);
	system("pause");
	glavnoe_menu(matrix1, matrix2);
}
void Multiplication(matrix_all* matrix1, matrix_all* matrix2) {
	system("cls");
	if (matrix1->col != matrix2->str) {
		printf_s("Such matrices cannot be multiplied\n");
		exit(1);
	}
	double** arr_sup = creature_arr_2d_int(matrix1->str, matrix2->col);
	double sum = 0.0;
	int k = 0, f = 0;
	for (int i = 1; i < (matrix1->str * matrix2->col)+1; ++i) {
		for (int j = 0; j < matrix2->col; ++j) {
			sum += (matrix1->matrix[k][j] * matrix2->matrix[j][f]);
		}
		arr_sup[k][f] = sum;
		f += 1;
		if ((i % matrix2->col) == 0) {
			k++;
			f = 0;
		}
		sum = 0.0;
	}
	for (int i = 0; i < matrix1->str; ++i) {
		for (int j = 0; j < matrix2->col; ++j) {
			printf_s("%.2f ", arr_sup[i][j]);
		}
		printf_s("\n");
	}
	for (int i = 0; i < matrix1->str; ++i) {
		free(arr_sup[i]);
	}
	free(arr_sup);
	system("pause");
	glavnoe_menu(matrix1, matrix2);
}
void Transposition(matrix_all* matrix) {
	double** arr_sup = creature_arr_2d_int(matrix->col, matrix->str);
	int k = 0, d = 0;
	for (int i = 0; i < matrix->col; ++i) {
		for (int j = 0; j < matrix->str; ++j) {
			arr_sup[i][j] = matrix->matrix[k][d];
			k++;
		}
		k = 0;
		d++;
	}
	for (int i = 0; i < matrix->col;++i) {
		for (int j = 0; j < matrix->str; ++j) {
			printf_s("%.2f ", arr_sup[i][j]);
		}
		printf_s("\n");
	}
	for (int i = 0; i < matrix->col; ++i) {
		free(arr_sup[i]);
	}
	free(arr_sup);
	system("pause");
}
double Determinant(double** matrix, int n) {
	if (n == 1) {
		return matrix[0][0];
	}
	if (n == 2) {
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
		for (int i = 0; i < n; ++i) {
			free(matrix[i]);
		}
		free(matrix);
	}
	int znak = 1;
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (znak * matrix[0][i] * Determinant(det_matrix_sup(matrix, n, i), n - 1));
		znak *= -1;
	}
	return sum;
}
