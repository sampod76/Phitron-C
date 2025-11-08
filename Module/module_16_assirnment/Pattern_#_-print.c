
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int startPrint = 1;
    int space = n - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= startPrint; j++)
        {
            if (i % 2 == 0)
            {
                printf("-");
            }
            else
            {
                printf("#");
            }
        }
        startPrint += 2;
        space--;
        printf("\n");
    }
    // reveries
    startPrint = 2 * n - 3; //
    space = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= startPrint; j++)
        {
            if ((n + i) % 2 == 0) // n এখানে check korta hoba এভাবে করার কারণ হচ্ছে আমাদের এখানে চেক করতে হবে n পরে অর্থাৎ n=5 সমন যদি পাস হয় ৬ নাম্বার লাইন থেকে নতুন কন্ডিশন
            {
                printf("-");
            }
            else
            {
                printf("#");
            }
        }
        startPrint -= 2;
        space++;
        printf("\n");
    }

    return 0;
}

/*
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int startPrint = 1;
    int space = n - 1;
    int lastPrint = '-';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= startPrint; j++)
        {
            if (lastPrint == '-')
            {
                printf("#");
            }
            else
            {
                printf("-");
            }
        }
        if (lastPrint == '-')
        {
            lastPrint = '#';
        }
        else
        {
            lastPrint = '-';
        }

        startPrint += 2;
        space--;
        printf("\n");
    }
    //
    int startBigPrint = 2 * n - 3;
    int spaceBig = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= spaceBig; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= startBigPrint; j++)
        {
            if (lastPrint == '-')
            {
                printf("#");
            }
            else
            {
                printf("-");
            }
        }
        if (lastPrint == '-')
        {
            lastPrint = '#';
        }
        else
        {
            lastPrint = '-';
        }

        startBigPrint -= 2;
        spaceBig++;
        printf("\n");
    }

    return 0;
}

*/