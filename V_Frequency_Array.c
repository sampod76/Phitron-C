
#include <stdio.h>

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // int freArray[m + 1] ={0};
    // it is not possible because this si dynamic array length
    // int freArray[m + 1];
    // for (int i = 0; i <= m; i++)
    // {
    //     freArray[i] = 0;
    // }
    int freArray[100001] = {0};
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        freArray[val]++;
    }
    // First line contains two numbers N, M(1≤ N ≤ 105,1 ≤ M ≤ 105).
    // Second line contains N numbers (1≤Ai≤M).
    // এখানে প্রশ্ন কোথাও ০ থেকে শুরু করা হয়নি যার কারণে আমাকে print করার সময় ০ বাদ  দিয়া print করতে হবে
    for (int i = 1; i <= m; i++)
    {

        printf("%d\n", freArray[i]);

        // if (freArray[i])
        // {
        //     printf("%d\n", freArray[i]);
        // }
    }

    return 0;
}