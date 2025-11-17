
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int starSmall = 1;
    // small to big
    for (int i = 1; i <= n; i++) // এটা মূলত কয়টা লাইন প্রিন্ট হবে সেটাই = n
    {
        for (int j = 1; j <= starSmall; j++) // আর এটা হচ্ছে প্রতি লাইনে কয়টা করে * প্রিন্ট হবে সেটা
        {
            printf("*");
        }
        printf("\n");
        starSmall++;
    }
    printf("\n");
    int startBig = n;
    // big to small
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= startBig; j++)
        {
            printf("*");
        }
        printf("\n");
        startBig--;
    }
    return 0;
}
// output starSmall
/*
 *
 **
 ***
 ****
 *****
 */

// output startBig

/*

*****
****
***
**
*

*/