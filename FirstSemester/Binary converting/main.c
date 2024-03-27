#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mylib.h"

int main(int argc, char* argv[]) {
	FILE* input, * output;
	char *name_file_1 = argv[1], *name_file_2 = argv[2];
	if (!(strcmp(name_file_1, name_file_2))) {
		printf_s(ERROR_NAME_FILE);
		exit(1);
	}
	max_strlen(name_file_1, name_file_2);
	if (fopen_s(&input, name_file_1, "r") || fopen_s(&output, name_file_2, "w")) {
		perror(ERROR_NAME_LEN);
		exit(1);
	}
	int y = check_simvol(input), arr_memory[SIZE] = {0};
	if (y > 0) {
		int copy_y = y, sum = sum_number(copy_y);
		binar_cod(arr_memory, y);
		print_arr(arr_memory, output);
		printf_s("\n%d", sum);
	}
	else{
		int copy_y = abs(y), sum = sum_number(copy_y);
		dop_cod_arr(copy_y, arr_memory);
		print_arr(arr_memory, output);
		printf_s("\n%d", sum);
	}
	fclose(input);
	fclose(output);
	return 0;
}