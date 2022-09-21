#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct Heap {
	int H[100], n;
	// n은 last index값
}Heap;
Heap _Heap;

void swapElements(int a, int b) {
	int tmp = _Heap.H[a];
	_Heap.H[a] = _Heap.H[b];
	_Heap.H[b] = tmp;
}
void upHeap(int i) {
	if (i == 1)
		return 0; // root일 경우 종료
	if (_Heap.H[i] <= _Heap.H[i / 2])
		return 0; // parent의 key값이 더 큰경우 종료

	swapElements(i, i / 2);
	upHeap(i / 2);
}
void insertItem(int key) {
	_Heap.n += 1;
	_Heap.H[_Heap.n] = key;

	// upHeap
	upHeap(_Heap.n); // n == last 의 index
}
void downHeap(int i) {
	int bigger, left, right;
	left = 2 * i;
	right = 2 * i + 1;

	if (left > _Heap.n) {
		return 0;
	} // left가 last index보다 크면 항상 외부노드.

	bigger = left;
	if (right <= _Heap.n) {
		if (_Heap.H[right] > _Heap.H[bigger])
			bigger = right;
	} // 자식노드 left or right 누가 더 큰지 확인
	if (_Heap.H[bigger] <= _Heap.H[i])
		return 0;
	// 자식(bigger)이 부모(i)보다 작으면 스왑해줄 필요없음

	// else swap
	swapElements(i, bigger);
	downHeap(bigger); // 재귀로 끝날때까지 계속
}
int removeMax() {
	int key = _Heap.H[1]; // key(root)
	_Heap.H[1] = _Heap.H[_Heap.n]; // root에 마지막 key값 할당
	_Heap.H[_Heap.n] = 0; // 0으로 초기화
	_Heap.n--; // retreatLast

	//downHeap
	downHeap(1);

	return key;
}
void printHeap() {
	int i;
	for (i = 1; i <= _Heap.n; i++)
		printf(" %d", _Heap.H[i]);
	printf("\n");
}

int main() {
	int key;
	char ch;
	_Heap.n = 0;

	scanf("%c", &ch);
	getchar();
	while (ch != 'q') {
		switch (ch) {
		case'i':
			scanf("%d", &key);
			insertItem(key);
			printf("0\n");
			break;

		case 'd':
			printf("%d\n", removeMax());
			break;
		case 'p':
			printHeap();
			break;
		default:
			break;
		}

		getchar(); // 엔터먹히는거 방지
		scanf("%c", &ch);
	}

	return 0;
}

