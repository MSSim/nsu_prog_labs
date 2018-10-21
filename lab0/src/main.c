#include <stdio.h>
#include <string.h>
#define SIZESTR 60

long long power(long long a, long long power) {
    long long solve = 1;
    for (long long i = 0; i < power; i++)
        solve *= a;
    return solve;
}

long long charToDec(char a) {
    char *alphabet = "aAbBcCdDeEfF";
    if (a >= '0' && a <= '9') {
        return a - '0';
    }
    for (long long i = 0; i < strlen(alphabet); i++) {
        if (a == alphabet[i])
            return 10 + i / 2;
    }
    return -1;
}

char decToChar(long long a) {
    if ((a > 9) && (a < 16))
        return (char) (a + 'a' - 10);
    if (a >= 0 && a < 10)
        return (char) ('0' + a);
    return -1;
}

long long b1_to_dec(long long b1, const char *do_tochki) {
    long long solve = 0;
    size_t n = strlen(do_tochki);
    for (long long i = 0; i < n; i++)
        solve = solve + charToDec(do_tochki[i]) * power(b1, n - i - 1);
    return solve;
}

double b1_to_drob(long long b1, char *posle_tochki) {
    double solve = 0;
    long long n = strlen(posle_tochki);
    for (long long i = 0; i < n; i++)
        solve = solve + (double) (charToDec(posle_tochki[i])) / power(b1, i + 1);
    return solve;
}

void print_dec_to_b2(long long b2, long long dec) {
    char ob_solve[SIZESTR] = {0};
    long long i = 0;
    while (dec / b2 != 0) {
        ob_solve[i] = decToChar(dec % b2);
        dec /= b2;
        i++;
    }
    ob_solve[i] = decToChar(dec);

    int len_ob_solve = strlen(ob_solve);

    for (i = 0; ob_solve[i] != '\0'; i++) {

        printf("%c", ob_solve[len_ob_solve - i - 1]);
    }
}

void print_drob_to_b2(long long b2, double drob) {
    if (drob != 0)
        printf(".");

    for (int i=0; i < 30 && drob != 0; i++) {
        drob *= b2;
        printf("%c", decToChar((long long) drob));
        drob -= (long long) drob;
        i++;
    }
}

void print_result(int b1, int b2,  char *nums) {
    char do_tochki[15] = {0};
    char posle_tochki[15] = {0};
    int i = 0;
    for (; nums[i] != '\0'; i++) {
        if (nums[i] == '.') break;
        do_tochki[i] = nums[i];
    }
    long long len_do_tochki = strlen(do_tochki);
    for (i++; nums[i] != '\0'; i++) {
        posle_tochki[i - len_do_tochki - 1] = nums[i];
    }

    long long dec = b1_to_dec(b1, do_tochki);
    double drob = b1_to_drob(b1, posle_tochki);
    print_dec_to_b2(b2, dec);
    print_drob_to_b2(b2, drob);
}

long long test(long long b1, long long b2, char *nums) {
    if (b1 < 2 || b2 < 2 || b1 > 16 || b2 > 16 || nums[0] == '.' || nums[strlen(nums) - 1] == '.')
        return -1;
    long long s = 0;
    for (long long i = 0; nums[i] != '\0'; i++) {
        if (charToDec(nums[i]) >= b1 && nums[i] != '.')
            return -1;
        if (charToDec(nums[i]) == -1 && nums[i] != '.')
            return -1;
        if (nums[i] == '.')
            s++;
    }
    if (s > 1)
        return -1;

    return 0;
}

int main() {
    int b1, b2;
    char nums[15];
    scanf("%d%d%s", &b1, &b2, nums);

    if (test(b1, b2, nums) == -1) {
        printf("bad input");
        return 0;
    }

    print_result(b1, b2, nums);
    return 0;
}
