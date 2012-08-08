#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#define MAXH 15 // ceil(log(EXPECTED MAXIMUM NUMBER OF ITEMS))

typedef struct sl_node {
	int cargo;
	struct sl_node* fwd[MAXH+1]; // 0 is the lowest and MAXH the gighest level
} sl_node;

char chooseheight() {
	// add one to num. and denom. to avoid log(0). TODO: is this neccessary?
	float x = ( (float) rand()+1 ) / ( (float) RAND_MAX+1 );
	int got = - ( (int) log(x) ); // p=e^-1 => log_p(x) = -log(x)
	return (got < MAXH) ? got : MAXH; // limit to some reasonable maximum
}

void sl_insert(sl_node** fwd, int cargo) {
	char h = chooseheight(), i=0;
	sl_node* newnode = calloc(sizeof(sl_node),1);
	newnode->cargo = cargo;
	for (i=MAXH; i>h; i--) { // the usual skiplist traversal
		while (fwd[i] != NULL && fwd[i]->cargo < cargo) fwd = fwd[i]->fwd;
	}
	for (i=h;   i>=0; i--) { // also add pointers to the new node
		while (fwd[i] != NULL && fwd[i]->cargo < cargo) fwd = fwd[i]->fwd;
		newnode->fwd[i] = fwd[i];
		fwd[i] = newnode;
	}
}

void sl_delete(sl_node** fwd, int target) { // delete /first/ node with cargo @target
	char i = MAXH;
	sl_node** linksto[MAXH+1]; // links that point to /some/ node with cargo @target
	for (i=MAXH; i>=0; i--) {
		while (fwd[i] != NULL && fwd[i]->cargo < target) fwd = fwd[i]->fwd;
		if (fwd[i] != NULL && fwd[i]->cargo == target) linksto[i] = &fwd[i];
	}
	if (fwd[0]->cargo == target) { // is there a node with value @target?
		sl_node* del = fwd[0]; // node to be deleted
		fwd = del->fwd;
		for (i=0; i<=MAXH && fwd[i] != NULL; i++) *linksto[i] = fwd[i];
		free(del);
	}
}

int sl_find(sl_node** fwd, int target) { // finds largest x <= target
	int val = -1; char i = MAXH;
	for (i=MAXH; i>=0; i--) {
		while (fwd[i] != NULL && fwd[i]->cargo <= target) {
			val = fwd[i]->cargo;
			fwd = fwd[i]->fwd;
		}
	}
	return val;
}

sl_node* sl[MAXH+1]; // header of a skiplist.
main () {
	sl_insert(sl,10);
	sl_insert(sl,15);
	sl_insert(sl,20);
	sl_insert(sl,5);
	sl_insert(sl,123456789);
	int i = 0;
	for (i=0; i<25; i++) printf("%d : %d\n",i,sl_find(sl,i));
	sl_delete(sl,10); printf("Deleted 10\n");
	for (i=0; i<25; i++) printf("%d : %d\n",i,sl_find(sl,i));
	sl_delete(sl,20); printf("Deleted 20\n");
	for (i=0; i<25; i++) printf("%d : %d\n",i,sl_find(sl,i));
	sl_delete(sl,5); printf("Deleted 5\n");
	for (i=0; i<25; i++) printf("%d : %d\n",i,sl_find(sl,i));
	sl_delete(sl,15); printf("Deleted 15\n");
	for (i=0; i<25; i++) printf("%d : %d\n",i,sl_find(sl,i));
	i = 223456789;
	printf("%d : %d\n",i,sl_find(sl,i));
}
