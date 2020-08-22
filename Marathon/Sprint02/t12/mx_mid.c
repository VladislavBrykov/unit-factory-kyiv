//#include <stdio.h>
#include <stdbool.h>

bool mx_mid(int a, int b, int c)
{
      if (a < b && a > c)
              return a;
      else if (b < a && b < c)
              return b;
      else if (c < a && c > b)
              return c;
      return 0;
}

//{ 					eto mozno ispolzovat dla proverki
//	if (a < b && a > c)
//		printf("%d", a);
//	else if (b < a && b < c)
//		printf("%d", b);
//	else if (c < a && c > b)
//		printf("%d", c);
//	return 0;
//}
//int main()
//{
//	mx_mid(2, 4, 1);
//}
