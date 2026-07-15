#include<stdio.h>
#include<stdlib.h>
#define INF 999999
int minDistance(int dist[],int visited[],int n){
    int min=INF,minIndex=-1;
    for(int i=0;i<n;i++){
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void dijkstra(int **graph,int n, int src){
    int *dist=(int *)malloc(n*sizeof(int));
    int *visited=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        dist[i]=INF;
        visited[i]=0;
    }
    dist[src]=0;
    for(int count=0;count<n-1;count++){
        int u=minDistance(dist,visited,n);
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(visited[v]==0 && graph[u][v]!=0 && dist[u] != INF && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("Shortest distance from %d\n",src);
    for(int i=0;i<n;i++){
        printf("%d->%d=%d\n",src,i,dist[i]);
    }
    free(dist);
    free(visited);
}
int main(){
    int n,src;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    int **graph=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        graph[i]=(int *)malloc(n*sizeof(int));
    }
    printf("Enter weighted adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter source vertex:");
    scanf("%d",&src);
    dijkstra(graph,n,src);
    for(int i=0;i<n;i++){
        free(graph[i]);
    }
    free(graph);
    return 0;
}