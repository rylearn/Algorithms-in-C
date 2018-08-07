
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void print_int_array(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// returns bool if number in array
int contains(int num, int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == num) {
			return 1;
		}
	}
	return 0;
}

int* get_random_subset(int *arr, int n, int m) {
	srand(time(NULL));
	int index;
	int indices_len = 0;
	int *subset_array = malloc(m * sizeof(int));
	int *indices = malloc(m * sizeof(int));
	while (indices_len < m) {
		index = rand() % n;
		if (!contains(index, indices, indices_len)) {
			subset_array[indices_len] = arr[index];
			indices_len += 1;
		}
	}
	free(indices);
	return subset_array;
}

int main() {
	int m;
	int n;
	int *arr;

	printf("Enter size of array: ");
	scanf("%d", &n);

	arr = malloc(sizeof(int) * n);

	printf("Enter array: ");
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	
	printf("Enter size of subset: ");
	scanf("%d", &m);

	int *subset = get_random_subset(arr, n, m);
	
	print_int_array(arr, n);
	free(arr);
	
	print_int_array(subset, m);
	free(subset);

	return 0;
}
