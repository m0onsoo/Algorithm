#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct index {
	int a, b;
}index;
int findPivot(int *x, int l, int r);
void swapElements(int *x, int a, int b);
index inPlacePartion(int *x, int l, int r, int k);
void inPlaceQucikSort(int *x, int l, int r);

int main() {
	int *x, n, i;

	scanf("%d", &n);
	x = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", x + i); // (1) 배열 동적할당받고 배열 저장.

	inPlaceQucikSort(x, 0, n - 1);

	for (i = 0; i < n; i++)
		printf(" %d", *(x + i));

	return 0;
}

int findPivot(int *x, int l, int r) {
	srand(time(NULL));
	return l + rand() % (r - l + 1); // l ~ r 사이의 값 리턴
}
void swapElements(int *x, int a, int b) {
	int tmp = *(x + a);
	*(x + a) = *(x + b);
	*(x + b) = tmp;
}
index inPlacePartion(int *x, int l, int r, int k) {
	index p_idx;
	int i, j, pivot = x[k], cnt=0;
	i = l;
	j = r - 1;
	swapElements(x, k, r); // hide pivot

	while (i <= j) 
	{
		while (i <= j && x[i] <= pivot) 
			i++;
		while (j >= i && x[j] >= pivot)
			j--;
		// x[i] > pivot & x[j] < pivot. i 전은 다 pivot보다 작고 j 이후는 pivot보다 큼.
		if (i < j)
			swapElements(x, i, j); // LT와 GT로 분리
	}
	swapElements(x, i, r);

	// 앞뒤로 같은 경우 체크가 필요하지 않을까??
	while (x[i + cnt] == pivot)
		cnt--;
	p_idx.a = i + cnt + 1;
	cnt = 0;
	while (x[p_idx.a + cnt] == pivot)
		cnt++;
	p_idx.b = p_idx.a + cnt-1; // a <= EQ <= b

	return p_idx;
}
void inPlaceQucikSort(int *x, int l, int r) {
	int k, i;
	index p_idx;
	
	if (l >= r)
		return;
	k = findPivot(x, l, r);
	p_idx = inPlacePartion(x, l, r, k); // pivot 기준 좌우 정렬

	
	/* PROCESS
	printf("pivot = %d a = %d b = %d\n", x[k], p_idx.a, p_idx.b); 
	for (i = l; i <= r; i++)
		printf(" %d", *(x + i));
	printf("\n");*/

	inPlaceQucikSort(x, l, p_idx.a-1);
	inPlaceQucikSort(x, p_idx.b+1, r);
}
