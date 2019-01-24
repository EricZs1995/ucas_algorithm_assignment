// #include<stdio.h>
// #include<algorithm>
// #include<string.h>
// #include<sstream>
// #include<iostream>
// #include<cmath>
// using namespace std;
// // int max(int a,int b){
// // 	return a>b?a:b;
// // }
// // int abs(int a){
// // 	return a>0?a:-a;
// // }
// int main(){
// 	int *a,*b;
// 	string s1,s2;
// 	getline(cin,s1);
// 	getline(cin,s2);
// 	stringstream ss1(s1);
// 	stringstream ss2(s2);
// 	stringstream ss(s1);
// 	int len=0;
// 	int i,j,k,l;
// 	while(ss>>i)len++;
// 	a = (int *)malloc(len*sizeof(int));
// 	b = (int *)malloc(len*sizeof(int));
// 	i=0;
// 	while(ss1>>k){
// 		a[i++]=k;
// 	}
// 	i=0;
// 	while(ss2>>k){
// 		b[i++]=k;
// 	}
// 	sort(a,a+len);
// 	sort(b,b+len);
// 	l=0;
// 	for(i=0;i<len;i++){
// 		l = max(l,abs(a[i]-b[i]));
// 	}
// 	printf("%d\n", l);
// 	free(a);
// 	free(b);
// 	return 0;
// }


#include<stdio.h>
#include<algorithm>
#include<string.h>
// #include<sstream>
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
int a[5000002];
int b[5000002];
int main(){
//    int *a,*b;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
	int i,j,k,l,len=0;
    i=0;
    j=0;
    k=0;
    int lens = s1.length();
    while(i<lens){
    	if(s1[i]==' '){
    		a[j++]=k;
    		// printf("%d\n", k);
    		k=0;
    	}else{
    		k=k*10+(s1[i]-'0');
    	}
    	i++;
    }
    a[j++]=k;
    // printf("%d\n",k );
    len=j;
    i=0;
    j=0;
    k=0;
    lens = s1.length();
    while(i<lens){
    	if(s2[i]==' '){
    		b[j++]=k;
    		k=0;
    	}else{
    		k=k*10+(s2[i]-'0');
    	}
    	i++;
    }
    b[j++]=k;
    // printf("%d\n",k );

//     stringstream ss1(s1);
//     stringstream ss2(s2);
// //    stringstream ss(s1);
//     int len=0;
//     int i,j,k,l;
//   //  while(ss>>i)len++;
//  //   a = (int *)malloc(len*sizeof(int));
//    // b = (int *)malloc(len*sizeof(int));
//     i=0;
//     while(ss1>>k){
//         a[i++]=k;
//     }
// 	len=i;
//     i=0;
//     while(ss2>>k){
//         b[i++]=k;
//     }
    sort(a,a+len);
    sort(b,b+len);
    l=0;
    for(i=0;i<len;i++){
        l = max(l,abs(a[i]-b[i]));
    }
    printf("%d\n", l);
  //  free(a);
//free(b);
    return 0;
}