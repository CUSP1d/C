#include <stdio.h>
#include <stdlib.h>

#include "function.h"

int mystrlen(char* string) {
	int count = 0, i = 0;
	while (string[i] != '\0') {
		count++;
		i++;
	}
	return count;
}

int** alloc2darrint(int N, int M) {
	int** arr = malloc(N * sizeof(int*));
	if (!arr) {
		perror;
		exit(1);
	}
	for (int i = 0; i < N; ++i) {
		arr[i] = malloc(M * sizeof(int));
		if (!arr[i]) {
			for (int j = 0; j < i; ++j) {
				free(arr[j]);
			}
			free(arr);
			perror;
			exit(1);
		}
	}
	return arr;
}

int substring_search_count(char* string, char* str) {
	int count_tmp = 0, count = 0;
	for (int i = 0; i < mystrlen(string); ++i) {
		count_tmp = 0;
		for (int j = 0; j < mystrlen(str); ++j) {
			if (string[i + j] == str[j]) {
				count_tmp++;
			}
		}
		if (count_tmp == mystrlen(str)) {
			count++;
		}
	}
	return count;
}

void substring_search(char* string, char* str) {
	int count_tmp = 0, index = 0;
	for (int i = 0; i < mystrlen(string); ++i) {
		count_tmp = 0;
		for (int j = 0; j < mystrlen(str); ++j) {
			if (string[i + j] == str[j]) {
				count_tmp++;
			}
		}
		if (count_tmp == mystrlen(str)) {
			index = i;
			printf_s("start:%d, end:%d\n", index, (index + mystrlen(str)) - 1);

		}
	}
}

char** separation_string(char* string, char* st) {
	int count = 0;
	for (int i = 0; i < mystrlen(string); ++i) {
		if (string[i] == st && string[i+1] != st) {
			count++;
		}
	}
	int* arr_sup = malloc((count+1) * sizeof(int));
	int k = 0, count1 = 0;
	for (int i = 0; i < mystrlen(string); ++i) {
		if (string[i] == st && string[i+1] != st) {
			arr_sup[k++] = count1+1;
			count1 = 0;
		}
		else if(string[i] != st) {
			count1++;
		}
	}
	arr_sup[k] = count1 + 1;
	char** arr_all = malloc((count+1) * sizeof(char*));
	if (!arr_all) {
		perror;
		exit(1);
	}
	for (int i = 0; i < count+1; ++i) {
		arr_all[i] = malloc(arr_sup[i] * sizeof(char));
		if (!arr_all[i]) {
			perror;
			exit(1);
		}
	}
	k = 0;
	int g = 0;
	for (int i = 0; i < mystrlen(string); ++i) {
		if (string[i] == st && string[i+1] != st) {
			arr_all[g][k] = '\0';
			g++;
			k = 0;
		}
		else if(string[i] != st) {
			arr_all[g][k++] = string[i];
		}
	}
	arr_all[g][k] = '\0';
	for (int i = 0; i < count+1; ++i) {
		printf_s("%s\n", arr_all[i]);
	}
	printf_s("\n");
	free(arr_sup);
	return arr_all;
}

char* replacing_a_substring(char* string, char* str, char* s) {
	int flag = 0, k = 0;
	int kolvo = substring_search_count(string, str);
	int** arr_point = alloc2darrint(kolvo, 2);
	for (int i = 0; i < mystrlen(string); ++i) {
		flag = 0;
		for (int j = 0; j < mystrlen(str); ++j) {
			if (string[i + j] == str[j]) {
				flag = 0;
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			arr_point[k][0] = i;
			arr_point[k][1] = (i + mystrlen(str)) - 1;
			k++;	
		}
	}
	int kolvo1 = mystrlen(str) - mystrlen(s);
	if (kolvo1 < 0) {
		kolvo1 = mystrlen(string) +  (abs(kolvo1) * kolvo);
	}
	else {
		kolvo1 = mystrlen(string) - (kolvo1 * kolvo);
	}
	char* arr_copy = malloc((kolvo1 + 1) * sizeof(char));
	if (!arr_copy) {
		perror;
		exit(1);
	}
	int o = 0;
	for (int i = 0, j = 0; i < mystrlen(string); ++i, j++) {
		if (i == arr_point[o][0]) {
			for (int f = 0; f < mystrlen(s); ++f) {
				arr_copy[j+f] = s[f];
			}
			j = (j + mystrlen(s)) - 1;
			i = arr_point[o][1];
			o++;
			if (o == kolvo) {
				o = 0;
			}
		}
		else {
			arr_copy[j] = string[i];
		}
	}
	arr_copy[kolvo1] = '\0';
	printf_s("%s\n", arr_copy);
	return arr_copy;
}