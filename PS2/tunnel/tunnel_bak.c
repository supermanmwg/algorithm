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
typedef struct stack {
	Element *p;
	int currentCount;
	int lowCount;
} Stack;

Stack mStack;
void Push(int num);
void Pop();

int operationNum;
int main() {

	int i;
	char operation;
	int height;
	scanf("%d", &operationNum);
	getchar();

	mStack.p =(Element *)malloc(sizeof(Element)*(operationNum+1));
	mStack.currentCount = 1;
	mStack.lowCount = 1;
	mStack.p[0].maxHeight = 0;

	for(i = 0; i <operationNum; i++) {
		DEBUG("i = %d\n", i);
		scanf("%c", &operation);
		DEBUG("operation = %c\n", operation);
		switch(operation) {
			case 'E' :
				do {
					scanf("%d",&height);
					DEBUG("height = %c\n",height);
				} while(height == ' ');
				Push(height);
				break;
			case 'D' :
				Pop();
				break;
			case 'M' :
				printf("%d\n",mStack.p[mStack.lowCount].maxHeight);
				break;
			default:
				 break;
		}
		getchar();
	}

	return 0;
}

void Push(int elem) {
	if(mStack.p[mStack.currentCount-1].maxHeight < elem)
		mStack.p[mStack.currentCount].maxHeight = elem;
	else 
		mStack.p[mStack.currentCount].maxHeight = mStack.p[mStack.currentCount-1].maxHeight;

	mStack.p[mStack.currentCount++].height = elem;
}

void Pop() {
	if(mStack.currentCount - mStack.lowCount >= 1) {
		printf("%d\n",mStack.p[mStack.lowCount++].height);
	}
}

