
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        // printf("index %d \n",i);
        int m1, d, m2;
        scanf("%d %d %d", &m1, &m2, &d);
        // printf("%d %d %d \n", m1, m2, d);
        // int totalMan=m1 + m2;
        int totalDay = (m1 * d) / (m1 + m2);
        // printf("total %d \n", totalDay);
        int extraDay = d - totalDay;
        printf("%d\n", extraDay);
    }
    return 0;
}