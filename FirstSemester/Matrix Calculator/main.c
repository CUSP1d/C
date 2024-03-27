#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "support.h"
#include "error.h"
#include "matrix_function.h"

int main(int argv, char* argc[]) {
	FILE *inp1, *inp2;
	int num = 0;
	matrix_all matrix1, matrix2;
	matrix1.col = 0;
	matrix1.str = 0;
	matrix2.col = 0;
	matrix2.str = 0;
	matrix1.count_det = 0;
	matrix1.det = 0;
	matrix2.count_det = 0;
	matrix2.det = 0;
	char *name1 = argc[1], *name2 = argc[2];
	if (fopen_s(&inp1, name1, "r") || fopen_s(&inp2, name2, "r")) {
		_fcloseall();
		perror(ERROR_FILE);
		exit(1);
	}
	char tmp;
	cheking_zero(inp1);
	cheking_zero(inp2);
	while (fscanf_s(inp1, "%c", &tmp, 1) != EOF) {
		if (tmp == '\n') break;
		printf_s("%c", tmp);
	}
	printf_s("\n\n");
	fseek(inp1, 0, 0);
	FILE* inp1_1 = cheking_whitespace(inp1, "mat1.txt");
	FILE* inp2_2 = cheking_whitespace(inp2, "mat2.txt");
	cheking_all(inp1_1, inp2_2);
	matrix1.matrix = record_matrix(inp1_1, &matrix1);
	matrix2.matrix = record_matrix(inp2_2, &matrix2);;
	glavnoe_menu(&matrix1, &matrix2);
	return 0;
}