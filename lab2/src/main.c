#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 10

void print_error(void) {
    printf("bad input");
    exit(0);
}

static void swap(int *perm_int, int i, int j) {
    int tmp = perm_int[i];
    perm_int[i] = perm_int[j];
    perm_int[j] = tmp;
}

void test(const char *perm_char, const int *p_int, size_t size) {
    bool count[MAX_LEN]={0};
    if (size == 0) exit(0);
    for (int k = 0; k < size; k++) {
        if (perm_char[k] < '0' || perm_char[k] > '9') print_error();
        if (count[p_int[k]] == 1) print_error();
        count[p_int[k]] = 1;
    }
}

void dijkstra_algorithm(int *perm_int, int size, int n) {
    for (int k = 0; k < n; k++) {
        int i = size - 2;
        int j = size - 1;
        while (i >= 0 && perm_int[i] >= perm_int[i + 1]) i--;
        if (i == -1) break;
        while (j > i && perm_int[j] <= perm_int[i]) j--;
        swap(perm_int, i, j);
        for (int a = i + 1; a < size - 1; a++) {
            if (perm_int[a] > perm_int[a + 1]) {
                swap(perm_int, a, a + 1);
            }
        }
        for (int l = 0; l < size; l++) {
            printf("%d", perm_int[l]);
        }
        printf("\n");
    }
}

int main() {
    char perm_char[MAX_LEN + 1];
    int perm_int[MAX_LEN] = {0};
    int n = 0;
    scanf("%10s", perm_char);
    scanf("%d", &n);
    size_t size = strlen(perm_char);
    for (int i = 0; i < size; i++) {
        perm_int[i] = perm_char[i] - '0';
    }
    test(perm_char, perm_int, size);
    dijkstra_algorithm(perm_int, size, n);
}
