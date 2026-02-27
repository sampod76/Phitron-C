
#include <stdio.h>
#include <string.h>
int main()
{

    char a[100], b[100];
    scanf("%s", &a);
    scanf("%s", &b);

    /*
            int i = 0;
            while (1)
            {
                if (a[i] == '\0' && b[i] == '\0')
                {
                    printf("%s", "equal");
                    break;
                }
                else if (a[i] == '\0')
                {
                    printf("%s", a);
                    break;
                }
                else if (b[i] == '\0')
                {
                    printf("%s", b);
                    break;
                }
                else if (a[i] < b[i])
                {
                    printf("%s", a);
                    break;
                }
                else if (a[i] > b[i])
                {
                    printf("%s", b);
                    break;
                }
                else if (a[i] == b[i])
                {
                    i++;
                }
    }
    */

    //  short way
    int check = strcmp(a, b);

    if (check == 0)
    {
        printf("%s", a);
    }
    else if (check < 0)
    {
        printf("%s", a);
    }
    else
    {
        printf("%s", b);
    }

    return 0;
}