#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

void swapElements(int *x, int a, int b) {
	int tmp = *(x + a);
	*(x + a) = *(x + b);
	*(x + b) = tmp;
}


int main() {
	int n, *x, *p, i, j, maxLoc, idx;

	scanf("%d", &n);
	x = (int *)malloc(sizeof(int *)*n);
	for (p = x; p < x + n; p++)
		scanf("%d", p);
	
	for (i = 0; i < n - 1; i++) {
		maxLoc = n - i - 1;
		for (j = 0; j < maxLoc; j++) {
			if (*(x + maxLoc) < *(x + j))
				maxLoc = j;
		}
		swapElements(x, maxLoc, n-i-1);
	}

	for (p = x; p < x + n; p++)
		printf(" %d", *p);

	return 0;
}

