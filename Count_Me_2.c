
#include <stdio.h>
#include <string.h>
int main()
{

    char sta[100001];
    scanf("%s", sta);
    int sLength = strlen(sta);
    int totalConsonants = 0;
    for (int i = 0; i < sLength; i++)
    {
        if (sta[i] != 'a' && sta[i] != 'e' && sta[i] != 'i' && sta[i] != 'o' && sta[i] != 'u')
        {
            totalConsonants++;
        }
    }
    printf("%d", totalConsonants);
    return 0;
}
