// #include<stdio.h>
// #include<stdlib.h>
// struct Job{
//     int id,deadline,profit;
// };
// void bubbleSort(struct Job arr[],int n){
//     struct Job temp;
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(arr[j].profit<arr[j+1].profit){
//                 temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
// }
// void jobSequencing(struct Job arr[],int n){
//     bubbleSort(arr,n);
//     int maxDeadline=0;
//     for(int i=0;i<n;i++){
//         if(arr[i].deadline>maxDeadline){
//             maxDeadline=arr[i].deadline;
//         }
//     }
//     int slot[maxDeadline];
//     int result[maxDeadline];
//     for(int i=0;i<n;i++){
//         slot[i]=0;
//     }
//     int totalprofit=0;
//     for(int i=0;i<n;i++){
//         for(int j=maxDeadline-1;j>=0;j--){
//             if(slot[i]==0){
//                 slot[i]=1;
//                 result[j]=i;
//                 totalprofit+=arr[i].profit;
//             }
//         }
//     }
//     printf("Selected jobs are:\n");
//     for(int i=0;i<maxDeadline;i++){
//         if(slot[i]){
//             printf("%d\t",arr[result[i]].id);
//         }
//     }
//     printf("total profit=%d",totalprofit);

// }
// int main(){
//     int n;
//     printf("Enter no. of jobs:");
//     scanf("%d",&n);
//     struct Job *arr=(struct Job *)malloc(n*sizeof(struct Job));
//     printf("Enter jobs:\n");
//     for(int i=0;i<n;i++){
//         printf("Enter job %d (id,deadline,profit):",i+1);
//         scanf("%d %d %d",&arr[i].id,&arr[i].deadline,&arr[i].profit);
//     }
//     jobSequencing(arr,n);
//     free(arr);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id, deadline, profit;
};

void bubbleSort(struct Job arr[], int n) {
    struct Job temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Sort in descending order of profit
            if (arr[j].profit < arr[j + 1].profit) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void jobSequencing(struct Job arr[], int n) {

    bubbleSort(arr, n);

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;
    }

    int slot[maxDeadline];
    int result[maxDeadline];

    // Initialize slots
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = 0;
        result[i] = -1;
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {

        // Try to schedule from the last available slot
        for (int j = arr[i].deadline - 1; j >= 0; j--) {

            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = i;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Jobs:\n");

    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("Job %d\n", arr[result[i]].id);
        }
    }

    printf("Total Profit = %d\n", totalProfit);
}

int main() {

    int n;

    printf("Enter no. of jobs: ");
    scanf("%d", &n);

    struct Job *arr = (struct Job *)malloc(n * sizeof(struct Job));

    printf("Enter jobs:\n");

    for (int i = 0; i < n; i++) {
        printf("Enter Job %d (id deadline profit): ", i + 1);
        scanf("%d %d %d", &arr[i].id, &arr[i].deadline, &arr[i].profit);
    }

    jobSequencing(arr, n);

    free(arr);

    return 0;
}