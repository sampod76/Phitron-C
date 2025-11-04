
#include <stdio.h>
#include <string.h>
// char a[10000001];
int main()
{
    char a[10001];
    scanf("%s", a);
    int sLength = strlen(a);
    int freArray[26] = {0};
    for (int i = 0; i < sLength; i++)
    {

        int setIndex = a[i] - 'a'; // a ASCII value 97
        freArray[setIndex]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freArray[i])
        {
            printf("%c - %d\n", i + 'a', freArray[i]);
        }
    }
    return 0;
}
