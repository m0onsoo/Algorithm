#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node *next;
}node;
typedef struct List {
	node *front;
}List;

node *getnode();
List *initList();
int size(List *L);
int isEmpty(List *L);
void addLast(List *L, int elem);
int removeFirst(List *L);
List *partition(List *L, int k);
List *merge(List *L1, List *L2);
void mergeSort(List *L);


int main() {
	int i, elem, n;
	List L;
	node *p;
	L.front = NULL; // init 필요

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		addLast(&L, elem);
	} // 단일연결리스트로 입력

	mergeSort(&L); // 합병정렬 실행

	p = L.front;
	while (p != NULL) {
		printf(" %d", p->elem);
		p = p->next;
	} // 정렬된 리스트 출력

	return 0;
}

node *getnode() {
	node *newnode = (node *)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->elem = NULL;
	return newnode;
}
List *initList() {
	List *L = (List *)malloc(sizeof(List));
	L->front = NULL;
	return L;
} 
int size(List *L) {
	int cnt = 0;
	node *p = L->front;
	while (p != NULL) {
		cnt++;
		p = p->next;
	}
	return cnt;
}
int isEmpty(List *L) {
	return L->front == NULL;
}
void addLast(List *L, int elem) {
	node *newnode = getnode(), *p = L->front;
	int i;
	newnode->elem = elem;
	if (isEmpty(L)) {
		L->front = newnode;
	} // 초기에 데이터 입력
	else {
		for (i = 0; i < size(L) - 1; i++)
			p = p->next;
		p->next = newnode;
	} // 널 직전까지 간다음 next에 새로운 노드 삽입

}
int removeFirst(List *L) {
	node *p = L->front;
	int elem = p->elem;

	L->front = p->next;
	free(p);
	// front 원소를 리턴값 저장해주고 front 한칸 당겨주고 메모리 반환.
	return elem;
}
List *partition(List *L, int k) {
	List *L2 = initList();
	node *p = L->front;
	int i;

	for (i = 1; i < k; i++)
		p = p->next; // L1 마지막까지
	L2->front = p->next; // L2로 분할 
	p->next = NULL; // L1 다음 널로 끊어줌

	return L2;
}
List *merge(List *L1, List *L2) {
	List *result = initList();

	while (!isEmpty(L1) && !isEmpty(L2))
	{
		if (L1->front->elem < L2->front->elem)
			addLast(result, removeFirst(L1));
		else
			addLast(result, removeFirst(L2));
	}
	while (!isEmpty(L1))
		addLast(result, removeFirst(L1));
	while (!isEmpty(L2))
		addLast(result, removeFirst(L2));

	return result->front;
}
void mergeSort(List *L) {
	List *L2;
	int k = size(L) / 2;

	if (size(L) > 1)
	{
		L2 = partition(L, k);
		mergeSort(L);
		mergeSort(L2);
		L->front = merge(L, L2);
		// 그냥 List로 반환했을 때 함수가 끝나면 저장이 안되서 구조체 front안에 저장시킴
	}

}
