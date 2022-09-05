#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

int *findMax(int *x, int last) {
	int *p, *max = x;
	for (p = x; p < x + last; p++)
		if (*p > *max)
			max = p;
	return max;
}

void swap(int *max, int *last) {
	int tmp = *max;
	*max = *last;
	*last = tmp;
}

int main() {
	int n, *x, *p, *max, cnt=0, i;

	scanf("%d", &n);
	x = (int *)malloc(sizeof(int) * n);

	for (p = x; p < x + n; p++)
		scanf("%d", p);

	for (i = 0; i < n; i++) {
		max = findMax(x, n - cnt);
		swap(max, x + n - cnt - 1);
		cnt++;
	}
	for (p = x; p < x + n; p++)
		printf("%d ", *p);

	return 0;

}

