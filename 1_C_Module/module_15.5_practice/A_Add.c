
#include <stdio.h>

int sum(int x, int y)
{
    return x + y;
}
int main()
{

    int x, y;
    scanf("%d %d", &x, &y);
    const total = sum(x, y);
    printf("%d", total);

    return 0;
}