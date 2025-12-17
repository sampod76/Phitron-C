
#include <stdio.h>
void fun(int *p, int value)
{
    *p = value;
}
int main()
{

    int n;

    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int replaceindex, replaceValue;
    scanf("%d %d", &replaceindex, &replaceValue);
    int *p;
    p = &a[replaceindex];
    // or -- one line declare and pointer value set
    //  int *p = &a[replaceindex];
    // printf("%p\n", p);

    fun(p, replaceValue);
    printf("%d", a[replaceindex]);

    return 0;
}