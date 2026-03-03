/*
✅ Adjacency Matrix:
গ্রাফকে 2D array দিয়ে সংরক্ষণ করা হয়।
যদি দুইটি node এর মধ্যে edge থাকে তাহলে 1 বসে,
না থাকলে 0 থাকে।

Undirected Graph হলে:
(r,c) তে 1 বসালে (c,r) তেও 1 বসাতে হয়।
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    node = মোট কয়টা vertex আছে
    edge = মোট কয়টা connection আছে
    */
    int node, edge;
    cin >> node >> edge;

    /*
    Adjacency Matrix তৈরি
    এখানে row = node
    column = node
    কারণ matrix সবসময় square হয় (node × node)
    */
    int adj_mat[node][node];

    /*
    প্রথমে পুরো matrix 0 দিয়ে initialize করি . মানে শুরুতে কোন node কারো সাথে connected না
    */
    /*  for (int i = 0; i < node; i++)
     {
         for (int j = 0; j < node; j++)
         {

             adj_mat[i][j] = 0;
         }
     } */
    // short cut
    memset(adj_mat, 0, sizeof(adj_mat));

    /*
    এখন edge অনুযায়ী connection বসাবো . যতগুলো edge আছে ততবার ইনপুট নিবো
    */
    for (int i = 0; i < edge; i++)
    {
        int r, c;
        cin >> r >> c;

        /*
        r এবং c এর মধ্যে connection আছে , তাই matrix[r][c] = 1 . যেহেতু এটা Undirected Graph . তাই matrix[c][r] = 1 ও হবে
        */
        adj_mat[r][c] = 1;
        adj_mat[c][r] = 1;
    }

    /*
    এখন চাইলে নিজের সাথে নিজের connection (self loop). দেখানোর জন্য diagonal এ 1 বসাতে পারি . মানে i == j হলে 1
    */
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            if (i == j)
                adj_mat[i][j] = 1;
        }
    }

    /*
    এখন পুরো adjacency matrix print করবো
    */
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Example Input:
5 5
0 1
0 2
3 0
1 3
3 4
*/