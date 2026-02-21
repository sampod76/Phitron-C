
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int space = n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        space--;
        /*
        //when need serila wiase print then it
          for (int j = 1; i >= j; j++)
         {

             printf("%d", j);
         }
         */
        for (int j = i; j >= 1; j--)
        {

            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}