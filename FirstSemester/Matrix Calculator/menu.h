
#define ERROR_FILE "The file didn't open"
#define ERROR_MEMORY "Does not fit in memory"
#define MAX_DLINA 50

struct Matrix {
	int col;
	int str;
	double** matrix;
	double det;
	int count_det;
};
typedef struct Matrix matrix_all;

void glavnoe_menu(matrix_all* matrix1, matrix_all* matrix2);
void Deduction_menu(matrix_all* matrix1, matrix_all* matrix2);
void Multiplication_menu(matrix_all* matrix1, matrix_all* matrix2);
void Transposition_menu(matrix_all* matrix1, matrix_all* matrix2);
void Determinant_menu(matrix_all* matrix1, matrix_all* matrix2);
