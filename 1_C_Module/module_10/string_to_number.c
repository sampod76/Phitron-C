
#include <stdio.h>
#include <string.h>

int main()
{
    char ch[1000001];
    scanf("%s", &ch);
    int length = strlen(ch);
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        // sum += ch[i] - 48 // '0' ASCII value is 48  | ch[i] when get a number character it will return its ASCII value example '1' will return 49 so 49 - 48 = 1
        sum += ch[i] - '0';
    }
    printf("%d", sum);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main()
{
    char a[101];
    // ভাই & দিতে ভুলে গেছো ,এটা তো কাজ করবে না
    scanf("%s", a);
    printf("%s", a);
    return 0;
}

#include <stdio.h>

int main()
{
    char a[101];
    // first way
    scanf("%s", &a);
    // secound way
    scanf("%s", &a[0]);
    // third way
    scanf("%s", a);
    //
    printf("%s", a);

    return 0;
}
