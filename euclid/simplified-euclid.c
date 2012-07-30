#include <stdio.h>

int gcd(int a, int b) {
	int t;
	if (b > a) {
		t = b;
		b = a;
		a = t;
	}
	while (b > 0) {
		t = b;
		b = a % b;
		a = t;
	}
}

int main() {
	printf("gcd(9,12) = %d\n",gcd(9,12));
	printf("gcd(1024,72) = %d\n",gcd(1024,72));
	printf("gcd(7,12) = %d\n",gcd(7,12));
}
