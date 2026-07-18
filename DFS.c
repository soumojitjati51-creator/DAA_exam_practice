#include<stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=-1;
void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}
void DFS(int n, int start){
    push(start);
    printf("DFS Traversal:\n");
    while (!isEmpty())
    {
        int u=pop();
        if(visited[u]==0){
            visited[u]=1;
            printf("%d\t_",u);
            for(int i=0;i<n;i++){
                if(graph[u][i]==1 && visited[i]==0){
                    push(i);
                }
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
    DFS(n,start);
    return 0;
}