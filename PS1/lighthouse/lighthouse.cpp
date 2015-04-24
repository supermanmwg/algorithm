#include <stdio.h>
#include <malloc.h>
#define _OJ_
void qsort(int *a, int *b, int l, int h);
void Merge(int *b, int l, int h) ;
long long sum =0;
int le[2000001];
int re[2000001];
int main(void) {
#ifndef _OJ_
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	long long  num=0;
	scanf("%lld",&num);
	int *a = (int *)malloc(sizeof(int)*(num+1));
	int *b = (int *)malloc(sizeof(int)*(num+1));
	for(int i=1; i<=num; i++) {
		scanf("%d %d",a+i,b+i);
	}
	qsort(a,b,1,num);
	Merge(b,1,num);
	free(a);
	free(b);
	printf("%lld",sum);
	//fflush(stdout);

	return 0;
}

void swaps(int *a,int i1,int i2) {
	int temp = a[i1];
	a[i1] = a[i2];
	a[i2] = temp;
}
void swap(int *a, int *b, int i1, int i2) {
	int temp = a[i1];
	a[i1] = a[i2];
	a[i2] = temp;
	temp = b[i1];
	b[i1] = b[i2];
	b[i2] = temp;
	
}
void qsort(int *a, int *b, int l, int h) {
	int i = l;
	int k = h;

	if(h - l >= 1) {
		int pivot = a[l];
		while(k > i ) {
			while(a[i] <=pivot && i <=h && k>i)
				i++;
			while(a[k]>pivot && k>=l && k>=i)
				k--;
			if(k>i) swap(a,b,i,k);
		}
		swap(a,b,l,k);

		qsort(a,b,l,k-1);
		qsort(a,b,k+1,h);
	} else {
		return;
	}
}

void MergeElem(int *b, int L, int mid ,int h) {
	int nl = mid - L + 1;
	int nr = h - mid;
	le[nl+1] = 1000000004;
	re[nr+1] = 1000000004;

	for(int i=1;i<= nl; i++) le[i]=b[L+i-1];
	for(int i=1;i<= nr; i++) re[i]=b[mid+i];

	 int s =L;
	 int n = 1;
	 int m = 1;
	 for(s=L;s<=h;s++) {
		if(le[m]<=re[n]) {
			b[s] = le[m++];
			sum += nr-n+1;
		} else {
			b[s] = re[n++];
		}
	}
}
void Merge(int *b, int L, int h) {
	if(L == h) return;
	int mid = L + ((h - L)>>1);
	Merge(b,L,mid);
	Merge(b,mid+1,h);
	MergeElem(b,L,mid,h);

}
