#include <unistd.h>
#include <time.h>
#include <stdio.h>

double mx_timer(void (*f)()) {
	clock_t start = clock();
	/*f("qwweertyyuiuojfhdfhdfhdgjgfjfhjhgkgjkjhljhljkjk");*/
	f();
	clock_t finish = clock();

	if(start == finish)
		return -1;

	return(double)(finish - start)/CLOCKS_PER_SEC;
}


/*void mx_strlen(const char *s) {
	for(int i = 0; s[i] != '\0'; i++)
		printf("%c", s[i]);

}

int main() {
double a = mx_timer(mx_strlen);
printf("%f", a);

}
*/
/*
Тип данных способный представлять временные тики. сlock_t

CLOCKS_PER_SEC Этот макрос заменяется на значение, представляющее число тиков в 
секунду, которое возвращает функция clock. Таким образом, везде, где
мы используем слово CLOCKS_PER_SEC, программа расценивает его как некое
число, обозначающее количество тиков в секунду. Для каждой
системы это число различно. Разделив общее количество тиков на
число тиков в секунду мы получаем  количество секунд. Например, 
общее число тиков мы получим с помощью функции clock, а вместо 
количества тиков в секунду  подставим в формулу соответствующий 
макрос: clock()/CLOCKS_PER_SEC = количество секунд. Таким образом 
можно найти время работы программы
*/
