#define arr_len 50

#include <stdio.h>

void shift_element(int* arr, int i) {
	int j;
	for (j = i; j > 0; j--) {
		*(arr + j) = *(arr + j - 1);
	}
}

void insertion_sort(int* arr, int len) {
	int i , j , tmp;
	for (i = 0; i < len; i++) {
		j = 0;
		while (*(arr + j) < *(arr + i)) { j++; }
		tmp = *(arr + i);
		shift_element(arr + j, i - j);
		*(arr + j) = tmp;
	}
}

int main() {
	int arr[arr_len];
	
	int i;
	for (i = 0; i < arr_len; i++) {
		scanf("%d", (arr + i));
	}

	insertion_sort(arr, arr_len);

	for (i = 0; i < arr_len -  1; i++) {
		printf("%d,", *(arr + i));
	}
	printf("%d", *(arr + arr_len - 1));

	return 0;
}