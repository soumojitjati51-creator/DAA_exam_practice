#include<stdio.h>
#include<stdlib.h>
struct Item{
    int id,weight,profit;
    float ratio;
};
void bubbleSort(struct Item arr[],int n){
    struct Item temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].ratio<arr[j+1].ratio){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
float fractionalKnapsack(struct Item arr[],int n,int M){
    float total=0;
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        if(M>=arr[i].weight){
            total+=arr[i].profit;
            M-=arr[i].weight;
        }else{
            total+=arr[i].ratio*M;
            break;
        }
    }
    return total;
}
int main(){
    int n,M;
    printf("Enter no. of items:");
    scanf("%d",&n);
    printf("Enter items :\n");
    struct Item *arr=(struct Item *)malloc(n*sizeof(struct Item));
    for(int i=0;i<n;i++){
        printf("Enter item %d(id weight profit):",i+1);
        scanf("%d %d %d",&arr[i].id,&arr[i].weight,&arr[i].profit);
        arr[i].ratio=(float)arr[i].profit/arr[i].weight;
    }
    printf("Enter knapsack capacity:");
    scanf("%d",&M);
    float result=fractionalKnapsack(arr,n,M);
    printf("maximum profit=%f",result);
    free(arr);
    return 0;
}