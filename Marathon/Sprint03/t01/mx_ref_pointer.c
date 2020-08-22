//#include <stdio.h>

void mx_ref_pointer(int i, int ******ptr) { //new function
	*****ptr = &i;
}

//int main()
//{
//	int i = 4;
//	int *pam;
//	int **pam1 = &pam;
//	int ***pam2 = &pam1;
//	int ****pam3 = &pam2;
//	int *****pam4 = &pam3;
//	int ******pam5 = &pam4;
//	mx_ref_pointer(i, pam5);
//	printf("%d\n", ******pam5);
//} 
