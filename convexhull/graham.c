/* vim: set ts=4 sw=4 : */
#include <stdio.h>
#include <stdlib.h>
#define MAXN 5

typedef struct point {
	int x, y;
} point;

point points[MAXN]; /* first one is empty */
int N;

int ccw(point a, point b, point c) {
	int x1 = a.x - b.x;
	int x2 = a.x - c.x;
	int y1 = a.y - b.y;
	int y2 = a.y - c.y;
	return x1*y2 - x2*y1;
}

int pointCmpBy(point* neg, point* pos, point* ref) { /* ccw */
	int n_x = neg->x - ref->x;
	int n_y = neg->y - ref->y;
	int p_x = pos->x - ref->x;
	int p_y = pos->y - ref->y;
	float cot_n = n_x/(1e-7 + n_y);
	float cot_p = p_x/(1e-7 + p_y);
	if (cot_n < cot_p) return 1;
	return -1;
}

int main () {
	int a=0, b=0;
	while (scanf("%d %d",&a,&b) == 2) {
		points[N].x = a;
		points[N].y = b;
		N++;
	}
	int i = 0;
	point p = points[0]; /* reference point. Lowest, prefer left. */
	for (i=1; i<N; i++) {
		if (points[i].y <  p.y ||
			points[i].y == p.y && points[i].x < p.x ) {
			points[0] = points[i];
			points[i] = p;
			p = points[0];
		}
	}
	qsort_r(points+1, N-1, sizeof(point), &pointCmpBy, &p);
	int j=2;
	for (i=2; i<N; i++) {
		while ( j >= 2 && ccw(points[j-2],points[j-1],points[i]) < 0) j--;
		points[j] = points[i];
		j++;
	}
	for (i=0;i<j;i++) printf("%d\t%d\n",points[i].x,points[i].y);
	return 0;
}
