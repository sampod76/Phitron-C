#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    char a[n + 1];
    scanf("%s", &a);
    int slength = strlen(a);
    int sum = 0;
    for (int i = 0; i < slength; i++)
    {
        // sum = sum + (a[i] - '0'); // char '0' ASCII value 48
        sum = sum + (a[i] - 48);
    }
    printf("%d", sum);
    return 0;
}