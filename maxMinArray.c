#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int maximun(int a, int b){
    return (a>b)?a:b;
}
int minimun(int a, int b){
    return (a<b)?a:b;
}
void maxMin(int arr[],int low, int high,int *max,int *min){
    if(low==high){
        *max=*min=arr[low];
        return;
    }
    if(high==low+1){
        if(arr[low]<arr[high]){
            *max=arr[high];
            *min=arr[low];
        }
        else{
            *max=arr[low];
            *min=arr[high];
        }
        return;
    }
    int mid=(low+high)/2;
    int max1,min1,max2,min2;
    maxMin(arr,low,mid,&max1,&min1);
    maxMin(arr,mid+1,high,&max2,&min2);
    *max=maximun(max1,max2);
    *min=minimun(min1,min2);
}
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max,min;
    maxMin(arr,0,n-1,&max,&min);
    printf("Maximum:%d\n",max);
    printf("Minimum:%d\n",min);
    return 0;
}