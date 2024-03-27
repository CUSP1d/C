#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "support.h"
#include "error.h"
#include "matrix_function.h"

void glavnoe_menu(matrix_all* matrix1, matrix_all* matrix2) {
	system("cls");
	int a;
	printf_s("Enter the operation you want to do\n");
	printf_s("1. Addition\n");
	printf_s("2. Deduction\n");
	printf_s("3. Multiplication\n");
	printf_s("4. Transposition\n");
	printf_s("5. Determinant\n");
	printf_s("0. exit\n");
	scanf_s("%d", &a);
	if (a == 1) {
		Addition(matrix1, matrix2);
	}
	if (a == 2) {
		Deduction_menu(matrix1, matrix2);
	}
	if (a == 3) {
		Multiplication_menu(matrix1, matrix2);
	}
	if (a == 4) {
		Transposition_menu(matrix1, matrix2);
	}
	if (a == 5) {
		Determinant_menu(matrix1, matrix2);
	}
	if (a == 0) {
		exit(1);
	}
	if (a > 5 || a < 0) {
		printf_s("such an operation does not exist\n");
		exit(1);
	}
}
void Deduction_menu(matrix_all* matrix1, matrix_all* matrix2) {
	system("cls");
	int a;
	printf_s("which matrix do you want to subtract from which one?\n");
	printf_s("1. 1 - 2 matrix\n");
	printf_s("2. 2 - 1 matrix\n");
	scanf_s("%d", &a);
	if (a == 1) {
		Deduction(matrix1, matrix2);
	}
	if (a == 2) {
		Deduction(matrix2, matrix1);
	}
	if (a < 1 || a > 2) {
		printf_s("such an operation does not exist\nTry again\n");
		Deduction_menu(matrix1, matrix2);
		exit(1);
	}
}
void Multiplication_menu(matrix_all* matrix1, matrix_all* matrix2) {
	system("cls");
	int a;
	printf_s("choose which matrix you want to multiply by which\n");
	printf_s("1. 1 * 2\n");
	printf_s("2. 2 * 1\n");
	scanf_s("%d", &a);
	if (a == 1) {
		Multiplication(matrix1, matrix2);
		exit(1);
	}
	if (a == 2) {
		Multiplication(matrix2, matrix1);
		exit(1);
	}
	if (a > 2 || a < 1) {
		printf_s("such an operation does not exist\nTry again\n");
		Multiplication(matrix1, matrix2);
		exit(1);
	}
}
void Transposition_menu(matrix_all* matrix1, matrix_all* matrix2) {
	system("cls");
	int a;
	printf_s("Enter which matrix you want to transpose\n");
	printf_s("1. 1\n");
	printf_s("2. 2\n");
	scanf_s("%d", &a);
	if (a == 1) {
		Transposition(matrix1);
		glavnoe_menu(matrix1, matrix2);
		exit(1);
	}
	if (a == 2) {
		Transposition(matrix2);
		glavnoe_menu(matrix1, matrix2);
		exit(1);
	}
	if (a < 1 || a > 2) {
		printf_s("such an operation does not exist\nTry again\n");
		Transposition_menu(matrix1, matrix2);
		exit(1);
	}
}
void Determinant_menu(matrix_all* matrix1, matrix_all* matrix2) {
	system("cls");
	int a;
	printf_s("Select the matrix from which you want to find the determinant\n");
	printf_s("1. 1\n");
	printf_s("2. 2\n");
	scanf_s("%d", &a);
	if (a == 1) {
		if (matrix1->col != matrix1->str) {
			printf_s("It is impossible to calculate the determinant for such a matrix\nTry another one\n");
			Determinant_menu(matrix1, matrix2);
			exit(1);
		}
		if (matrix1->str > 7) {
			printf_s("The matrix is too large\nTry another one\n");
			Determinant_menu(matrix1, matrix2);
			exit(1);
		}
		if (matrix1->count_det == 1) {
			printf_s("det = %f \n", matrix1->det);
			system("pause");
			glavnoe_menu(matrix1, matrix2);
			exit(1);
		}
		matrix1->count_det = 1;
		double** det = matrix1->matrix;
		matrix1->det = Determinant(det, matrix1->str);
		printf_s("det = %f \n", matrix1->det);
		for (int i = 0; i < matrix1->str; ++i) {
			free(det[i]);
		}
		free(det);
		system("pause");
		glavnoe_menu(matrix1, matrix2);
	}
	if (a == 2) {
		if (matrix2->col != matrix2->str) {
			printf_s("It is impossible to calculate the determinant for such a matrix\nTry another one\n");
			Determinant_menu(matrix1, matrix2);
			exit(1);
		}
		if (matrix1->str > 10) {
			printf_s("The matrix is too large\nTry another one\n");
			Determinant_menu(matrix1, matrix2);
			exit(1);
		}
		if (matrix2->count_det == 1) {
			printf_s("det = %f \n", matrix2->det);
			system("pause");
			glavnoe_menu(matrix1, matrix2);
			exit(1);
		}
		matrix2->count_det = 1;
		double** det = matrix2->matrix;
		matrix2->det = Determinant(det, matrix2->str);
		printf_s("det = %f \n", matrix2->det);
		system("pause");
		for (int i = 0; i < matrix1->str; ++i) {
			free(det[i]);
		}
		free(det);
		glavnoe_menu(matrix1, matrix2);
	}
	if (a < 1 || a > 2) {
		printf_s("Such an operation does not exist\nTry again\n");
		exit(1);
	}
}