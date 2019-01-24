
/*
DP Problem No.1
Author VastSky_Miaow 
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100000 
#define Tmax 1000


int T;
int seq[Tmax][N];
int len[Tmax]; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void init_len(int t){
	int i;
	for(i=0;i<t;i++)
		len[i] = 1;	
}

int BinaryDivisionInsert(int *s, int low, int high, int x){
	int mid;
	//printf("X:%d low=%d high=%d\n", x,low, high);
	mid = (low+high)/2;
	if(low >= high){
		if(s[mid] == x)
			return mid;
		else if(s[mid] < x)
			return mid+1;
		else
			return mid;
		}
	if(s[mid] == x)
		return mid;
	else if(s[mid] > x)
		return BinaryDivisionInsert(s, low, mid-1, x);
	else
		return BinaryDivisionInsert(s, mid+1, high, x);
	
} 

int LIS(int *a, int t, int n){
	int i, slen, pos, s[N];
	if(n == 0)
		return 0;
	s[0] = a[0];
	slen = 0;
	for(i=1;i<n;i++){
		pos = BinaryDivisionInsert(s, 0, slen, a[i]);
		//printf("pos:%d\n", pos); 
		if(pos > slen){
			slen++;
			s[pos] = a[i];}
		else{
			if(a[i] < s[pos])
				s[pos] = a[i];
		} 
	}
	return slen+1;
}

/*
int LIS(int *a, int t, int n){
	if(n == 1){
		return 1;
	}
	int i, j;
	int Slen[N];
	Slen[0] = 1;
	
	for(i=0;i<n;i++){
		Slen[i] = 1;
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[j] < a[i] &&  Slen[i] < Slen[j]+1)
				Slen[i] = Slen[j]+1;
		}
	}
	int max = Slen[0];
	for(i=1;i<n;i++){
		if(Slen[i]>max)
			max = Slen[i];
	} 
	len[t] = max;
	return max;
}
*/

int main(int argc, char *argv[]) {
	int i, n, t, l;
	scanf("%d", &T);
	init_len(T);
	for(t=0;t<T;t++){
		scanf("%d", &n);
		for(i=0;i<n;i++){
			scanf("%d", &seq[t][i]);
			//printf("%d ",seq[i]);
		}
		
		len[t] = LIS(seq[t], t, n); 

	}
	for(t=0;t<T;t++){
		printf("%d\n",len[t]);
	}
	return 0;
}

