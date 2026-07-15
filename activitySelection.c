#include<stdio.h>
#include<stdlib.h>
struct activity    
{
    int start;
    int finish;
};
void bubbleSort(struct activity arr[], int n){
    struct activity temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].finish>arr[j+1].finish){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void activitySelection(struct activity arr[],int n){
    bubbleSort(arr,n);
    printf("Selected Activities:\n");
    int last=0;
    printf("(%d %d)",arr[0].start,arr[0].finish);
    for(int i=1;i<n;i++){
        if(arr[i].start>=arr[last].finish){
            printf("(%d %d)",arr[i].start,arr[i].finish);
            last=i;
        }
    }
}
int main(){
    int n;
    printf("Enter no. of activites:");
    scanf("%d",&n);
    struct activity arr[n];
    for(int i=0;i<n;i++){
        printf("Enter activity %d:(in start finish order)",i+1);
        scanf("%d %d",&arr[i].start,&arr[i].finish);
    }
    activitySelection(arr,n);
    return 0;
    
}