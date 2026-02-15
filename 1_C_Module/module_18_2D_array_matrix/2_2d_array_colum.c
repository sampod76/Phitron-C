#include <stdio.h>
int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // print
    int specific_row;
    scanf("%d", &specific_row);
    for (int i = 0; i < c; i++)
    {

        printf("%d ", a[specific_row][i]);
    }
    printf("\n");
    // when need print col
    int specific_col = 0;
    for (int i = 0; i < r; i++)
    {

        printf("%d ", a[i][specific_col]);
    }
    return 0;
}

/* input

2 3
2 1 5
3 6 5
1

*/

/*
3 6 5
*/