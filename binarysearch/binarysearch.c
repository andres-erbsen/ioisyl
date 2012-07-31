#include <stdio.h>

int bsearch(int* arr, int len, int target) {
	// lower bound if element not present
	int* left = arr;
	int* right = arr + len -1;
	while (left < right) {
		int* mid = left + (right - left) / 2;
		if (*mid < target) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left - arr;
}

int main() {
	int i = 0;
	int arr[10] = {0,12,23, 34,54,59, 62,73,74,99};
	for (i=0; i<10; i++) {
		printf("%d : %d\n",i*9,bsearch(arr,10,i*9));
	}
}
