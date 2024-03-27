#define ERROR_FILE "The file does not open"
#define ERROR_NUMBER "Non-correct characters in the file"
#define ERROR_NAME_LEN "The file name is too long"
#define ERROR_MEMORY "Does not fit in memory"
#define SIZE 32
#define ERROR_INT_MIN "The number is less than INT_MIN"
#define ERROR_INT_MAX "The number is greater than INT_MAX"
#define ERROR_NAME_FILE "The same file name."

void print_arr(int arr[32], FILE* input);
void dop_cod_arr(int t, int arr[32]);
void binar_cod(int arr[32], int y);
int check_simvol(FILE* i);
int sum_number(int y);
void max_strlen(char* name1, char* name2);