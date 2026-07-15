#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int left, int mid, int right){
    int i=left;
    int j=mid+1;
    int k=0;
    int *temp=(int *)malloc((right-left+1)*sizeof(int));
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++){
        arr[i]=temp[k];
    }
    free(temp);
}
void mergeSort(int arr[],int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,0,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    int n;
    printf("Enter number of elements:\t");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted Elements:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    free(arr);
    return 0;
}