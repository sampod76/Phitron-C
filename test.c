#include <stdio.h>

int main()
{
    float x;
    scanf("%f", &x);
    printf("%.3f", x);

    return 0;
}

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            scanf("%d", &arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }
}