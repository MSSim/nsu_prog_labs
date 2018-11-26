#include <stdio.h>
#include <stdlib.h>

static int *memory_allacation(int n) {
    int *a = calloc((size_t) n, sizeof(int));
    if (a == NULL) {
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    return a;
}

static void build_heap(int k, int *a, int n) {
    for (int i = k; i >= 0; i--) {
        int j = i;
        while (2 * j + 1 < n) {
            int max = a[2 * j + 1];
            if ((2 * j + 2 < n) && (a[2 * j + 2] > a[j]) && (a[2 * j + 2] > a[2 * j + 1])) {
                max = a[2 * j + 2];
                a[2 * j + 2] = a[j];
                a[j] = max;
                j = 2 * j + 2;
            } else if (max > a[j]) {
                a[2 * j + 1] = a[j];
                a[j] = max;
                j = 2 * j + 1;
            } else break;
        }
    }
}

static void heap_sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int buf;
        buf = a[0];
        a[0] = a[n - i - 1];
        a[n - i - 1] = buf;
        int j = 0;
        while (2 * j + 1 < n - i - 1) {
            int max = a[2 * j + 1];
            if ((2 * j + 2 < n - i - 1) && (a[2 * j + 2] > a[j]) && (a[2 * j + 2] > a[2 * j + 1])) {
                max = a[2 * j + 2];
                a[2 * j + 2] = a[j];
                a[j] = max;
                j = 2 * j + 2;
            } else if (max > a[j]) {
                a[2 * j + 1] = a[j];
                a[j] = max;
                j = 2 * j + 1;
            } else break;
        }
    }
}

static void print_arr(const int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = memory_allacation(n);
    int k = n / 2 - 1;
    for (int j = 0; j < n; j++) {
        scanf("%d", &a[j]);
    }
    build_heap(k, a, n);
    heap_sort(a, n);
    print_arr(a, n);
    free(a);
}
