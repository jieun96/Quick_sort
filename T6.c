#include <stdio.h>
#include <time.h>
void quicksort(int,int,int*);
void partition(int, int, int*,int*);
void swap(int*,int*);
int main(){
	int a[3001],n[24];
	int i,j,k;
	long b;
	const long r[24] = {300000,300000,200000,200000,100000,100000,100000,80000,80000,50000,50000,25000,15000,15000,10000,7500,7000,6000,5000,5000,3000,2000,2000,1000};
	for(i=1;i<=3000;i++)
		a[i] = 3001-i;
	for(j=0;j<10;j++){
		n[j] = 10*j;
		n[j+10] = 100*(j+1);
	}
	n[20] = 1500;
	n[21] = 2000;
	n[22] = 2500;
	n[23] = 3000;

	printf("    n   totlaTime     runTime\n");
	for(int k=0;k<24;k++){
		clock_t start, stop;
		start = clock();
		for(b = 1;b<r[k];b++)
			quicksort(0,n[k]-1,a+1);
		stop = clock();
		clock_t totalTime = stop-start;
		double runTime = (double)totalTime/(double)(r[k]);
		printf(" %4d %11d %11lf\n",n[k],totalTime,runTime);
	}
	return 0;
}
void quicksort(int low, int high, int s[]){
	int pivotpoint,i;
	if(high>low){
		partition(low,high,&pivotpoint,s);
		quicksort(low,pivotpoint-1,s);
		quicksort(pivotpoint+1,high,s);
	}
}
void partition(int low, int high, int * pivotpoint,int s[]){
	int i,j;
	int pivotitem;
	pivotitem = s[low];
	j = low;
	for(i=low+1;i<=high;i++){
		if(s[i]<pivotitem){
			j++;
			swap(&s[i],&s[j]);
		}
	}
	*pivotpoint = j;
	swap(&s[low],&s[*pivotpoint]);
 return;
}
void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
