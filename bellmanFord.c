#include <stdio.h>
#include <stdlib.h>
#define INF 999999
struct Edge
{
    int src, dest, weight;
};
void bellmanFord(struct Edge arr[], int V, int E, int src)
{
    int *dist = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = arr[j].src;
            int v = arr[j].dest;
            int w = arr[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int j = 0; j < E; j++)
    {
        int u = arr[j].src;
        int v = arr[j].dest;
        int w = arr[j].weight;
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("Negative cycle exists!");
            free(dist);
            return;
        }
    }
    printf("\n Shortest distance from %d:\n",src);
    for(int i=0;i<V;i++){
        printf("%d -> %d=%d\n",src,i,dist[i]);
    }
    free(dist);

}
int main(){
    int V,E,src;
    printf("Enter no. of vertices and edges:");
    scanf("%d %d",&V,&E);
    struct Edge *arr=(struct Edge *)malloc(E*sizeof(struct Edge));
    printf("Enter edges(src,dest,weight):\n");
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&arr[i].src,&arr[i].dest,&arr[i].weight);
    }
    printf("Enter source:");
    scanf("%d",&src);
    bellmanFord(arr,V,E,src);
    free(arr);
    return 0;
}
