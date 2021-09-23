#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	char c, in[64] = { 0 };
	int sch1 = 0;
	double a = 0;

	setlocale(LC_ALL, "Rus"); //

	while ((c = getchar()) != '\n') {
		if (sch1 == 64) {
			printf("Превышен допустимый размер строки\n");
			return 0;
		}
		if ((c > '9' || c < '0') && c != '|') {
			printf("Введены некорректные данные\n");
			return 0;
		}
 in[sch1++] = c;
	}

	if (in[sch1] == 0) {
		while (in[sch1] == 0)
			--sch1;
	}


	int pal = sch1;

	while (in[pal] != '|' && pal > 0)
		pal--;

	if (pal == 0) {
		pal = sch1;
	}

	int uk = sch1;
	while (uk >= 0) {
		if (in[uk] ==  '|') {
			--uk;
			continue;
		}
		a += (double)(in[uk--] - '0') * pow(10, (double)(pal - sch1--));

	}

	printf("%.7f\n", a);

}
