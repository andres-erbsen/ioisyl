#include <stdio.h>

#define INTLEN 100

void integer_add(char* target, char* add) { // a += b
	char carry = 0, i = 0;
	for (i=0; i<INTLEN; i++) {
		char t = carry + add[i] + target[i];
		target[i] = t % 10;
		carry = t / 10;
	}
}

void integer_multsmall(char* target, int mult) {
	int carry = 0, i = 0;
	for (i=0; i<INTLEN; i++) {
		int t = carry + target[i]*mult;
		target[i] = t % 10;
		carry = t / 10;
	}
}

void integer_mult(char* target, char* a, char* b) {
	char j = 0;
	for (j=0; j<INTLEN; j++) {
		char m = b[j];
		if (!m) continue;
		char carry = 0, i = 0;
		for (i=0; i<INTLEN; i++) {
			char t = carry + target[i+j] + a[i]*m;
			target[i+j] = t % 10;
			carry = t / 10;
		}
	}
}

void integer_print(char* a) {
	int i = INTLEN-1;
	while (i>= 0 && !a[i]) i--;
	while (i>= 0) {
		printf("%d",a[i]);
		i--;
	}
}

void integer_fromstring(char* target, char* str, int len) {
	int i = 0;
	for (i=0; i<len && i<INTLEN; i++) {
		target[i] = str[len -1 -i] - '0';
	}
}

char something[INTLEN];
char other[INTLEN];
char sthe[INTLEN];
char result[INTLEN];

int main() {
	integer_fromstring(something,"64",2);
	integer_fromstring(other,"150",3);
	integer_mult(result,something,other);
	integer_print(result); printf("\n");
	integer_fromstring(sthe,"31415",5);
	integer_print(sthe); printf("\n");
	integer_add(sthe,sthe);
	integer_print(sthe); printf("\n");
	integer_multsmall(sthe,10);
	integer_print(sthe); printf("\n");
	integer_multsmall(sthe,3);
	integer_print(sthe); printf("\n");
}

