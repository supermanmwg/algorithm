//============================================================================
// Name        : testZuma.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <malloc.h>


enum Dir {
	SINGLE, RIGHT, LEFT
};
typedef struct _List{
	char elem;
	int size;
	struct _List *next;
	struct _List *prev;
} List;

void ChangeList(List *list, int index, char ch);

int main(void) {
#ifndef _OJ_
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	char ch;

	List *Head = (List *)malloc(sizeof(List));
	Head->next = Head->prev = NULL;
	Head->elem = '2';
	Head->size = 0;
	List *Prev = Head;
	while (1) {
		scanf("%c",&ch);
		if(ch == '\n') break;
		//初始化节点
		List *listElem = (List *)malloc(sizeof(List));
		listElem->elem = ch;
		listElem->next = NULL;
		listElem->size =1;

		//判断两个元素是否相等
		if(listElem->elem == Prev->elem) {
			listElem->size++;
			Prev->size++;
		}
		//更改指针
		Prev->next = listElem;
		listElem->prev = Prev;
		Prev = listElem;

	}

	int num = 0;
	int index;
	scanf("%d",&num);

	for(int i = 0; i < num; i++) {
		scanf("%d %c",&index,&ch);
		ChangeList(Head,index,ch);

		List *testL = Head->next;
		if(testL == NULL) printf("-");
		while(testL != NULL) {
			printf("%c",testL->elem);
			testL = testL->next;
		}
		printf("\n");
		fflush(stdout);
	}

	fflush(stdout);
}


void ChangePoint(List *a,List *b) {
	if(b != NULL) {
		a->next = b;
		b->prev = a;
	} else {
		a->next = NULL;
	}
}
void deletePoint(List *a,List *b,List *c) {
	free(a);
	free(b);
	free(c);
}

void ChangeMethod(List *l) {
	List *next = l->next;
	if(next == NULL) return;
	if(l->elem != next->elem) {
		return;
	} else {
		List *Prev,*Next;
		if(l->size == 2){
			Prev=l->prev->prev;
			free(l->prev);
			free(l);
			if(next->size == 1) {
				Next = next->next;
				free(next);
			}
		}
		if(next->size == 2) {
			Next = next->next->next;
			free(next->next);
			free(next);
			if(l->size == 1) {
				Prev = l->prev;
				free(l);
			}
		}

		if(l->size == 1 && next->size == 1) {

			l->size++;
			next->size++;

			return;
		} else {
				ChangePoint(Prev,Next);
				ChangeMethod(Prev);
		}

	}
}
void ChangeList(List *list, int index, char ch) {
	int i =0;
	List *listElem = (List *)malloc(sizeof(List));
	listElem->elem = ch;
	listElem->next = NULL;
	listElem->size =1;

	List *prev = list;
	for(i=0;i<index;i++) {
		prev = prev->next;
	}
	listElem->next = prev->next;
	if(prev->next != NULL)
		prev->next->prev = listElem;
	prev->next = listElem;
	listElem->prev = prev;
	List *elemNext = listElem->next;
	List *method;
	if(elemNext != NULL) {
		if(listElem->elem != prev->elem && listElem->elem !=elemNext->elem ) {
			return;
		}

		if(listElem->elem == prev->elem && listElem->elem ==elemNext->elem ) {
			ChangePoint(prev->prev,elemNext->next);
			method = prev->prev;
			deletePoint(prev,elemNext,listElem);
			ChangeMethod(method);
			return;
		}

		if(listElem->elem == elemNext->elem && elemNext->size == 1 ) {
			listElem->size++;
			elemNext->size++;
			return;
		}
		if(listElem->elem ==elemNext->elem && elemNext->size == 2 ) {
			ChangePoint(prev,elemNext->next->next);
			method = prev;
			ChangeMethod(method);
			return;
		}
	}

	if(listElem->elem == prev->elem && prev->size==2 ) {
		ChangePoint(prev->prev->prev,listElem->next);
		method = prev->prev->prev;
		deletePoint(prev->prev,prev,listElem);
		ChangeMethod(method);
		return;
	}
	if(listElem->elem == prev->elem && prev->size == 1 ) {
		listElem->size++;
		prev->size++;
		return;
	}



}
