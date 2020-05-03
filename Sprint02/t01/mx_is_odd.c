#include <stdbool.h>
//#include <stdio.h>

bool mx_is_odd(int value) {
	if (value % 2 == 0)
		return false;
	else
		return true;
}

//bool mx_is_odd(int value) {  //dla proverki
//        if (value % 2 == 0)
//                printf("false");
//        else
//                printf("true");
//		return 0;
//}
//int main()
//{
//	mx_is_odd(4);
//}
