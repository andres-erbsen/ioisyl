#include <stdio.h>
#include <limits.h>

printarr(int* arr, int len) {
	int i = 0;
	printf("[");
	for (i; i<len-1; i++) printf("%d, ",arr[i]);
	printf("%d]\n",arr[len-1]);
}

void heapsort(int* arr, int len) {
	// Binary min-heap using 0-based indexes.
	// parent: (n-1)/2; children: 2*n+1 and 2*n+2
	int i = 1;
	for (i=1; i<len; i++) {
		int n = i;
		int p = (n-1)/2;
		int node = arr[n];
		int parent = arr[p];
		while (node < parent) { // if n == p == 0 then node == parent
			// swap them
			arr[p] = node;
			arr[n] = parent;
			// move up to the parent, check it too
			n = p;
			p = (n-1)/2; // n=0 -> p = (-1)/2 = 0.
			node = arr[n];
			parent = arr[p];
		}
	}
	for (i=1; i<len; i++) {
		int n = i, node = arr[n];
		// the first i places in array are already sorted and not heapy
		int l = 2*(n-i)+1 +i;
		int r = 2*(n-i)+2 +i;
		int child_l = (l < len) ? arr[l] : INT_MAX;
		int child_r = (r < len) ? arr[r] : INT_MAX;
		while (node > child_l || node > child_r) {
			// if node < one of its children, swap with the lesser
			int child = 0; int c = 0;
			if (child_l < child_r) {
				child = child_l;
				c = l;
			} else {
				child = child_r;
				c = r;
			}
			arr[n] = child;
			arr[c] = node;
			// and check the just-demoted child too using the same loop
			n = c;
			node = child;
			l = 2*(n-i)+1 +i;
			r = 2*(n-i)+2 +i;
			child_l = (l < len) ? arr[l] : INT_MAX;
			child_r = (r < len) ? arr[r] : INT_MAX;
		}

	}
}

int main() {
	int i = 0;
	for (i=0; i<10; i++) {
		int arr[10] = {5,4,3, 2,1,8, 9,7,6,0};
		heapsort(arr,i+1);
		printarr(arr,i+1);
	}
}

