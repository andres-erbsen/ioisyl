#include <stdio.h>

printarr(int* arr, int len) {
	int i = 0;
	printf("[");
	for (i; i<len-1; i++) printf("%d, ",arr[i]);
	printf("%d]\n",arr[len-1]);
}

void quicksort(int* arr, int len) {
	// pick a random pivot, move it to [0]
	printf("go %d\n",len); printarr(arr,len);
	int p = rand() % len;
	int pivot = arr[p];
	arr[p] = arr[0];
	arr[0] = pivot;
	printf("pivot = arr[%d] = %d\n",p,pivot);
	// partition the array in-place
	int* left  = arr+1;
	int* right = arr+len-1;
	while (left < right) {
		printf("(left=%d, right=%d)\n",left-arr,right-arr);
		printarr(arr,len);
		if (*left > pivot) {
			// swap with a greater value
			while (left < right && *right > pivot) right--;
			int t = *left;
			*left = *right;
			*right = t;
			right--;
		}
		left++;
	}
	printf("finally (left=%d, right=%d)\n",left-arr,right-arr);
	printarr(arr,len);
	// move pivot into its place
	int t = *(left-1);
	*(left-1) = pivot;
	*arr = t;
	printarr(arr,len);
	// sort the ends, if any
	if ((left-arr) > 1) quicksort(arr, left-arr);
	if ((arr+len) - left > 1) quicksort(left,(arr+len)-left);
	printf("back: "); printarr(arr,len);
}

int arr[10] = {5,4,3, 2,1,8, 9,7,6,0};
int main() {
	quicksort(arr,10);
}
