#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

FILE* open_file_read(char* name) {
	FILE* input;
	if (fopen_s(&input, name, "r")) {
		printf(ERROR_FILE);
		exit(1);
	}
	return input;
}

FILE* open_file_write(char* name) {
	FILE* output;
	if (fopen_s(&output, name, "w")) {
		printf(ERROR_FILE);
		exit(1);
	}
	return output;
}

void Replacement(char* pod, char* zam, FILE* input, FILE* output) {
	int FlagMemory = 0, FlagSimvol = 0, SizePod = strlen(pod), SizeZam = strlen(zam), index = 0, \
		CountCoincidence = 0, CountBits = 0, indexCheck = 0, countCoin = 0, save = 0, saveFlag = 0, ffff = -1;
	char buf[SIZE_BUFFER];
	int* key = (int*)malloc(strlen(pod) * sizeof(int));
	int* valueLen = (int*)malloc(strlen(pod) * sizeof(int));
	for (int i = 1; i < strlen(pod); ++i) {
		if (pod[indexCheck] == pod[i]) {
			indexCheck++;
			if (saveFlag == 0) {
				save = i;
				saveFlag = 1;
			}
		}
		else {
			if (indexCheck != 0) {
				key[countCoin] = save;
				valueLen[countCoin] = indexCheck;
				countCoin++;
				indexCheck = 0;
				i = save;
				save = 0;
				saveFlag = 0;
			}
		}
	}
	while (1) {
		CountBits = fread(buf, 1, SIZE_BUFFER, input);
		if (CountBits == 0) break;
		for (int i = 0; i < CountBits; ++i) {
			if (buf[i] == pod[index]) {
				int flag = 0;
				for (int k = index; i < CountBits; ++i, ++k) {
					if (k == SizePod) break;
					if (buf[i] == pod[k]) {
						for (int l = 0; l < countCoin; ++l) {
							if (k == key[l]) ffff = key[l] - 1;
						}
						CountCoincidence++;
					}
					else {
						flag = 1;
						break;
					}
				}
				if (CountCoincidence == SizePod) {
					fwrite(zam, 1, SizeZam, output);
					printf("%s", zam);
					CountCoincidence = 0;
					index = 0;
					i = i - 1;
					FlagMemory = 0;
				}
				else if (CountCoincidence < SizePod && flag == 0) {
					index += (CountCoincidence-index);
					FlagMemory = 1;
					break;
				}
				else if (flag == 1) {
					int curIndex = ffff + 1;
					index = 0;
					int backLen = -1;
					int flaggg = 0;
					for (int k = 0; k < countCoin; ++k) {
						if (curIndex == key[k]) {
							index = key[k]-1;
							backLen = key[k] - 1;
							flaggg = 1;
							break;
						}
					}
					if (flaggg == 1) {
						fwrite(pod, 1, CountCoincidence - (backLen + 1), output);
						for (int k = 0; k < (CountCoincidence - (backLen + 1));++k) {
							printf("%c", pod[k]);
						}
						CountCoincidence = backLen;
						i = i - 2;
						flaggg = 0;
						ffff = -1;
					}
					else {
						fwrite(pod, 1, CountCoincidence - (backLen + 1), output);
						for (int k = 0; k < (CountCoincidence - (backLen + 1));++k) {
							printf("%c", pod[k]);
						}
						CountCoincidence = backLen+1;
						i = i - 1;
					}
					FlagMemory = 0;
				}
			}
			else {
				fwrite(buf + i, 1, 1, output);
				printf("%c", buf[i]);
			}
			if (FlagSimvol == 1) {
				fwrite(buf + i, 1, 1, output);
				printf("%c", buf[i]);
				FlagSimvol = 0;
			}
		}
	}
	printf("\n");
}