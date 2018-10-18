#include <stdio.h>
#include <string.h>
//n2-степень в которую переводим
//l-цифры вводимой переменной после точки после перевода в 10 степень
//vavoddrob-функция ввывода значения переменной после точки
int vavoddrob(int n2,long double l){
    for (int i=0;(i<13);++i){
        if (((int)(l * n2)) > 9){
            printf("%c",(((int)(l * n2)) + 55));
            l=l * n2 - (int) (l* n2);}
        else {printf("%d",(int)(l * n2));l = l * n2 - (int)(l * n2);}}
    return 0;
}
//hg-вводимая переменная представленная в виде множества char элементов
//g-цифры вводимой переменной до точки после перевода в 10 степень
//h-проверка на наличие точки (1-есть точка ,0-нет токи)
//p-счетчик дробной части ,который в функции vavodcel переделывается в число счёта длины ввыводимого числа
//vavodcel-функция ввывода значения переменной до точки и если есть значения после точки ,то функция vavoddrob
int vavodcel( int n2,long double l,char *hg,long long int g,long long int p,int h,int q){
    if (((g==0)&&(l==0))&&(q==1)){if (h==1){printf("bad input");} else printf("0");}
    else{ if (q!=0){ if (0 == g){printf("0");}
    for (int i=0;(0 < g);++i,++p){
                        if ((g % n2) > 9){
                            hg[i] = (char) (55 + (int)(g % n2));
                            g=g / n2;}else{
                            hg[i] = (char)((int)(g % n2) + '0');
                            g=(g / n2);}}}
                for (int i=(int)(p-1);(0<=i);--i){
                    printf("%c",hg[i]);}
                if (l > 0){printf(".");
                    vavoddrob(n2,l);}};
                return 0;
}
int main(void) {
    //q-проверка ошибки (q=1 нет ошибок ,q=0 есть ошибка)
    int n1,n2,k,h=0,q=1;
    char hg[52];
    signed long long int g=0,x=1,p=0;
   long double l;
    scanf("%d",&n1);
    scanf("%d\n",&n2);
    scanf("%s",hg);
    //k-длинна вводимой строки
    k = (int)strlen(hg);
    if (n1<2 || n1>16 || n2<2 || n2>16){
        printf("bad input");}
    else{
        //z-число i элемента hg переведённого в 10 степень ,нужен чтобы не проводить частых пересчётов для проверок
        for (int  i = 0,z = 0; (i < k); ++i){
            z= 0; //не сокращаймая строка ,без неё не проходит тестер (копмилю ровно ,что мы задали z строкой выше?)
            if(hg[i] >= 97){z = hg[i] - 87; if (z >= n1){printf("bad input");q=0;break;}}
            else{if(hg[i] >= 65){z = hg[i] - 55;if (z >= n1){printf("bad input");q=0;break;}}}
            if (hg[i] != '.'){
                if (h >= 1){
                    if (z <= 0) {if((hg[i] - '0') >= n1){printf("bad input");q=0;break;}else{
                        //x-счетчик стени ,нужен для вычесления l
                            x = x * n1;
                            p = ( p * n1 + ( hg[i] - '0'));}
                    }else{ x = x * n1;
                        p = ( p * n1 + z);}}else{
                    if (z <= 0) {if ((hg[i] - '0') >= n1){printf("bad input");q=0;break;}else{g = ((g + (hg[i] - '0')) * n1);}}
                    else{g = (g + z) * n1;}}
            }else{h = 1;}}
        l = (long double)p/x;
        p = 0;
        g = g / n1;
        vavodcel(n2,l,hg,g,p,h,q);}
    return 0;}