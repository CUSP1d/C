#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

void proverka(int a) {
	if (a != 0) {
		if (a == 1) {
			printf(ERROR_FLAG_1);
			exit(1);
		}
		if (a == 2) {
			printf(ERROR_FLAG_2);
			exit(1);
		}
	}
	else {
		//printf(GOOD_FLAG);
	}
}

// Функция для подсчета колличества типа каждого флага 

int* kolvo_flags(char** mass, int size) {
	int* mass_f = (int*)calloc(6, sizeof(int));
	char* mass_flags[6] = { "-m1", "-m2", "-n", "-c", "-a", "-C" }; 
	if (mass_f == NULL) {
		printf(ERROR_MEMORY);
		exit(1);
	}
	for (int i = 0; i < size - 1; ++i) {
		for (int k = 0; k < 6; k++) {
			if (strcmp(mass[i], mass_flags[k]) == 0) {
				if (i != 0) {
					if (strcmp(mass[i - 1], "-a") != 0) {
						mass_f[k]++;
					}
					else {
						if (i > 1) {
							if (strcmp(mass[i - 2], "-a") == 0) {
								mass_f[k]++;
							}
						}
					}
				}
				else {
					mass_f[k]++;
				}
			}
		}
	}
	return mass_f;
}

// Функция для проверки на совместимость флагов 

int checking_flags(char** mass, int size) {
	int* mass_f = kolvo_flags(mass, size);
	if (mass_f[0] == 1) {
		if(mass_f[1] != 1) return 2;
		if (mass_f[2] > 0) return 2;
	}
	else if (mass_f[0] > 1) return 2;
	else {
		if (mass_f[1] > 0) return 2;
		if (mass_f[2] < 1) return 2;
	}
	if (mass_f[4] == 1) {
		if (mass_f[5] > 0) return 2;
	}
	else if (mass_f[4] > 1) return 2;
	if (mass_f[4] == 0) {
		if (mass_f[5] == 0) return 2;
	}
	if (mass_f[2] > 1) return 2;
	if (mass_f[3] > 1) return 2;
	if (mass_f[5] > 1) return 2;
	free(mass_f);
	return 0;
}

//Функция для проверки корректности введенных флагов
//Пример что если -a aAA тут функция выдаст ошибку, потому что повторяются A

int checking_correctness_flag_arguments(char** mass, int size) {
	for (int i = 0; i < size - 1; ++i) {
		if (strcmp(mass[i], "-m1") == 0 || strcmp(mass[i], "-n") == 0 || strcmp(mass[i], "-m2") == 0 || strcmp(mass[i], "-c") == 0) {
			int flag = 0;
			if (i != 0) {
				if (strcmp(mass[i - 1], "-a") != 0) flag = 1;
			}
			else flag = 1;
			if (flag == 1) {
				if (i == size - 2) return 2; 
				size_t len = strlen(mass[i + 1]);
				for (int j = 0; j < len; ++j) {
					if (mass[i + 1][j] < 48 || mass[i + 1][j] > 57) return 1;
				}
				char mass_d[] = { '2','1','4','7','4','8','3','6','4','7' };
				if (len == 10) {
					if (mass[i + 1][0] > mass_d[0]) return 1;
					if (mass[i + 1][0] == mass_d[0]) {
						for (int j = 1; j < len; ++j) if (mass[i + 1][j] > mass_d[j]) return 1;
					}
				}
			}
		}
		if (strcmp(mass[i], "-C") == 0) {
			int flag = 0;
			if (i != 0) {
				if (strcmp(mass[i - 1], "-a") != 0) flag = 1;
			}
			else flag = 1;
			if (flag == 1) {
				if (i == size - 2) return 2;
				size_t len = strlen(mass[i + 1]);
				int* mass_check = (int*)malloc(len * sizeof(int));
				if (mass_check == NULL) {
					printf(ERROR_MEMORY);
					exit(0);
				}
				for (int j = 0; j < len; ++j) {
					mass_check[j] = mass[i + 1][j];
				}
				for (int j = 0; j < len; ++j) {
					if (mass[i + 1][j] != 97 && mass[i + 1][j] != 65 && mass[i + 1][j] != 68 && mass[i + 1][j] != 83) return 1;
				}
				for (int j = 0; j < len; ++j) {
					for (int k = 0; k < len; ++k) {
						if (j != k) {
							if (mass_check[j] == mass_check[k]) return 1;
						}
					}
				}
				free(mass_check);
			}
		}
		if (strcmp(mass[i], "-a") == 0) {
			int flag = 0;
			if (i != 0) {
				if (strcmp(mass[i - 1], "-a") != 0) flag = 1;
			}
			else flag = 1;
			if (flag == 1) {
				if (i == size - 2) return 2;
			}
		}
	}
	return 0;
}

//Создает алфавит если введен флаг -a

char* create_alphabet(char* alph) {
	const char mass_mini[] = "abcdefghijklmnopqrstuvwxyz";
	const char mass_maxi[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char mass_chislo[] = "0123456789";
	const char mass_simvol[] = "!@#$%^&*_?:;";
	size_t len = strlen(alph);
	int size = 0;
	int mass_b[] = { 0,0,0,0 };
	for (int i = 0; i < len; ++i) {
		if (alph[i] == 97){
			mass_b[0]++;
			size += strlen(mass_mini);
		}
		if (alph[i] == 65) {
			mass_b[1]++;
			size += strlen(mass_maxi);
		}
		if (alph[i] == 68) {
			mass_b[2]++;
			size += strlen(mass_chislo);
		}
		if (alph[i] == 83) {
			mass_b[3]++;
			size += strlen(mass_simvol);
		}
	}
	char* alphabet = (char*)malloc((size+1) * sizeof(char));
	int index = 0;
	if (mass_b[0] > 0) {
		for(int i = 0; i < strlen(mass_mini); ++i) {
			alphabet[i] = mass_mini[i];
		}
		index = strlen(mass_mini);
	}
	if (mass_b[1] > 0) {
		for (int i = index; i < strlen(mass_maxi) + index; ++i) {
			alphabet[i] = mass_maxi[i - index];
		}
		index += strlen(mass_maxi); 
	}
	if (mass_b[2] > 0) {
		for (int i = index; i < strlen(mass_chislo) + index; ++i) {
			alphabet[i] = mass_chislo[i - index];
		}
		index += strlen(mass_chislo);
	}
	if (mass_b[3] > 0) {
		for (int i = index; i < strlen(mass_simvol) + index; ++i) {
			alphabet[i] = mass_simvol[i - index];
		}
		index += strlen(mass_simvol);
	}
	alphabet[index] = '\0';
	return alphabet;
}

//Функция которая смотрит какой флаг длинны введен, и флаг кол-во длинны
//Если -n то сразу передает его в функцию, но если флаги -m1 и -m2
//То выбирается рандомная длинна из заданного диапазона

char** pred_generator(char* alphabet, char** mass, int size) {
	int* kol_flag = kolvo_flags(mass, size);
	int len_password = 0;
	int kol_password = 1;
	if (kol_flag[0] == 1 && kol_flag[1] == 1) {
		int len1 = 0;
		int len2 = 0;
		for (int i = 0; i < size - 1; ++i) {
			if (strcmp(mass[i], "-m1") == 0) len1 += atoi(mass[i + 1]);
			if (strcmp(mass[i], "-m2") == 0) len2 += atoi(mass[i + 1]);
		}
		if (len1 > len2) {
			printf(ERROR_M1_M2_LEN);
			exit(1);
		}
		if (len1 == 0 && len2 == 0) {
			printf(ERROR_LEN);
			exit(1);
		}
		len_password = len2 - len1 + 1;
		len_password = len1 + rand() % len_password;
		if (len_password == 0) {
			printf(ERROR_LEN);
			exit(1);
		}
	}
	else {
		for (int i = 0; i < size - 1; ++i) {
			if (strcmp(mass[i], "-n") == 0) len_password = atoi(mass[i + 1]);
		}
		if (len_password == 0) {
			printf(ERROR_LEN);
			exit(1);
		}
	}
	for (int i = 0; i < size - 1; ++i) {
		if (strcmp(mass[i], "-c") == 0) kol_password = atoi(mass[i + 1]);
	}
	char** password = (char**)malloc(kol_password * sizeof(char*));
	if (password == NULL) {
		printf(ERROR_MEMORY);
		exit(1);
	}
	for (int i = 0; i < kol_password; ++i) {
		password[i] = generator_password(alphabet, len_password);
	}
	free(kol_flag);
	return password;
}

//функция генерации пароля

char* generator_password(char* alphabet, int size) {
	char* alph = (char*)malloc((size + 1) * sizeof(char));
	if (alph == NULL) {
		printf(ERROR_MEMORY);
		exit(1);
	}
	for (int i = 0; i < size; ++i) {
		int index = rand() % strlen(alphabet);
		alph[i] = alphabet[index];
	}
	alph[size] = '\0';
	return alph;
}

void print(char** mass, char** passwd, int size) {
	int len = 1;
	for (int i = 0; i < size - 1; ++i) {
		if (strcmp(mass[i], "-c") == 0) {
			len = atoi(mass[i + 1]);
			break;
		}
	}
	for (int i = 0; i < len; ++i) {
		printf("%s\n", passwd[i]);
	}
}