
#include <stdio.h> 
#include <malloc.h>
#define DEBUG_PRINT

#ifdef DEBUG_PRINT
#define  DEBUG(fmt,args ...) printf(fmt,##args)

#else
#define DEBUG(fmt,args ...)
#endif

typedef struct element {
	int height;
	int maxHeight;
} Element; 

typedef struct mstack {
	Element *p;
	int currentCount;
	int size;
} MStack;

typedef struct stack {
	int *p;
	int size;
} Stack;

Stack stack;
MStack mStack;
void mPush(int num);
void mPop();

void Push(int num);

void mTs();
void sTm();

int operationNum;

int main() {
	int i;
	char operation;
	int height;

	scanf("%d", &operationNum);
	getchar();

	stack.p = (int *)malloc(sizeof(int)*(operationNum + 1));
	mStack.p = (Element *)malloc(sizeof(Element)*(operationNum + 1));
	stack.size = 0;
	mStack.size = 0;
	mStack.currentCount = 1;
	mStack.p[0].maxHeight = 0;

	for (i = 0; i < operationNum; i++) {
		DEBUG("i = %d\n", i);
		scanf("%c", &operation);
		DEBUG("operation = %c\n", operation);
		switch(operation) {
			case 'E' :
				do {
					scanf("%d",&height);
					DEBUG("height = %c\n",height);
				} while(height == ' ');
				if(stack.size != 0)
					Push(height);
				else {
					if(mStack.size != 0)
						mTs();
					Push(height);
				}
				break;
			case 'D' :
				if(mStack.size != 0)
					mPop();
				else {
					if(stack.size != 0) {
						sTm();
						mPop();
					}
				}
				break;
			case 'M' :
				if(mStack.size != 0)
					printf("%d\n",mStack.p[mStack.currentCount].maxHeight);
				else {
					if(stack.size != 0) {
						sTm();
						printf("%d\n",mStack.p[mStack.currentCount].maxHeight);
					} else {
						printf("0\n");
					}

				}
				break;
			default:
				 break;
		}
		getchar();
	}

	return 0;
}


void mPush(int num) {

}
void mPop() {

}

void Push(int num){

}

void mTs() {

}
void sTm() {

}
