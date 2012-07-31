#include <stdio.h>

int ipow(int a, int x) {
	int ret = 1;
	while (x) {
		if (x & 1) ret *= a;
		x >>= 1;
		a *= a;
	}
	return ret;
}

int main() {
	printf("2^3 = %d\n",ipow(2,3));
	printf("2^8 = %d\n",ipow(2,8));
	printf("3^6 = %d\n",ipow(3,6));
	return 0;
}
