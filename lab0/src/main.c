//Введение
//Перевод числа X из системы счисления с основанием n1 в систему с основанием n2.
//
//Дано:
//строка 1:
//целые числа b1 и b2 от 2 до 16 -- основание исходной и конечной системы счисления, разделенные пробелом
//строка 2:
//от 1 до 12 b1-ричных цифр, возможно разделенных точкой на целую и дробную часть.
//Это b1-ричная запись числа X. Всего должно быть не более 13 символов.
//
//Принцип работы
//Считываем вводимую строку попупно переводяи деля число X на 2 части ,1 целая ,2 дробная
//Переводим 1 часть в n2 степень ,разделяя её на символы ,выводим символы задом наперёт (тк после перевода и разделения строка символов зеркальна нужной )
//Переводим 2 часть в n2 степень ,домножаем 2 часть на степень и выводим целую часть из полученного ,пристваиваем 2 части дробную часть полученого числа
//
//Переменные
//n2-степень в которую переводим
//l-цифры вводимой переменной после точки после перевода в 10 степень
//hg-вводимая переменная представленная в виде множества char элементов
//g-цифры вводимой переменной до точки после перевода в 10 степень
//h-проверка на наличие точки (1-есть точка ,0-нет токи)
//p-счетчик дробной части ,который в функции vavodcel переделывается в число счёта длины ввыводимого числа
//x-счетчик стени ,нужен для вычесления l
//z-число i элемента hg переведённого в 10 степень ,нужен чтобы не проводить частых пересчётов для проверок
//k-длинна вводимой строки
//error-проверка ошибки
//
//Макросы
//TSELOE-целая часть дробной части l возведённая в n2
//DROBNOE-дробная часть дробной части l возведённая в n2
//DLINNADROBCHASTI- длинна чисел после точки
//BYKVASMENA-смена в массиве hg  i переменой на нужную ввыводимую впоследствие букву
//CHISLOSMENA-смена в массиве hg  i переменой на нужное ввыводимое впоследствие число
//STIPIN-подсчёт максимального дробного числа  
//
//функции
//vavodcel-подфункция функции main ,функция ввывода значения переменной до точки и если есть значения после точки ,то функция vavoddrob
//vavoddrob-подфункция функции vavodcel ,функция ввывода значения переменной после точки
//main-главная функция 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TSELOE ((int)(l*n2))
#define DROBNOE l=l * n2 - (int) (l * n2);
#define DLINNADROBCHASTI 13
#define BYKVASMENA hg[i] = (char) (55 + (int) (g % n2))
#define CHISLOSMENA hg[i] = (char) ((int) (g % n2) + '0')
#define STIPIN x = x * n1


static int vavoddrob(int n2, long double l) {
    for (int i = 0; (i < DLINNADROBCHASTI); ++i) {
        if (TSELOE > 9) {
            printf("%c", (TSELOE + 55));
            DROBNOE;
        } else {
            printf("%d", TSELOE);
            DROBNOE;
        }
    }
    return 0;
}


static int vavodcel(int n2, long double l, char *hg, long long int g, long long int p, bool point, bool error) {
    if (((g == 0) && (l == 0)) && (error == false)) { if (point == true) { printf("bad input"); } else printf("0"); }
    else {
        if (error != true) {
            if (0 == g) { printf("0"); }
            for (int i = 0; (0 < g); ++i, ++p) {
                if ((g % n2) > 9) {
                    BYKVASMENA;
                    g = g / n2;
                } else {
                    CHISLOSMENA;
                    g = g / n2;
                }
            }
        }
        for (int i = (int) (p - 1); (0 <= i); --i) {
            printf("%c", hg[i]);
        }
        if (l > 0) {
            printf(".");
            vavoddrob(n2, l);
        }
    };
    return 0;
}


int main(void) {

    int n1, n2, k;
    char hg[53];
    signed long long int g = 0, x = 1, p = 0;
    long double l;
    bool point = false, error = false;
    scanf("%d", &n1);
    scanf("%d\n", &n2);
    scanf("%52s", hg);

    k = (int) strlen(hg);
    if (n1 < 2 || n1 > 16 || n2 < 2 || n2 > 16) {
        printf("bad input");
    } else {

        for (int i = 0; (i < k); ++i) {
            int z = 0;
            if (hg[i] >= 97) {
                z = hg[i] - 87;
                if (z >= n1) {
                    printf("bad input");
                    error = true;
                    break;
                }
            } else {
                if (hg[i] >= 65) {
                    z = hg[i] - 55;
                    if (z >= n1) {
                        printf("bad input");
                        error = true;
                        break;
                    }
                }
            }
            if (hg[i] != '.') {
                if (point == true) {
                    if (z <= 0) {
                        if ((hg[i] - '0') >= n1) {
                            printf("bad input");
                            error = true;
                            break;
                        } else {

                            STIPIN;
                            p = (p * n1 + (hg[i] - '0'));
                        }
                    } else {
                        STIPIN;
                        p = (p * n1 + z);
                    }
                } else {
                    if (z <= 0) {
                        if ((hg[i] - '0') >= n1) {
                            printf("bad input");
                            error = true;
                            break;
                        } else { g = ((g + (hg[i] - '0')) * n1); }
                    } else { g = (g + z) * n1; }
                }
            } else { point = true; }
        }
        l = (long double) p / x;
        p = 0;
        g = g / n1;
        vavodcel(n2, l, hg, g, p, point, error);
    }
    return 0;
}
