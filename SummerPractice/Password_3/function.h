#pragma once

#define ERROR_MEMORY "Memory allocation error\n"
#define ERROR_FLAG_1 "The values of the flags are entered incorrectly\n"
#define ERROR_FLAG_2 "incorrectly entered flags\n"
#define GOOD_FLAG "the flags are entered correctly\n"
#define SIZE_FLAG 6
#define ERROR_M1_M2_LEN "m1 is more than m2\n"
#define ERROR_LEN "The length cannot be zero\n"
#define ERROR_MAX "Value greater than INT_MAX\n"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Возвращяемые значения                                       |
// 0 - Все хорошо                                              |
// 1 - Неккоректно введены значения флагов                     |
// 2 - Неправильно введены флаги                               |
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

int* kolvo_flags(char**, int);
int checking_flags(char**, int);
int checking_correctness_flag_arguments(char**, int);
void proverka(int);
char* create_alphabet(char*);
char** pred_generator(char*, char**, int);
char* generator_password(char*, int);
void print(char**, char**, int);