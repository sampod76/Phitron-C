
#include <stdio.h>

//? replace any array element
/*
int main()
{

    int n; //5
    scanf("%d", &n);
    int a[n]; //10 20 11 12 13
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int index, value; //2 500
    scanf("%d %d", &index, &value);
    a[index] = value;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]); //10 20 500 12 13
    }

    return 0;
} */

// https://phitron.io/ph028/video/ph028-9-3-insert-a-value-in-an-array-implementation
int main()
{

    int n; // 5
    scanf("%d", &n);

    int a[n + 1]; // 10 20 11 12 13
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        // printf("%d --", a[i]);
    }
    int index, value; // 2 500
    scanf("%d %d", &index, &value);
    for (int i = n; i >= index + 1; i--)
    {
        a[i] = a[i - 1];
        // printf("%d ", a[i]);
    }

    a[index] = value;
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", a[i]); // 10 500 20 11 12 13
    }

    return 0;
}