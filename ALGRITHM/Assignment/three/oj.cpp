#include<stdio.h>
#include<algorithm>
#include<string.h>

int a[30004];
int cmp(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,m,i,j,k,l;
	while(scanf("%d%d",&n,&m)!=EOF){
		k=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++){
			scanf("%d",&l);
			a[l]++;
		}
		j=0;
		// sort(a,a+n,cmp);
		// for(i=30000;i>m;i--){
		// 	if(a[i]>0){
		// 		j=1;
		// 		return 0;
		// 	}
		// }
		for (i = 30000; i >0;)
		{
			if(a[i]==0)continue;
			a[i]--;
			for(j = m-i;j>=0;j--){
				if(a[j]>0){
					a[j]--;
					break;
				}
			}
			if (a[i]==0)
			{
				i--;	
			}
			k++;
		}
		printf("%d\n", k);
	}

	return 0;
}