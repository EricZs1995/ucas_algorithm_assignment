//
//  main.c
//  Assign Banana
//
//  Created by 苗天昊 on 2018/11/15.
//  Copyright © 2018 苗天昊. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 500
int monkey[N];
int banana[N];

int weight[N];

int cmp ( const void *a , const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int i = 0;
    int j;
    char c;
    int max;
    do{
        scanf("%d", &monkey[i]);
        i++;
    }while((c = getchar())!= '\n');

    for(j = 0; j < i; j++){
        scanf("%d", &banana[j]);
    }
    qsort(monkey, i, sizeof(int), cmp);
    qsort(banana, i, sizeof(int), cmp);
    max = abs(monkey[0] - banana[0]);
    for(j = 0; j < i; j++){
        if(abs(monkey[j] - banana[j]) > max)
            max = abs(monkey[j] - banana[j]);
    }
    printf("%d", max);
    return 0;
}

