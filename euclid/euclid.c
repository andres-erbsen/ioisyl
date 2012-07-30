#include <stdio.h>

struct Euc {
	int x, y, gcd;
};

struct Euc euclid(int dprev, int d) {
	int x=0, xprev=1, y=1, yprev=0;
	while (dprev % d) {
		int q = dprev / d;
		int r = dprev % d;
		int xnew = xprev - q*x;
		int ynew = yprev - q*y;
		xprev = x; x = xnew;
		yprev = y; y = ynew;
		dprev = d; d = r;
	}
	struct Euc ret;
	ret.x = x;
	ret.y = y;
	ret.gcd = d;
	return ret;
}

int main () {
	int a=0, b=0;
	scanf("%d %d",&a,&b);
	struct Euc r = euclid(a,b);
	printf("%d*%d + %d*%d == %d\n",r.x,a,r.y,b,r.gcd);
	return 0;
}
