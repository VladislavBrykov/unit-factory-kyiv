void mx_printchar(char c);

void mx_printint(int n) {
    long number = n;  //[-2 147 483 647, +2 147 483 647]
    if (number < 0) {
	mx_printchar('-'); //vivodim - pered chislom
        number = (number * -1);
    }
    if (number >= 10)
        mx_printint(number / 10);
    mx_printchar(number % 10 + 48);
}

//int main()
//{
//	mx_printint(-45756);
//	return 0;
//}
