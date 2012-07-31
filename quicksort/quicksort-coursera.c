#include <stdio.h>

printarr(int* arr, int len) {
	int i = 0;
	printf("[");
	for (i; i<len-1; i++) printf("%d, ",arr[i]);
	printf("%d]\n",arr[len-1]);
}

int quicksort(int* arr, int len) {
	if (len < 2) return;
	int p = rand() % len, i=1, j=0;
	int pivot = arr[p];
	arr [p] = arr[0];
	for (i=1; i<len; i++) {
		if (arr[i] < pivot) {
			j++;
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	arr[0] = arr[j];
	arr[j] = pivot;
	quicksort(arr,j);
	quicksort(arr+j+1,len - (j+1));
}

int arr[10] = {5,4,3, 2,1,8, 9,7,6,0};
int main() {
	quicksort(arr,10);
	printarr(arr,10);
}

