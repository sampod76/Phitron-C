
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int is_palindrome(char s[])
{
    int length = strlen(s);
    // printf("%d\n",length);
    char new[1001];
    for (int i = 0; i < length; i++)
    {
        new[i] = s[i];
    }

    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    int pandulam = 1; // 1 min true
    for (int i = 0; i < length; i++)
    {
        // printf("%c-%c\n",s[i],new[i]);
        if (s[i] != new[i])
        {
            pandulam = 0;
        }
    }
    return pandulam;
}
int main()
{
    char s[1001];
    scanf("%s", s);
    int condiction = is_palindrome(s);
    if (condiction == 0)
    {
        printf("Not Palindrome");
    }
    else
    {
        printf("Palindrome");
    }

    return 0;
}