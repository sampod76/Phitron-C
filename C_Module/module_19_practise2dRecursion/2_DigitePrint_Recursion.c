
#include <stdio.h>

/*
 void convertNumberRec(int n)
{
    if (n == 0)
    {
        return;
    }
    int iNumber;
    scanf("%d", &iNumber);
    while (iNumber > 0)
    {
        printf("%d ", iNumber % 10);
        iNumber = iNumber / 10;
    }
    printf("\n");
    convertNumberRec(n - 1);
}
    //
output:
6 2 1
9 3
6 5 4 3 2 1
*/

/* // input
3
126
39
123456
---
1 2 6
3 9
1 2 3 4 5 6

*/
void convertNumberRec(int n)
{
    if (n == 0)
    {
        return;
    }

    convertNumberRec(n / 10);
    int last = n % 10;
    printf("%d ", last);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        // printf("%d", n);
        if (n == 0) // wen n
        {
            printf("%d", n);
        }
        else
        {

            convertNumberRec(n);
        }
        printf("\n");
    }
    return 0;
}
/* // or --> array solution

void convertNumberRec(int n)
{
    if (n == 0)
    {
        return;
    }
    int iNumber;
    scanf("%d", &iNumber);
    int digits[20];
    int count = 0;
    if (iNumber == 0)
    {
        printf("%d", 0);
    }
    else
    {

        while (iNumber > 0)
        {
            digits[count] = iNumber % 10;
            // printf("%d ", iNumber % 10);
            iNumber = iNumber / 10;
            count++;
        }
        for (int i = count - 1; i >= 0; i--)
        {
            printf("%d ", digits[i]);
        }
    }

    printf("\n");
    convertNumberRec(n - 1);
}
int main()
{

    int n;
    scanf("%d", &n);
    // printf("%d", n);
    convertNumberRec(n);
    return 0;
}

*/