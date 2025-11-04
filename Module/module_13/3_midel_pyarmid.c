
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int starSmail = 1;
    int spaceSmail = n - 1; // first time default space
    // small to big
    for (int i = 1; i <= n; i++) // এটা মূলত কয়টা লাইন প্রিন্ট হবে সেটাই = n
    {
        for (int j = 1; j <= spaceSmail; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= starSmail; j++) // আর এটা হচ্ছে প্রতি লাইনে কয়টা করে * প্রিন্ট হবে সেটা
        {
            printf("*");
        }
        printf("\n");
        starSmail += 2;
        spaceSmail--;
    }
    printf("\n");
    int startBig = n * 2 - 1;
    int spaceBig = 0;
    // big to small
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= spaceBig; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= startBig; j++)
        {
            printf("*");
        }
        printf("\n");
        startBig -= 2;
        spaceBig++;
    }
    return 0;
}
// output starSmail
/*
    *
   ***
  *****
 *******
*********


 */

// output startBig

/*

*********
 *******
  *****
   ***
    *

*/