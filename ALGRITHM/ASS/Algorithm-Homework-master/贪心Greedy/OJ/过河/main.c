//
//  main.c
//  Greedy_Cross River
//
//  Created by 苗天昊 on 2018/11/14.
//  Copyright © 2018 苗天昊. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 50000

int n;//人数
int weight_limit;//权重限制
int weight[N];
int cmp ( const void *a , const void *b)
{
    return *(int *)b - *(int *)a;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, j;
    scanf("%d%d", &n, &weight_limit);
    for(i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }
    qsort(weight, n, sizeof(int), cmp);
    int number = 0;
    i = 0;
    j = n - 1;
    while(i <= j){
	number++;
	if(weight[i] + weight[j] <= weight_limit)
	    j--;
	i++;
    }
    printf("%d\n", number);
    return 0;
}
