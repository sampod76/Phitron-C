
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int arr[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d \n", arr[i]);
    // }
    int freq[100] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        // printf("%d -> %d \n",i, freq[i]);
        if (freq[i])
        {
            printf("%d have total  -> %d \n", i, freq[i]);
        }
    }

    return 0;
}

/*
input:
10
5 4 2 4 5 3 2 5 4 5
*/
/*
output:
2 have total  -> 2
3 have total  -> 1
4 have total  -> 3
5 have total  -> 4

*/