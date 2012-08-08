#include <stdio.h>

int inversioncount(int* arr, int len) {
	if (len < 2) return 0;

}

int main() {
	{
		int arr[10] = {0,1,2,3,4,5,6,7,8,9};
		printf("%d\n",inversioncount(arr,10));
	}
	{
		int arr[10] = {9,8,7,6,5,4,3,2,1,0};
		printf("%d\n",inversioncount(arr,10));
	}
}
