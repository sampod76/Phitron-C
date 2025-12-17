
#include <stdio.h>
void LoopPrint()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
}
int main()
{

    printf("");
    LoopPrint();
    return 0;
}