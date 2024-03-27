#include <stdio.h>
#include <stdlib.h>

#include "function.h"

void test_1();

int main() {
	test_1();
	return 0;
}

void test_1() {
	char* string = "string_ssstrolbets_summa";
	char* str = "tr";
	char* st = 's';
	char* s = "qew";
	if (mystrlen(str) > mystrlen(string)){
		printf_s("ERROR\n");
		exit(1);
	}
	int kolvo = substring_search_count(string, str);
	printf_s("%d\n\n", kolvo);
	substring_search(string, str);
	printf_s("\n\n");
	char** arr_replace = separation_string(string, st);
	printf_s("\n\n");
	char* arr = replacing_a_substring(string, str, s);
	printf_s("\n\n");
	str = "ew";
	st = 'q';
	s = "lox";
	if (mystrlen(str) > mystrlen(arr)) {
		printf_s("ERROR\n");
		exit(1);
	}
	kolvo = substring_search_count(arr, str);
	printf_s("%d\n\n", kolvo);
	substring_search(arr, str);
	printf_s("\n\n");
	char** arr_replace2 = separation_string(arr, st);
	printf_s("\n\n");
	char* arr1 = replacing_a_substring(arr, str, s);
	printf_s("\n\n");
	free(arr);
	free(arr1);
}