#include <stdio.h>
#include <stdlib.h>
#define INF 999999
void floydWarshall(int **G, int n)
{
    int dist[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = G[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Shortest distance %d -> %d= %d\n", i, j, dist[i][j]);
        }
    }
}
int main()
{
    int n;
    printf("Enter size:");
    scanf("%d", &n);
    int **G = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        G[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter Adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    floydWarshall(G, n);
    for (int i = 0; i < n; i++)
    {
        free(G[i]);
    }
    free(G);
    return 0;
}