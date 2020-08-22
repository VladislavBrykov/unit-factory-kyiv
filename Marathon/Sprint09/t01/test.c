#include "macros.h"

int main() {
	int x = -5;
	int y = 6;

	printf("X:  %d\n", x);
	printf("Y:  %d\n", y);

	int result = MX_SUM(x, y);
	printf("MX_SUM:  %d\n", result);

	int result1 = MX_MULT(x, y);
	printf("MX_MULT:  %d\n", result1);

	int result2 = MX_MIN(x, y);
	printf("MX_MIN:  %d\n", result2);

	int result3 = ABS(x);
	printf("ABS:  %d\n", result3);

	int result4 = MX_IS_ODD(y);
	printf("MX_IS_ODD:  %d\n", result4);

}
