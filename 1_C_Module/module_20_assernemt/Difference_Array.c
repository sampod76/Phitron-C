
#include <stdio.h>
#include <stdlib.h>
int main()
{

    int t; // test case
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        int duplicateArray[n]; // duplicate array
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
            duplicateArray[j] = a[j];
        }

        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d ", duplicateArray[j]);
        // }
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (duplicateArray[j] > duplicateArray[k])
                {
                    int temp = duplicateArray[j];
                    duplicateArray[j] = duplicateArray[k];
                    duplicateArray[k] = temp;
                }
            }
        }
        int def[n]; // a and duplicateArray  absolute  difference

        for (int k = 0; k < n; k++)
        {
            def[k] = abs(a[k] - duplicateArray[k]);
        }
        for (int k = 0; k < n; k++)
        {
            printf("%d ", def[k]);
        }

        printf("\n");
    }

    return 0;
}