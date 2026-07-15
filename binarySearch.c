#include<stdio.h>
#include<stdlib.h>
int binarySearch(int arr[],int low,int high,int key){
    if(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n,key;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter key:");
    scanf("%d",&key);
    int result=binarySearch(arr,0,n-1,key);
    if(result==-1){
        printf("key not found\n");
    }
    else{
        printf("key found at %dth index",result);
    }
    free(arr);
    return 0;
}