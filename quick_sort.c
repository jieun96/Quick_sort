#include <stdio.h>
void quicksort(int,int,int*);
void partition(int, int, int*,int*);
void swap(int*,int*);
int main(){
	int low = 0, high, i;
	printf("배열 크기 입력 :");
	scanf("%d",&high);
	int s[high];
	for(i=0;i<high;i++){
		printf("s[%d] 입력 : ",i);
		scanf("%d",&s[i]);
	}
	quicksort(low,high-1,s);
	for(i=0;i<high;i++){
		printf("s[%d] = %d\n",i,s[i]);
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
