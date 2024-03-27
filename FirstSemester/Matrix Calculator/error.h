#define ERR_INCOR_INP_SIMVOL "ERROR: incorrect input characters\n"
#define ERR_INCOR_INP_WHITESPACE "ERROR: incorrect input whitespace\n"
#define ERR_INCOR_INP_MATRIX "ERROR: incorrect input matrix\n"

void cheking_zero(FILE* in);
FILE* cheking_whitespace(FILE* in, const char* name);
void cheking_simvol(FILE* in);
void cheking_col_matrix(FILE* in);
void cheking_all(FILE* in1, FILE* in2);