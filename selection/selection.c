#include <stdio.h>
#include <assert.h>

int stat(int* arr, int len, int ord) { // ord is 0-based
	if (len == 1) {
		assert(ord==0);
		return *arr;
	} else if (len == 0) {
		assert(0);
	}
	int p = rand() % len, i = 1, j = 0;
	int pivot = arr[p];
	arr[p] = arr[0];
	for (i=1; i<len; i++) {
		if (arr[i] < pivot) {
			j++;
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
	}
	arr[0] = arr[j];
	arr[j] = pivot;
	if (ord < j) return stat(arr,j,ord);
	else return stat(arr+j,len-j,ord-j);
}


int main() {
	int i = 0;
	for (i=0; i<10; i++) {
		int arr[10] = {5,4,3, 2,1,8, 9,7,6,0};
		printf("%d : %d\n",i,stat(arr,10,i));
	}
}
