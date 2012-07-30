#include <stdio.h>

#define MAXN (500000)
#define MAXP (7368787)
// 500000th prime

int primes[MAXN] = {2,3};
char iscomposite[MAXP] = {1,1,0,0,1,0};
int m, n; // limits of search

void sieve(int i) {
	int j = 0;
	if (!iscomposite[i]) {
		if (i >= m) {
			printf("%d\n",i);
		}
		for (j=i*i; j<=n; j+=i) {
			iscomposite[j] = 1;
		}
	}
}

int main(int argc, char** argv) {
	sscanf(argv[1],"%d",&m);
	sscanf(argv[2],"%d",&n);
	if (m <= 2 && 2 <= n) printf("2\n");
	if (m <= 3 && 3 <= n) printf("3\n");
	int n_=n-2, i = 5; 	// all primes after 3 are 6*k (+-) 1
	while (i <= n_) {
		sieve(i);
		i += 2;
		sieve(i);
		i += 4;
	}
	if (i <= n) sieve(i);
	return 0;
}
