
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int modifyN;
    if (n == 1)
    {
        modifyN = 6;
    }
    else
    { // এখানে একটা parttern দেখা যাচ্ছে n প্রত্যেকটা বিজোড় সংখ্যা হবে এবং এক ছাড়া বাকিদেরকে ভাগ করলে ভাগফল যেটা পাওয়া যায় ততটি লাইন বৃদ্ধি পায়
        int dividedRes = (n / 2);
        modifyN = 6 + dividedRes;
    }

    int star = 1;
    int space = modifyN - 1;
    for (int i = 1; i <= modifyN; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= star; j++)
        {
            printf("*");
        }

        star += 2;
        space--;
        printf("\n");
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= n; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}