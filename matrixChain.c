#include <stdio.h>
#include <stdlib.h>
#define INF 999999
int matrixChain(int p[], int n)
{
    int **m = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        m[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i <= n - l; i++)
        {
            int j = i + l - 1;
            m[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    int ans = m[1][n - 1];

    for (int i = 0; i < n; i++)
        free(m[i]);
    free(m);
    return ans;
}
int main()
{
    int n;
    printf("Enter no. of metrices:");
    scanf("%d", &n);
    int *p = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter dimensions:");
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%d", &p[i]);
    }
    int result = matrixChain(p, n + 1);
    printf("minimum no. of multiplications=%d", result);
    free(p);
    return 0;
}