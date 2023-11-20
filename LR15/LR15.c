#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int mas[n][n], ans[n], lwmax[n], max = -32768;


    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
        lwmax[i] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mas[i][j]);
            if (mas[i][j] > max)
            {
                max = mas[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mas[i][j]);
            if (mas[i][j] == max)
            {
                lwmax[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (lwmax[i] == 1)
        {
        for (int j = 0; j < n; j++)
            {
                ans[j] += mas[i][j];
            }
        }
    }

    printf("\nРезультат сложения:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (lwmax[i] == 1)
        {
        for (int j = 0; j < n; j++)
            {
                mas[i][j] = ans[j];
            }
        break;
        }
        
    }

    printf("\nПолучилась матрица:");

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mas[i][j]);
        }
    }
}