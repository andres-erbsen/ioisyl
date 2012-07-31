#include <stdio.h>

printarr(int* arr, int len) {
	int i = 0;
	printf("[");
	for (i; i<len-1; i++) printf("%d, ",arr[i]);
	printf("%d]\n",arr[len-1]);
}

void quicksort(int* arr, int len) {
	if (len < 2) return;
	// pick a random pivot, move it to [0]
	int p = rand() % len;
	int pivot = arr[p];
	arr[p] = arr[0];
	arr[0] = pivot;
	int* left  = arr+1;
	int* right = arr+len-1;
	while (left < right) {
		if (*left > pivot) {
			while (left < right && *right > pivot) right--;
			int t = *left;
			*left = *right;
			*right = t;
			right--;
		}
		left++;
	}
	int t = *(left-1);
	*(left-1) = pivot;
	*arr = t;
	quicksort(arr, left-arr);
	quicksort(left,(arr+len)-left);
}

int arr[10] = {5,4,3, 2,1,8, 9,7,6,0};
int main() {
	quicksort(arr,10);
	printarr(arr,10);
}
