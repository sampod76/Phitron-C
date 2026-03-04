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
    totalNodes = মোট কয়টা vertex / node আছে
    totalEdges = মোট কয়টা connection / edge আছে
    */
    int totalNodes, totalEdges;
    cin >> totalNodes >> totalEdges;

    /*
    Adjacency Matrix তৈরি

    এখানে:
    row = node
    column = node

    কারণ adjacency matrix সবসময় square হয়
    size = node × node
    */
    int adjacencyMatrix[totalNodes][totalNodes];

    /*
    প্রথমে পুরো matrix 0 দিয়ে initialize করি

    মানে শুরুতে ধরে নিচ্ছি
    কোন node কারো সাথে connected না
    */
    /*
    for (int row = 0; row < totalNodes; row++)
    {
        for (int col = 0; col < totalNodes; col++)
        {
            adjacencyMatrix[row][col] = 0;
        }
    }
    */

    // shortcut method (সব value 0 করা)
    memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));

    /*
    এখন edge অনুযায়ী connection বসাবো | যতগুলো edge আছে ততবার input নিবো
    */
    while (totalEdges--)
    {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;

        /*
        sourceNode এবং destinationNode এর মধ্যে connection আছে

        তাই matrix[source][destination] = 1

        যেহেতু এটা Undirected Graph
        তাই reverse connection ও থাকবে
        matrix[destination][source] = 1
        */
        adjacencyMatrix[sourceNode][destinationNode] = 1;
        adjacencyMatrix[destinationNode][sourceNode] = 1;
    }

    /*
    এখন চাইলে নিজের সাথে নিজের connection (self loop)
    দেখানোর জন্য diagonal এ 1 বসাতে পারি

    অর্থাৎ:
    row == col হলে matrix[i][j] = 1
    */
    for (int row = 0; row < totalNodes; row++)
    {
        for (int col = 0; col < totalNodes; col++)
        {
            if (row == col)
                adjacencyMatrix[row][col] = 1;
        }
    }

    /*
    এখন পুরো adjacency matrix print করবো
    */
    for (int row = 0; row < totalNodes; row++)
    {
        for (int col = 0; col < totalNodes; col++)
        {
            cout << adjacencyMatrix[row][col] << " ";
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