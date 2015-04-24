#include <stdio.h> 
#include <malloc.h>


typedef enum operation{
	PUSH,
	POP,
	NO
} Operation;

void Print(Operation p);

int trainNum;
int stationCapacity;

int main() {
	int i,j;
	int currentHigh = 0, currentLow = 0;
	int opCount = 0;
	scanf("%d %d", &trainNum, &stationCapacity);
	
	int *trainArray;
	Operation *operation;
	operation = (Operation *)malloc(sizeof(Operation)*trainNum*2);
	trainArray = (int *)malloc(sizeof(int)*trainNum);
	
	for (i = 0; i < trainNum; i++) {
		scanf("%d", &trainArray[i]);
	}

	for( i = 0; i< trainNum; i++) printf("%d ",trainArray[i]);
	printf("\n");

	for (i = 0; i < trainNum; i++) {
		if(trainArray[i] > currentHigh){
			if(trainArray[i] - currentHigh > stationCapacity) {
				Print(NO);
				free(operation);
				free(trainArray);
				return 0;
			}
			for (j = 0; j < trainArray[i] - currentHigh; j++) {
				operation[opCount++] = PUSH;
				currentLow++;
				stationCapacity--;
			}
			operation[opCount++] = POP;
			currentLow--;
			stationCapacity++;
			currentHigh = trainArray[i];
		} else {
			if(trainArray[i] != currentLow) {
				Print(NO);
				free(operation);
				free(trainArray);
				return 0;
			} else {
				operation[opCount++] = POP;
				stationCapacity++;
				currentLow--;
			}
		}
	}

	opCount--;
	for (i=0; i < opCount; i++) {
		Print(operation[i]);
	}



	free(operation);
	free(trainArray);

	return 0;
}



void Print(Operation p) {
	switch (p) {
		case PUSH:
			printf("PUSH\n");
			break;
		case POP:
			printf("POP\n");
			break;
		case NO:
			printf("NO\n");
			break;
		default:
			break;
	}
}

