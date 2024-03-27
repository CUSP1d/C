#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ERROR_OPEN_FILE "File opening error\n"
#define STRINGS_COUNT 1000
#define MAX_STRING_SIZE 20
#define MAX_STR_SIZE 50

char* GenerateRandomString(unsigned int max_size) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned int size = rand() % max_size + 1;
    char* str = (char*)malloc((size + 1) * sizeof(char));
    if (str == NULL) {
        printf("ERROR\n");
        exit(1);
    }
    for (int i = 0; i < size; ++i) {
        int tmp = rand() % strlen(alphabet);
        str[i] = alphabet[tmp];
    }
    str[size] = '\0';
    return str;
}


void GenerateRandomStrings(FILE* output) {

    for (int i = 0; i < STRINGS_COUNT; ++i) {
        char* str = GenerateRandomString(MAX_STR_SIZE);
        fputs(str, output);
        fputs("\n", output);
    }
}

void PrintStrings(char staticStrings[STRINGS_COUNT][MAX_STRING_SIZE], char** dynamicStrings) {
    for (int i = 0; i < STRINGS_COUNT; ++i) {
        int flag = 0;
        for (int j = 0; j < MAX_STRING_SIZE; ++j) {
            if (staticStrings[i][j] == '\0') {
                flag = 1;
                break;
            }
            printf("%c", staticStrings[i][j]);
        }
        if (flag == 0) {
            printf("%s", dynamicStrings[i]);
        }
        printf("\n");
    }
}

int Len_static(char* stat) {
    int size = 0;
    int flag = 0;
    for (int i = 0; i < MAX_STRING_SIZE; ++i) {
        if (stat[i] == '\0') {
            flag = 1;
            size += i;
            break;
        }
    }
    if (flag == 0) {
        size += MAX_STRING_SIZE;
    }
    return size;
}

int Len_dynem(char* mass) {
    if (mass == NULL) {
        return 0;
    }
    int size = 0;
    int i = 0;
    while (mass[i] != '\0') {
        size++;
        i++;
    }
    return size;
}

int sort1(char* arr1, char* arr2, int s_d) {
    int size = 0;
    int size2 = 0;
    if (s_d == 1) {
        size = Len_static(arr1);
        size2 = Len_static(arr2);
    }
    if (s_d == 2) {
        size = Len_dynem(arr1);
        size2 = Len_dynem(arr2);
    }
    if (size > size2) {
        return 1;
    }
    else if (size < size2) {
        return 2;
    }
    else {
        return 3;
    }
}

int sort2(char* arr1, char* arr2, int s_d) {
    int size = 0;
    int size2 = 0;
    if (s_d == 1) {
        size = Len_static(arr1);
        size2 = Len_static(arr2);
    }
    if (s_d == 2) {
        size = Len_dynem(arr1);
        size2 = Len_dynem(arr2);
    }
    if (size > size2) {
        return 2;
    }
    else if (size < size2) {
        return 1;
    }
    else {
        return 3;
    }
}

int sort3(char* arr1, char* arr2, int s_d) {
    if (s_d == 1) {
        int size = Len_static(arr1);
        int size2 = Len_static(arr2);
        int len = 0;
        if (size > size2) len = size2;
        if (size < size2) len = size;
        if (size == size2) len = size;
        int a = 0, b = 0;
        for (int i = 0; i < len; ++i) {
            if (arr1[i] >= 65 && arr1[i] <= 90) a = arr1[i] - 'A';
            if (arr1[i] >= 97 && arr1[i] <= 122) a = arr1[i] - 'a';
            if (arr2[i] >= 65 && arr2[i] <= 90) b = arr2[i] - 'A';
            if (arr2[i] >= 97 && arr2[i] <= 122) b = arr2[i] - 'a';
            if (a > b) return 1;
            else if (a < b) return 2;
        }
        if (size > size2) return 1;
        if (size < size2) return 2;
        if (size == size2) return 3;
    }
    if (s_d == 2) {
        if (arr1 == NULL && arr2 == NULL) return 3;
        if (arr1 == NULL && arr2 != NULL) return 2;
        if (arr1 != NULL && arr2 == NULL) return 1;
        int size = Len_dynem(arr1);
        int size2 = Len_dynem(arr2);
        int len = 0;
        if (size > size2) len = size2;
        if (size < size2) len = size;
        if (size == size2) len = size;
        int a = 0, b = 0;
        for (int i = 0; i < len; ++i) {
            if (arr1[i] >= 65 && arr1[i] <= 90) a = arr1[i] - 'A';
            if (arr1[i] >= 97 && arr1[i] <= 122) a = arr1[i] - 'a';
            if (arr2[i] >= 65 && arr2[i] <= 90) b = arr2[i] - 'A';
            if (arr2[i] >= 97 && arr2[i] <= 122) b = arr2[i] - 'a';
            if (a > b) return 1;
            else if (a < b) return 2;
        }
        if (size > size2) return 1;
        if (size < size2) return 2;
        if (size == size2) return 3;
    } 
}

int sort4(char* arr1, char* arr2, int s_d) {
    if (s_d == 1) {
        int size = Len_static(arr1);
        int size2 = Len_static(arr2);
        int len = 0;
        if (size > size2) len = size2;
        if (size < size2) len = size;
        if (size == size2) len = size;
        int a = 0, b = 0;
        for (int i = 0; i < len; ++i) {
            if (arr1[i] >= 65 && arr1[i] <= 90) a = arr1[i] - 'A';
            if (arr1[i] >= 97 && arr1[i] <= 122) a = arr1[i] - 'a';
            if (arr2[i] >= 65 && arr2[i] <= 90) b = arr2[i] - 'A';
            if (arr2[i] >= 97 && arr2[i] <= 122) b = arr2[i] - 'a';
            if (a > b) return 2;
            else if (a < b) return 1;
        }
        if (size > size2) return 2;
        if (size < size2) return 1;
        if (size == size2) return 3;
    }
    if (s_d == 2) {
        if (arr1 == NULL && arr2 == NULL) return 3;
        if (arr1 == NULL && arr2 != NULL) return 1;
        if (arr1 != NULL && arr2 == NULL) return 2;
        int size = Len_dynem(arr1);
        int size2 = Len_dynem(arr2);
        int len = 0;
        if (size > size2) len = size2;
        if (size < size2) len = size;
        if (size == size2) len = size;
        int a = 0, b = 0;
        for (int i = 0; i < len; ++i) {
            if (arr1[i] >= 65 && arr1[i] <= 90) a = arr1[i] - 'A';
            if (arr1[i] >= 97 && arr1[i] <= 122) a = arr1[i] - 'a';
            if (arr2[i] >= 65 && arr2[i] <= 90) b = arr2[i] - 'A';
            if (arr2[i] >= 97 && arr2[i] <= 122) b = arr2[i] - 'a';
            if (a > b) return 2;
            else if (a < b) return 1;
        }
        if (size > size2) return 2;
        if (size < size2) return 1;
        if (size == size2) return 3;
    }
}

void SortStrings(char staticStrings[STRINGS_COUNT][MAX_STRING_SIZE], char** dynamicStrings, int left, int right, int (*sortFunc)(char*, char*, int)) {
    if (left >= right) return;
    int i = left;
    int j = right;
    int p = (left + right) / 2;
    int lenstat = Len_static(staticStrings[p]);
    char pstatic[MAX_STRING_SIZE];
    char* pdynemic = NULL;
    if (dynamicStrings[p] != NULL) {
        pdynemic = dynamicStrings[p];
    }
    for (int k = 0; k < lenstat; ++k) {
        pstatic[k] = staticStrings[p][k];
    }
    if (lenstat < MAX_STRING_SIZE) {
        pstatic[lenstat] = '\0';
    }
    
    while (i <= j) {
        int resleft = sortFunc(staticStrings[i], pstatic, 1);
        int resright = sortFunc(staticStrings[j], pstatic, 1);
        if (resleft == 3) {
            resleft = sortFunc(dynamicStrings[i], pdynemic, 2);
        }
        if (resright == 3) {
            resright = sortFunc(dynamicStrings[j], pdynemic, 2);
        }
        while (resleft == 2) {
            i++;
            resleft = sortFunc(staticStrings[i], pstatic, 1);
            if (resleft == 3) {
                resleft = sortFunc(dynamicStrings[i], pdynemic, 2);
            }
        }
        while (resright == 1) {
            j--;
            resright = sortFunc(staticStrings[j], pstatic, 1);
            if (resright == 3) {
                resright = sortFunc(dynamicStrings[j], pdynemic, 2);
            }
        }
        if (i <= j) {
            if (i != j) {
                int size = Len_static(staticStrings[i]);
                int size2 = Len_static(staticStrings[j]);
                char tmp[MAX_STRING_SIZE] = { 0 };
                for (int k = 0; k < size; ++k) {
                    tmp[k] = staticStrings[i][k];
                }
                if (size < MAX_STRING_SIZE) {
                    tmp[size] = '\0';
                }
                for (int k = 0; k < size2; ++k) {
                    staticStrings[i][k] = staticStrings[j][k];
                }
                if (size2 < MAX_STRING_SIZE) {
                    staticStrings[i][size2] = '\0';
                }
                for (int k = 0; k < size; ++k) {
                    staticStrings[j][k] = tmp[k];
                }
                if (size < MAX_STRING_SIZE) {
                    staticStrings[j][size] = '\0';
                }
                char* tmpe = dynamicStrings[i];
                dynamicStrings[i] = dynamicStrings[j];
                dynamicStrings[j] = tmpe;
            }
            i++;
            j--;
        }
    }
    SortStrings(staticStrings, dynamicStrings, left, j, sortFunc);
    SortStrings(staticStrings, dynamicStrings, i, right, sortFunc);
}

void read_file(FILE* output, char static_mass[STRINGS_COUNT][MAX_STRING_SIZE], char** dynamic_mass) {
    char tmp;
    int j = 0;
    int flag = 0;
    char save_tmp;
    for (int i = 0; i < STRINGS_COUNT; ++i) {
        j = 0;
        while (j != MAX_STRING_SIZE) {
            tmp = fgetc(output);
            if (tmp == '\n') {
                static_mass[i][j] = '\0';
                flag = 1;
                break;
            }
            static_mass[i][j] = tmp;
            j++;
        }
        j = 0;
        if (flag != 1) {
            dynamic_mass[i] = (char*)malloc(sizeof(char));
            while (1) {
                tmp = fgetc(output);
                if (tmp == '\n') {
                    dynamic_mass[i][j] = '\0';
                    break;
                }
                dynamic_mass[i][j] = tmp;
                j++;
                dynamic_mass[i] = (char*)realloc(dynamic_mass[i], sizeof(char) * (j + 1));
            }
        }
        else {
            dynamic_mass[i] = NULL;
        }
        flag = 0;
    }
}

int main(int argc, char* argv[]) {
    srand((unsigned)time(NULL));
    int flag = atoi(argv[2]);
    FILE* output;
    if (fopen_s(&output, argv[1], "w")) {
        printf(ERROR_OPEN_FILE);
        exit(1);
    }
    char staticStrings[STRINGS_COUNT][MAX_STRING_SIZE];
    char** dynamicStrings = (char**)malloc(STRINGS_COUNT * sizeof(char*));
    if (dynamicStrings == NULL) {
        printf("ERROR memory\n");
        return 1;
    }
    GenerateRandomStrings(output);
    fclose(output);
    if (fopen_s(&output, argv[1], "r")) {
        printf(ERROR_OPEN_FILE);
        exit(1);
    }
    read_file(output, staticStrings, dynamicStrings);
    PrintStrings(staticStrings, dynamicStrings);
    printf("-----------------------------------------------------------\n");
    switch (flag){
    case 1:
        SortStrings(staticStrings, dynamicStrings, 0, STRINGS_COUNT - 1, sort1);
        break;
    case 2:
        SortStrings(staticStrings, dynamicStrings, 0, STRINGS_COUNT - 1, sort2);
        break;
    case 3:
        SortStrings(staticStrings, dynamicStrings, 0, STRINGS_COUNT - 1, sort3);
        break;
    case 4:
        SortStrings(staticStrings, dynamicStrings, 0, STRINGS_COUNT - 1, sort4);
        break;
    default:
        exit(1);
    }
    printf("-----------------------------------------------------------\n");
    PrintStrings(staticStrings, dynamicStrings);
    fclose(output);
    return 0;
}