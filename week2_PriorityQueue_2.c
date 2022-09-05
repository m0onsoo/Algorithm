#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

void swap(int *x, int i) {
	int *p, *want = (x + i + 1), tmp;

	for (p = x + i; p >= x; p--) {
		if (*want < *p) {
			tmp = *want;
			*want = *p;
			*p = tmp;
			want = p;
		}
	}
}

int main() {
	int n, *x, *p, *max, cnt=0, i;

	scanf("%d", &n);
	x = (int *)malloc(sizeof(int) * n);

	for (p = x; p < x + n; p++)
		scanf("%d", p);

	for (i = 0; i < n-1; i++) {
		swap(x, i);
	}
	for (p = x; p < x + n; p++)
		printf("%d ", *p);

	return 0;

}

