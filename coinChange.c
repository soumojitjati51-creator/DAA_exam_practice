#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int c[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(c[j]<c[j+1]){
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
}
void coinChange(int c[],int n, int amount){
    int count=0;
    bubbleSort(c,n);
    printf("\nCoins used:\n");
    for(int i=0;i<n;i++){
        while(amount>=c[i]){
            amount-=c[i];
            printf("%d\t",c[i]);
            count++;
        }
    }
    if(amount!=0){
        printf("\nRemaining amount:%d",amount);
    }else
    {
        printf("\namount achieved success fully!");
    }
    printf("\nTotal coins used:%d\n",count);
}
int main(){
    int n,amount;
    printf("Enter no. of types of coins:");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter coins:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter amount:");
    scanf("%d",&amount);
    coinChange(arr,n,amount);
    free(arr);
    return 0;
}