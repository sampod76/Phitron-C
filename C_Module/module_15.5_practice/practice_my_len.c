#include <stdio.h>

int fun(char s[], int n)
{
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {

        total++;
    }
    return total;
}
int main()
{
    char s[100001];
    scanf("%s", s);
    // printf("%s \n", s);
    printf("%d", fun(s, 100001));

    return 0;
}