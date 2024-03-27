#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "function.h"

int main(int argv, char* argc[]) {
	srand((unsigned)time(NULL));
	int max_size = 0;
	for (int i = 0; i < argv - 1; ++i) {
		if (strlen(argc[i+1]) > max_size) {
			max_size = strlen(argc[i+1]);
		}
	}
	char** Mass_flag = (char**)malloc((argv - 1) * sizeof(char*));
	if (Mass_flag == NULL) {
		printf(ERROR_MEMORY);
		return 1;
	}
	for (int i = 0; i < argv - 1; ++i) {
		Mass_flag[i] = argc[i + 1];
	}
	int check = checking_flags(Mass_flag, argv);
	proverka(check);
	check = checking_correctness_flag_arguments(Mass_flag, argv);
	proverka(check);
	int* mass_f = kolvo_flags(Mass_flag, argv);
	char* alphabet;
	if (mass_f[5] == 1) {
		int index = 0;
		for (int i = 0; i < argv - 1;++i) {
			if (strcmp(argc[i + 1], "-C") == 0) {
				index = i + 2;
			}
		}
		alphabet = create_alphabet(argc[index]);
	}
	else {
		int index = 0;
		for (int i = 0; i < argv - 1; ++i) {
			if (strcmp(Mass_flag[i], "-a") == 0) {
				index = i + 1;
				break;
			}
		}	
		alphabet = Mass_flag[index];
	}
	char** password = pred_generator(alphabet, Mass_flag, argv);
	print(Mass_flag, password, argv);
	int kol = 1;
	for (int i = 0; i < argv - 1; ++i) {
		if (strcmp(Mass_flag[i], "-c") == 0) {
			kol = atoi(Mass_flag[i + 1]);
		}
	}
	for (int i = 0; i < kol; ++i) {
		free(password[i]);
	}
	free(password);
	free(mass_f);
	free(Mass_flag);
	return 0;
}