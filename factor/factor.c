#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	int n = 0;
	sscanf(argv[1],"%d",&n);
	printf("%d:",n);
	while (n % 2 == 0) {
		printf(" 2");
		n /= 2;
	}
	while (n % 3 == 0) {
		printf(" 3");
		n /= 3;
	}
	int i=5, middle = sqrt(n) + 1 + 0.5; // +1 because 6*i-1 is used
	// printf("%d %f\n",middle,sqrt(n) + 0.5);
	while (i<=middle) { // all primes after 3 are 6*k (+-) 1
		while (n % i == 0) {
			printf(" %d",i);
			n /= i;
		}
		i += 2;
		while (n % i == 0) {
			printf(" %d",i);
			n /= i;
		}
		i += 4;
	}
	if (n != 1) printf(" %d",n);
	printf("\n");
	return 0;
}
