#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void swap(int p_int[], int tmp, int i, int j) {
    tmp = p_int[i];
    p_int[i] = p_int[j];
    p_int[j] = tmp;
}

int test(const char p_char[], const int p_int[], int count[], size_t size) {
    if (size == 0) {
        printf("bad input");
        return 0;
    }
    for (int k = 0; k < size; k++) {
        if (p_char[k] < '0' || p_char[k] > '9') {
            printf("bad input");
            return 0;
        }
        if (count[p_int[k]] == 1) {
            printf("bad input");
            return 0;
        }
        count[p_int[k]] = 1;
    }
}

int dejkstra_algorithm(int *p_int, int size, int tmp, int n) {
    for (int k = 0; k < n; k++) {
        int i = size - 2;
        int j = size - 1;
        while (i >= 0 && p_int[i] >= p_int[i + 1]) {
            i--;
        }
        if (i == -1)
            return 0;
        while (j > i && p_int[j] <= p_int[i]) {
            j--;
        }
        swap(p_int, tmp, i, j);
        for (int a = i + 1; a < size - 1; a++) {
            if (p_int[a] > p_int[a + 1]) {
                swap(p_int, tmp, a, a + 1);
            }
        }
        for (int l = 0; l < size; l++) {
            printf("%d", p_int[l]);
        }
        printf("\n");
    }
}

int main() {
    char p_char[11];
    int count[10] = {0};
    int p_int[11] = {0};
    int n;
    int tmp;
    scanf("%s", p_char);
    scanf("%d", &n);
    size_t size = strlen(p_char);
    for (int i = 0; i < size; i++) {
        p_int[i] = p_char[i] - '0';
    }
    if (test(p_char, p_int, count, size) == 0)
        return 0;
    dejkstra_algorithm(p_int, size, tmp, n);
}
