#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bad_input() {
	printf("bad input");
	exit(0);
}



int main()
{
	int i, n, j = 0, b_1, b_2, c_1;
	long long int resz_10;
	double res_10;
	char c = '0';
	int mas[48];
	
	for (i = 0; i < 48; i++) {
		mas[i] = -1;
	}
	
	scanf("%d%d", &b_1, &b_2);
	if (b_1 < 2 || b_1>16) {
		bad_input();
	}
	if (b_2 < 2 || b_2>16) {
		bad_input();
	}
	getchar();


	for (i = 0; i < 12; i++)
	{
		c = getchar();         //посимвольно ввожу строку и заполняю числовой массив
		c_1 = (int)c;
		if (c_1 < 65)
		{
			mas[i] = c_1 - '0';
		}
		else {
			if (c_1 < 97) {
				mas[i] = c_1 - 'A' + 10;
			}
			else {
				mas[i] = c_1 - 'a' + 10;
			}
		}
		if (mas[i] >= b_1) { bad_input(); }
		if (c == '\n') { break; }

	}
	res_10 = 0;
	resz_10 = 0;
	for (i = 0; i < 122; i++)
	{
		if (mas[i] >= 0)
		{
			resz_10 = resz_10 * b_1 + mas[i];    //перевожу целую часть в 10 систему счисления по схеме Горнера
		}
		else {
			j = i + 1;   //присваиваю номер эллемента массива, с которого начинается вещественная часть числа
			break;
		}
	}

	n = -1;
	for (i = j; i < 12; i++)
	{

		if (mas[i] >= 0) {

			res_10 = res_10 + pow(b_1, n)*mas[i];  //перевожу вещественную часть в 10 систему счисления
			n = n - 1;

		}
		else { break; }
	}

	if (b_2 == 10) { printf("%f", res_10 + resz_10); }

	else
	{

		for (i = 0; i < 48; i++) { //сбрасываю значения эллементов массива
			mas[i] = -1;
		}


		j = 0;
		for (i = 0; i < 48; i++)
		{
			if (resz_10 >= b_2) {     //перевожу целую часть из 10 в нужную систему счисления 
				mas[i] = resz_10 % b_2;
				resz_10 = (long long int)(resz_10 / b_2);
			}
			else {
				mas[i] = resz_10;
				j = i + 2;   //присваиваю номер эллемента массива, с которого будет начинаться вещественная часть
				break;
			}
		}
		for (i = j; i < 48; i++) { //перевожу вещественную часть из 10 в нужную систему счисления
			if (res_10 != 0) {
				mas[i] = (int)(res_10*b_2);
				res_10 = res_10 * b_2 - mas[i];
			}
		}



		j = j - 2;  //присваиваю номер эллемента, которым заканчивается целая часть

		for (i = j; i >= 0; i--) { //вывжу в обратном порядке целую часть
			if (mas[i] < 10) {
				printf("%d", mas[i]);
			}
			else {
				printf("%c", mas[i] - 10 + 'A');
			}
		}
		printf(".");

		j = j + 2; //присваиваю номер эллемента, с которого начинается вещественная часть

		for (i = j; i < 48; i++) { //вывожу вещественную часть

			if (mas[i] >= 0) {

				if (mas[i] < 10) {
					printf("%d", mas[i]);
				}
				else {
					printf("%c", mas[i] - 10 + 'A');
				}
			}
		}
	}


	
	system("pause");
	return (0);
}
