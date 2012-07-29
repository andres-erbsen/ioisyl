#include <stdio.h>

int N=0, M=0;
char fromdigits[10000];
char todigits_rev[10000];

int main () {
	int i=0;
	int c=0, frombase=0, tobase=0;
	scanf("%d %d",&frombase,&tobase);
	while(scanf("%c",&c) == 1) {
		if (c >= '0' && c <= '9') {
			fromdigits[N] = c - '0';
			N++;
		}
	}
	__int128 value = 0, weight = 1, fb = frombase;
	for (i=N-1; i>=0; i--) {
		value  += weight * fromdigits[i];
		weight *= fb;
	}
	while (value > 0) {
		todigits_rev[M] = value % tobase;
		value /= tobase;
		M++;
	}
	for (i=M-1; i>=0; i--) {
		printf("%d",todigits_rev[i]);
	} printf("\n");
}
