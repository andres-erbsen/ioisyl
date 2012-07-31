#include <stdio.h>
#include <malloc.h>
#include <string.h>

printarr(int* arr, int len) {
	int i = 0;
	printf("[");
	for (i; i<len-1; i++) printf("%d, ",arr[i]);
	printf("%d]\n",arr[len-1]);
}

void mergesort(int* arr, int len) {
	if (len < 2) return;
	int* mid = arr + len/2;
	int* end = arr + len;
	int llen = mid - arr;
	int rlen = end - mid;
	mergesort(arr,llen);
	mergesort(mid,rlen);
	// move the left sorted subarray to temporary memory
	int* tmp = malloc( llen * sizeof(int) );
	memcpy(tmp, arr,   llen * sizeof(int) );
	int* tmpend = tmp + llen;
	int* l = tmp;
	int* r = mid;
	// merge arrays mid..end and tmp..tmpend to arr..end
	// using pointers  r,           l,            arr
	while (l < tmpend && r < end) {
		if (*l < *r) {
			*arr = *l;
			l++;
		} else {
			*arr = *r;
			r++;
		}
		arr++;
	}
	// copy the leftovers, on whichever side they are (one of the len is 0)
	memcpy(arr, l, (tmpend - l) * sizeof(int) );
	memcpy(arr, r, (end    - r) * sizeof(int) );
	free(tmp);
}

int main() {
	int i = 0;
	for (i=0; i<10; i++) {
		int arr[10] = {5,4,3, 2,1,8, 9,7,6,0};
		mergesort(arr,i+1);
		printarr(arr,i+1);
	}
}
