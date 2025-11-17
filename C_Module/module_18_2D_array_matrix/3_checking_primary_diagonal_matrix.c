
#include <stdio.h>
#include <stdbool.h>
/* // first of all full shape hota hoba squire and only corner value any number other all 0
3 3

1 0 0
0 2 0
0 0 9

*/
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
    bool is_diagonal = true;
    if (r == c)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == j)
                {
                    // we are now at diagonal , jast skip
                }
                else
                {
                    if (a[i][j] != 0)
                    {
                        is_diagonal = false;
                        printf("This is not a primary diagonal marix\n");
                    }
                }
            }
        }
        if (is_diagonal)
        {
            printf("This is a primary diagonal marix\n");
        }
    }
    else
    {
        printf("This is not a primary diagonal marix\n");
    }

    return 0;
}
