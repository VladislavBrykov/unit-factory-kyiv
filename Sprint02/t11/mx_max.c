#include <stdio.h>

int mx_max(int a,int b,int c) {
        if(a > b && a > c) 
        	return a;
        if(b > a && b > c) 
       		return b;
        else
       		return c;
}

//int main()
//{
//        mx_max(3, -1, 4);
//}

//int mx_max(int a,int b,int c) {
//      if (a > b && a > c)
//              printf("%d", a);
//      if (b > a && b > c)
//              printf("%d", b);
//      else
//              printf("%d", c);
//      return 0;
//}
