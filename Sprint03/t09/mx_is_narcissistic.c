#include <stdbool.h>

double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num) {
    int p = 0;
    int b;
    int s;
    int n = num;                        //novie peremennie
    
    for (int i = n; i > 0; i /= 10) { //zapuskaem cikl fof
        p++;                            //yvelichivaem p
    }
    while(n != 0) {                  //poka yslovie sobludaetsa
        b = n % 10;
        s = s + mx_pow(b, p);
        n = n/10;
    }
    if(s == n) {                 //yslovie vivoda rezultata
        return true;
    }
    else{
        return false;
    }
}
