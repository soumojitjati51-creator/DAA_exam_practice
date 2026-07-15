#include<stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front=-1, rear=-1;
void enqueue(int x){
    if(front==-1){
        front=0;
    }
    queue[++rear]=x;
}
int dequeue(){
    return queue[front++];
}
int isEmpty(){
    return front>rear;
}
void BFS(int n,int start){
    visited[start]=1;
    enqueue(start);
    printf("BFS Traversal:\n");
    while(!isEmpty()){
        int u=dequeue();
        printf("%d\t",u);
        for(int i=0;i<n;i++){
            if(graph[u][i]==1 && visited[i]==0){
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}
int main(){
    int n,start;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter start vertex:");
    scanf("%d",&start);
    BFS(n,start);
    return 0;
}