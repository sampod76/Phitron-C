#include <stdio.h>

int main()
{
     int n;
     scanf("%d", &n);

     int a[n];

     for (int i = 0; i < n; i++)
     {
          scanf("%d", &a[i]);
     }

     for (int i = 0; i < n - 1; i++) // n-1 -কারন শেষে যেটা থাকবে ওটা চেক করার দরকার নেই ,ওটার শেষে  তো আর কেউ নেই
     {
          // ! প্রথম কথা হচ্ছে প্রজেক্টর ঠিকমতো রান করলে আউটপুট দেখলেই visual বুঝে ফেলবেন
          // এখানে মূলত যা হয় তা হলো—প্রতিবার লুপ চলার সময় আমরা বর্তমান ইনডেক্স থেকে শুরু করে তার ডান পাশের সব ইন্ডেক্সের মানগুলোর সাথে তুলনা করি। লক্ষ্য থাকে বর্তমান ইনডেক্সে সবচেয়ে ছোট মানটি বসানো।

          // প্রথমবার যখন লুপ চলে তখন i = 0 থাকে।
          // অর্থাৎ ০ নম্বর ইন্ডেক্সে পুরো অ্যারের মধ্যে সবচেয়ে ছোট মান বসবে।
          // তাই ০ নম্বর ইন্ডেক্স তার ডান পাশে থাকা সব ইন্ডেক্সের সাথে নিজের মানটির তুলনা করে।
          // যখনই তার চেয়ে ছোট কোনো মান পায়, তখন সেটিকে নিজের স্থানে বসায় এবং নিজের মানটি সেখানে পাঠায় (swap)।

          // পরেরবার যখন লুপ চলে তখন i = 1 থাকে।
          // এবার ১ নম্বর ইন্ডেক্স তার ডান পাশের সব মানের সাথে নিজের মানের তুলনা করে।
          // নিজের চেয়ে ছোট কোনো মান পেলে সেই মানটিকে স্থানান্তর করে নিজের স্থানে বসানো হয়।

          // এভাবে প্রতি ধাপে অ্যারের একটি করে অবস্থান সঠিকভাবে সাজানো হয়,
          // এবং পুরো অ্যারে ascending order-এ sort হয়ে যায়।

          printf("\n\n------------Global loop start %d bar -------\n\n", i + 1);
          for (int j = i + 1; j < n; j++)
          {
               printf("     Comparing a[%d] = %d with a[%d] = %d ", i, a[i], j, a[j]);
               if (a[i] > a[j]) // ✅ যদি ডান পাশে ছোট মান পাওয়া যায় → swap
               {

                    printf("✅ Smaller found! Swapping %d <-> %d", a[i], a[j]);
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
               }
               printf("\n");
               for (int k = 0; k < n; k++)
               {
                    printf("%d ", a[k]);
               }

               printf("\n");
          }
     }
     printf("\n\n------ ✅ Final Sorted Output (ASC) ------\n");
     for (int i = 0; i < n; i++)
     {
          printf("%d,", a[i]);
     }

     return 0;
}

/*
input:
5
5 2 6 3 1



------------Global loop start 1 bar -------

     Comparing a[0] = 5 with a[1] = 2 ✅ Smaller found! Swapping 5 <-> 2
2 5 6 3 1
     Comparing a[0] = 2 with a[2] = 6
2 5 6 3 1
     Comparing a[0] = 2 with a[3] = 3
2 5 6 3 1
     Comparing a[0] = 2 with a[4] = 1 ✅ Smaller found! Swapping 2 <-> 1
1 5 6 3 2


------------Global loop start 2 bar -------

     Comparing a[1] = 5 with a[2] = 6
1 5 6 3 2
     Comparing a[1] = 5 with a[3] = 3 ✅ Smaller found! Swapping 5 <-> 3
1 3 6 5 2
     Comparing a[1] = 3 with a[4] = 2 ✅ Smaller found! Swapping 3 <-> 2
1 2 6 5 3


------------Global loop start 3 bar -------

     Comparing a[2] = 6 with a[3] = 5 ✅ Smaller found! Swapping 6 <-> 5
1 2 5 6 3
     Comparing a[2] = 5 with a[4] = 3 ✅ Smaller found! Swapping 5 <-> 3
1 2 3 6 5


------------Global loop start 4 bar -------

     Comparing a[3] = 6 with a[4] = 5 ✅ Smaller found! Swapping 6 <-> 5
1 2 3 5 6


------ ✅ Final Sorted Output (ASC) ------
1,2,3,5,6,
*/