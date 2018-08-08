#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_func(const char* a, const char* b) {
    return strcmp(a, b);
}

void swap(char **arr, int i, int j) {
    char *temp = arr[i];
    arr[i] = strdup(arr[j]);
    free(arr[j]);
    arr[j] = strdup(temp);
}

int partition(char **arr, int p, int r, 
    int (*cmp_func)(const char *a, const char *b)) {
    char* pivot = strdup(arr[r]);
    int i = p - 1;
    for (int j = p; j <= r - 1; ++j) {
        if (cmp_func(arr[j], pivot) <= 0) {
            i += 1;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    free(pivot);
    return i + 1;
}

void quicksort(char **arr, const int len, size_t sz, 
    int (*cmp_func)(const char *a, const char *b)) {
    if (len <= 1)
        return;
    int p = 0;
    int r = len - 1;
    int q = partition(arr, p, r, cmp_func);
    int len_lower = q;
    int len_upper = len - len_lower;
    char **arr_first_half = arr;
    char **arr_second_half = arr + len_lower;
    quicksort(arr_first_half, len_lower, sz, cmp_func);
    quicksort(arr_second_half, len_upper, sz, cmp_func);   
}

int main() {
    
    int n; 
    #define MAX_STR_SIZE 25
    printf("Enter number of strings to sort: ");
    scanf("%d", &n);

    char* arr[n]; 
    for (int i = 0; i < n; ++i) {
        char str[MAX_STR_SIZE];
        scanf("%s", str);
        arr[i] = strdup(str);
    }

    quicksort(arr, n, sizeof(char*), cmp_func);

    for (int i = 0; i < n; ++i) {
        printf("%s\n", arr[i]);
    }

    for (int i= 0; i < n; ++i) {
        free(arr[i]);
    }

    return 0;
}
