#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

int main() {
	int n, *x, *p, i, j, tmp;

	scanf("%d", &n);
	x = (int *)malloc(sizeof(int *)*n);
	for (p = x; p < x + n; p++)
		scanf("%d", p);
	
	for (i = 1; i < n; i++) {
		// insertItem with order
		tmp = *(x + i);
		j = i - 1;
		while (j >= 0 && tmp <= *(x + j)) {
			*(x + j + 1) = *(x + j);
			j -= 1;
		}
		// swap j+1 <-> tmp
		*(x + j + 1) = tmp;
	}

	for (p = x; p < x + n; p++)
		printf(" %d", *p);

	return 0;
}

