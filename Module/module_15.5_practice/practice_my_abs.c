
#include <stdio.h>
#include <stdlib.h>
int fun(int i)
{
    return abs(i);
}
int main()
{
    int i;
    scanf("%d", &i);

    printf("%d", fun(i));

    return 0;
}