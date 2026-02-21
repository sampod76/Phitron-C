#include <stdio.h>

// ✅ fun() ফাংশন: দুইটা integer pointer নিয়ে মান স্বাপ করবে
void fun(int *x, int *y)
{
    // *x মানে হচ্ছে x pointer যেই ভ্যারিয়েবলের দিকে ইঙ্গিত করছে তার VALUE
    // temp এ *x এর মান রাখলাম (ধরি x = 10 হলে temp = 10)
    int temp = *x;

    // ✅ এবার *x এর জায়গায় *y এর মান বসালাম (ধরি y = 20 ⇒ *x = 20)
    *x = *y;

    // ✅ এবার *y এর জায়গায় temp বসালাম (আগের x এর মান → 10)
    *y = temp;

    // এভাবে দুইটা ভ্যারিয়েবলের মান swap হয়ে গেলো
}

int main()
{
    int x, y;

    // ✅ ইউজারের কাছ থেকে মান ইনপুট নিই
    scanf("%d %d", &x, &y);

    // ✅ x এবং y এর ADDRESS পাঠাচ্ছি fun() এর ভিতরে
    fun(&x, &y);

    // ✅ swap হওয়ার পর মান প্রিন্ট করছি
    printf("%d %d", x, y);

    return 0;
}
