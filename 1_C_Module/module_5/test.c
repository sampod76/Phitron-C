
// #include <stdio.h>

// int main()
// {

//     int n;
//     scanf("%d ", &n);

//     if ((n / 1000) % 2 == 0)
//     {
//         printf("EVEN");
//     }
//     else
//     {
//         printf("ODD");
//     }

//     return 0;
// }

// set valid character

#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    // minimum
    if (a <= b && a <= c)
    {
        printf("%d ", a);
    }
    else if (b <= a && b <= c)
    {
        printf("%d ", b);
    }
    else if (c <= a && c <= b)
    {
        printf("%d ", c);
    }

    // maximum
    if (a >= b && a >= c)
    {
        printf("%d", a);
    }
    else if (b >= a && b >= c)
    {
        printf("%d", b);
    }
    else if (c >= a && c >= b)
    {
        printf("%d", c);
    }

    return 0;
}