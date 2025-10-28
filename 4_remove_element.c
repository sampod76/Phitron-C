
#include <stdio.h>

int main()
{

    int n; // 5
    scanf("%d", &n);
    int a[n]; // 10 20 11 12 13
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        // printf("%d --", a[i]);
    }
    int idx; // 1
    scanf("%d", &idx);
    for (int i = idx; i < n - 1; i++) // n - 1 -->আমরা চাই একটা এলিমেন্ট রিমুভ করতে। যখন একটা এলিমেন্ট রিমুভ করা হবে, তখন শেষের ঘরটা ফাঁকা থেকে যাবে। তাই ওই ঘর পর্যন্ত loop কোনো দরকার নেই। সেই কারণেই আমরা এক ঘর কম loop চালিয়েছি।
    {
        a[i] = a[i + 1];
        // printf("%d ", a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]); // 10 11 12 13 13  --> because last element is empty
    }
    printf("\nsolution-> ");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]); // 10 11 12 13
    }

    return 0;
}