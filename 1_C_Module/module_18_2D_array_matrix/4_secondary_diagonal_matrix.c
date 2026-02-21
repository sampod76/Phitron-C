
// https://phitron.io/ph028/video/ph028-18-12-checking-secondary-diagonal-matrix
#include <stdio.h>
#include <stdbool.h>
/* // first of all full shape hota hoba squire and only corner value any number other all 0
3 3

0 0 1
0 2 0
5 0 0

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
                if (i + j == r - 1)
                {
                    // we are now at secondary diagonal of a matrix // skip checking
                }
                else
                {
                    if (a[i][j] != 0)
                    {
                        is_diagonal = false;
                    }
                }
            }
        }
        if (is_diagonal)
        {
            printf("This is a secondary diagonal of a matrix\n");
        }
    }
    else
    {
        printf("This is not a secondary diagonal of a matrix\n");
    }

    return 0;
}
