
#include <stdio.h>
#include <stdbool.h>
int main()
{

    int row, column;
    scanf("%d %d", &row, &column);
    int a[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }
    if (row == column)
    { // square matrix
        bool is_jadu = true;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == j)
                {
                    if (a[i][j] != 1)
                    {
                        is_jadu = false;
                    }
                    // we are now at diagonal jast skip
                }
                else if (i + j == row - 1)
                {
                    if (a[i][j] != 1)
                    {
                        is_jadu = false;
                    }
                }

                else
                {
                    if (a[i][j] != 0)
                    {
                        is_jadu = false;
                    }
                }
            }
        }
        if (is_jadu)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    else
    {
        printf("NO");
    }

    return 0;
}