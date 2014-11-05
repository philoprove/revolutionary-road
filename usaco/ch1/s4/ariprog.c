/*
ID:sphy1
LANG: C
TASK: ariprog
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "ariprog.in"
#define OUTPUT "ariprog.out"
int POW_TABLE[250];
int idx=0;
int maxcomb;
int ret[2];

int *ALL;


void build_pow_list(int max)
{
    int i;
    for(i=0;i<=max;i++)
    {
        POW_TABLE[i] = i * i;
    }
}

int print_array(int li[])
{
    int i, size= maxcomb;
    for(i=0;i<size;i++)
    {
        printf("%d ",li[i]);
    }
    printf("\n");
}


void comb(int array[], int length, int picked)
{
    if(length < picked){
        return;
    }
    if(picked<=0){
//        printf("%d\n",ret[0] + ret[1]);
        ALL[ret[0] + ret[1]] ++;
        return;
    }
    int i;
    for(i=0;i<length;i++)
    {
        ret[idx] = array[i];
        idx ++;
        comb(array, length, picked-1);
        idx --;
    }
    return;
}

int in_comb(int number){
    if(number>=maxcomb){ // if not append equal ,can't pass case 1
        return 0;
    }
    if(ALL[number]==0)
    {
        return 0;
    }
    return 1;
}

int found(int start,int b,int needed)
{
    int i;
    for(i=0;i<needed;i++){
        if(in_comb(start+i*b)==0)
        {
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int N, M;
    scanf("%d\n%d", &N, &M);
    maxcomb = M*M*2+1;
    build_pow_list(M);
    ALL = (int*)malloc(maxcomb*sizeof(int));
    int i;
    for(i=0;i<maxcomb;i++)
    {
        *(ALL+sizeof(int)*i) = 0;
    }
//    print_array(ALL);
    comb(POW_TABLE,M+1,2); // list all a^2 + b^2
//    print_array(ALL);
//    printf("%d\n%d", (int)sizeof(ALL), ALL[64]);
    int max_b = M*M*2/(N - 1);
    int b,start,none=0;
    for(b=1;b<=max_b;b++)
    {
        for(start=0;start<maxcomb;start++){
//            printf("detect:%d %d neeed:%d\n", start, b, N);
            if(found(start,b,N)!=0)
            {
                printf("%d %d\n", start, b);
                none ++;
            }
        }
    }
    if(none==0){
        printf("%s\n","NONE");
    }
    exit(0);
}