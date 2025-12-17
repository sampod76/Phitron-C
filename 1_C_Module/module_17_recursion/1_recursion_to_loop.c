
#include <stdio.h>
void hello(int i)
{
    if (i == 6)
    {
        return;
    }
    printf("%d\n", i);
    hello(i + 1);
}
int main()
{

    // int i;
    // scanf("%d", &i);
    int i = 5;
    hello(i);
    return 0;
}