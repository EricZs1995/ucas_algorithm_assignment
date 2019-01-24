#include<stdio.h>
#include<map>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

struct pai
{
	double s;
	double e;
} a[6];

double opt[6];

int findmin(){
	int i=0,j = 0;
	double m = -1;
	for( i = 1;i<5;i++){
		double 	tmp = opt[i]-opt[i-1];
		if(tmp > m){
			j = i-1;
			m = tmp;
		}
	}
	return j;

}

double findmax(){
	int i=0,j = 0;
	double m = -100.0;
	for( i = 1;i<5;i++){
		double 	tmp = opt[i]-opt[i-1];
		if(tmp > m){
			j = i-1;
			m = tmp;
		}
		printf("%lf,%lf\n",m,tmp);
	}
	printf("**********");
	for (int i = 0; i < 4; ++i)
	{
		printf("%.2lf ", opt[i]);
	}
	printf("%.2lf\n", opt[4]);
	printf("%lf\n",m);
	return m;
}

int main(){
	int n = 0;
	int i,j,k,l,r;
	for (i =0;i<5;i++){
		scanf("%lf%lf",&a[i].s,&a[i].e);
		opt[i] = a[i].s;
	}
	opt[4] = a[4].e;
	k=-1;
	double tmp = 0.0,t2 = 0.0,t1 = 0.0,t=0.0;
	opt[4] = a[4].e;
	double pre =  -1.0,cur = -101.0,n1,n2;
	int flag = 1;
	while(flag==1){
		printf("-------");
		j = findmin();
		printf("%d\n",j);
		printf("%lf  %lf\n",pre,cur);
		for (int i = 0; i < 4; ++i)
		{
			printf("%.2lf ", opt[i]);
		}
		printf("%.2lf\n", opt[4]);
		pre = cur;
		flag = 0;
		if(j==0){
			//see 3[2,3,4]
			t2 = opt[1];
			tmp = (opt[0]+opt[2])/2;
			if(tmp<a[1].s){
				opt[1] = a[1].s;
			}else if (tmp>a[1].e){
				opt[1] = a[1].e;
			}else{
				opt[1] = tmp;
			}
			t = min(opt[1]-opt[0],opt[2]-opt[1]);
			if(opt[1]!=t2){flag=1;}
		}	
		else if(j == 3){
			//see 3[2,3,4]
			t2 = opt[3];
			tmp = (opt[4]+opt[2])/2;
			if(tmp<a[3].s){
				opt[3] = a[3].s;
			}else if (tmp>a[3].e){
				opt[3] = a[3].e;
			}else{
				opt[3] = tmp;
			}
			t = min(opt[3]-opt[2],opt[4]-opt[3]);
			if(opt[3]!=t2){flag=1;}
		}else{
			double tmp1=opt[j],tmp2 = opt[j+1];
			//see j,[j-1,j,j+1]
			t1 = 100.0;
			tmp = (opt[j-1]+opt[j+1])/2;
			if(tmp < a[j].s){
				t1 = min(a[j].s-opt[j-1],opt[j+1]-a[j].s);
				n1 = a[j].s;
			}else if(tmp>a[j].e){
				t1 = min(a[j].e-opt[j-1],opt[j+1]-a[j].e);
				n1 = a[j].e;
			}else{
				t1 = tmp-opt[j-1];
				n1 = tmp;
			}

			//see j+1,[j,j+1,j+2]
			t2 = 100.0;
			tmp = (opt[j]+opt[j+2])/2;
			if(tmp < a[j+1].s){
				t2 = min(a[j+1].s-opt[j],opt[j+2]-a[j+1].s);
				n2 = a[j+1].s;
			}else if(tmp>a[j+1].e){
				t2 = min(a[j+1].e-opt[j],opt[j+2]-a[j+1].e);
				n2 = a[j+1].e;
			}else{
				t2 = tmp-opt[j];
				n2 = tmp;
			}

			//s
			if(t1<t2){
				opt[j] = n1;
				t = t1;
				if(tmp1 != opt[j])flag=1;
			}else{
				opt[j+1] = n2;
				t=t2;
				if(tmp2 != opt[j+1])flag=1;
				
			}
		}
		cur = findmax();
		printf("cur:%lf\n",cur);
	}
		printf("%d\n",j);
		printf("%lf  %lf\n",pre,cur);
	for (int i = 0; i < 4; ++i)
	{
		printf("%.2lf ", opt[i]);
	}
	printf("%.2lf\n", opt[4]);
	return 0;
}
