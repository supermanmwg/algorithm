#include <stdio.h>
#include <malloc.h>
#define _OJ_
int outputNumL(int *a, int l,int h, int ln);
int outputNumH(int *a, int l, int h, int hn);
void bInsertSort(int *L,int watcher,int length);
void quickSort(int array[], int start, int end);
int main(void) {
	int sN,qN;
	int l,h;
	int lb,hb;

#ifndef _OJ_
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	sN =0;
	qN =0;
	scanf("%d %d",&sN,&qN);
	int *a = (int*)malloc(sizeof(int)*sN);
	int *b = (int*)malloc(sizeof(int)*sN);
	for(int i = 0; i < sN; i++){
		scanf("%d",&a[i]);
		//bInsertSort(a,a[i],i);
	}
	 quickSort(a,0, sN-1);

	for(int i = 0; i < qN; i++) {
		scanf("%d %d",&l,&h);
		lb=outputNumL(a,0,sN-1,l);
		hb=outputNumH(a,0,sN-1,h);
		printf("%d\n",hb-lb+1);
	//	fflush(stdout);
	}

	return 0;
}

int outputNumL(int *a, int l,int h, int ln) {
	int mid;
	// 1 5 8 10 90     7,11
	if(l < h){
		mid = (l+h)/2;
		if(a[mid] == ln) {
			return mid;
		} else if(a[mid] < ln) {
			return outputNumL(a,mid+1,h,ln);
		}else {
			return outputNumL(a,l,mid-1,ln);
		}
	}

	if(	l>=h ) {
		if(ln <= a[l] ) {
			return l;
		} else {
			return l+1;
		}

	}
}

int outputNumH(int *a, int l, int h, int hn) {
	int mid;

	if(l < h) {
		mid = (l+h)/2;
		if(a[mid] == hn) {
			return mid;
		} else if(a[mid] < hn) {
			return outputNumH(a,mid+1,h,hn);
		}else {
			return outputNumH(a,l,mid-1,hn);
		}
	}
	if(l>=h) {
		if(hn>=a[l]){
			return l;
		} else {
			return l-1;
		}
	}

}

void bInsertSort(int *L,int watcher,int length)
{
    int low =0;
    int high =length-1;
    int mid;

	if(L[high] <= watcher) {
		return;
	}
	// 1 2 3 4 7   5
	while(low <= high) {
		mid = (low+high)/2;
		if(L[mid] < watcher) {
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
    for(int j =length;j>high;j--)
    {
            L[j]=L[j-1];
    }
    L[high+1] =watcher;

}
void swap(int array[], int index1, int index2)

{
	int temp = array[index1];          
	array[index1] = array[index2];      
	array[index2] = temp;              
}

 void quickSort(int array[], int start, int end)
{
        int i = start;                         
        int k = end;                          

        if (end - start >= 1)                  
        {
                int pivot = array[start];       

                while (k > i)                 
                {
                        while (array[i] <= pivot && i <= end && k > i)  
                                i++;                                    
                        while (array[k] > pivot && k >= start && k >= i) 
                            k--;                                       
                        if (k > i)                                       
                                swap(array, i, k);                     
                }
                swap(array, start, k);         
                quickSort(array, start, k - 1); 
                quickSort(array, k + 1, end);  
        }
        else   
        {
                return;                  
        }
}


