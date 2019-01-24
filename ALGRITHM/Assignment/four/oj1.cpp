#include<iostream>
#include<map>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

const int M=208,N=1008,INT_MA=1e9;

const double eps=1e-6;

inline int read_data(){
    char cost=getchar();int x=0,f=1;
    while(cost<'0'||cost>'9'){
        if(cost=='-')
            f =-1;
        cost=getchar();
    }
    while(cost>='0'&&cost<='9'){
        x=x*10+cost-'0'; 
        cost=getchar();
    }
    return x*f;
}

int n,m;
double a[M][N],b[M],cost[N],v;

void pivot(int l,int e){
    b[l]/=a[l][e];
    for(int j=1;j<=n;j++) 
        if(j!=e) 
            a[l][j]/=a[l][e];
    a[l][e]=1/a[l][e];
    
    for(int i=1;i<=m;i++) 
        if(i!=l&&fabs(a[i][e])>0){
            b[i]-=a[i][e]*b[l];
            for(int j=1;j<=n;j++) 
                if(j!=e) a[i][j]-=a[i][e]*a[l][j];
            a[i][e]=-a[i][e]*a[l][e];
        }
    
    v+=cost[e]*b[l];
    for(int j=1;j<=n;j++) 
        if(j!=e) 
            cost[j]-=cost[e]*a[l][j];
    cost[e]=-cost[e]*a[l][e];
}

double simplex(){
    while(true){
        int e=0,l=0;
        for(e=1;e<=n;e++) 
            if(cost[e]>eps) 
                break;
        if(e==n+1) return v;
        double max_n=INT_MA;
        for(int i=1;i<=m;i++)
            if(a[i][e]>eps&&max_n>b[i]/a[i][e]) 
                max_n=b[i]/a[i][e],l=i;
        if(max_n==INT_MA) 
            return INT_MA;
        pivot(l,e);
    }
}

int main(){
    n=read_data();
    m=read_data();
    for(int i=1;i<=n;i++) 
        cost[i]=read_data();
    for(int i=1;i<=m;i++){
        int s=read_data(),t=read_data();
        for(int j=s;j<=t;j++) 
            a[i][j]=1;
        b[i]=read_data();
    }
    printf("%d\n",(int)(simplex()+0.5));
}

