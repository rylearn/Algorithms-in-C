
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void print_int(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// returns bool if number in array
int isIn(int num, int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == num) {
			return 1;
		}
	}
	return 0;
}

int* generate_random_from_array(int *arr, int n, int m) {
	srand(time(NULL));
	int *indices = malloc(m * sizeof(int));
	int *ret_arr = malloc(m * sizeof(int));
	int index;
	int indices_len = 0;
	while (indices_len < m) {
		index = rand() % n;
		if (!isIn(index, indices, indices_len)) {
			indices[indices_len] = index;
			ret_arr[indices_len] = arr[index];
			indices_len += 1;
		}
	}
	return ret_arr;
}

int main() {
	int arr[] = {1, 4, 2, 8, 19};
	print_int(gen_random(arr, 5, 2), 2);
	return 0;
}
