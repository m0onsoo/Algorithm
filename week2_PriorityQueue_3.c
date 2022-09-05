#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#pragma warning(disable:4996)

int *findMax(int *x, int last) {
	int *p, *max = x;
	for (p = x; p < x + last; p++)
		if (*p > *max)
			max = p;
	return max;
}

void swap_select(int *max, int *last) {
	int tmp = *max;
	*max = *last;
	*last = tmp;
}
void swap_insert(int *x, int i) {
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
	int n, *A, *B, *p, i, *max, x, cnt = 0;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	scanf("%d", &n);
	A = (int *)malloc(sizeof(int) * n);
	B = (int *)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		*(A + i) = *(B + i) = rand() % 101;
	} // 배열 생성
	printf("n = %d\n", n);

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 0; i < n - 1; i++) {
		max = findMax(A, n - cnt);
		swap_select(max, A + n - cnt - 1);
		cnt++;
	} // 선택정렬
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	for (i = 0; i < n - 1; i++) {
		swap_insert(B, i);
	} // 삽입정렬
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));



	return 0;

}

