#include <bits/stdc++.h>
using namespace std;

/*
 Node class:
 প্রতিটি Node এর মধ্যে থাকবে
 1) value → ডাটার মান
 2) next  → পরের Node এর address
*/
class Node
{
public:
    int value;  // Node এর ডাটা
    Node *next; // পরবর্তী Node এর pointer

    // Constructor: নতুন Node তৈরি করার সময় value সেট করবে
    Node(int val)
    {
        this->value = val; // Node এর value সেট করা
        this->next = NULL; // শুরুতে next = NULL (কোনো Node নাই)
    }
};

/*
 insert_at_head:
 Linked List এর একদম শুরুতে (head এ) নতুন Node যোগ করে
 Node *&head → reference ব্যবহার করা হয়েছে যাতে আসল head পরিবর্তন হয়
*/
void insert_at_head(Node *&head, int value)
{
    // 1. নতুন Node তৈরি করা
    Node *newNode = new Node(value);
    // 2. নতুন Node এর next এ পুরোনো head এর address বসানো // newNode → old head → rest of list
    newNode->next = head;
    // 3. head কে নতুন Node এ point করানো   // এখন নতুন Node ই head
    head = newNode;
}

/*
 print_linked_list:
 পুরো Linked List প্রিন্ট করে
*/
void print_linked_list(Node *head)
{
    // temp pointer দিয়ে list traverse করবো
    Node *temp = head;
    // যতক্ষণ temp NULL না হবে, ততক্ষণ loop চলবে
    while (temp != NULL)
    {
        cout << temp->value << endl; // বর্তমান Node এর value প্রিন্ট
        temp = temp->next;           // পরের Node এ চলে যাওয়া
    }
}

int main()
{
    /*
      এখানে আমরা প্রথমে manually একটি linked list বানাচ্ছি:

      head → 10 → 50 → 20 → NULL
    */

    Node *head = new Node(10);
    Node *a = new Node(50);
    Node *b = new Node(20);

    // link তৈরি
    head->next = a; // 10 → 50
    a->next = b;    // 50 → 20

    /*
      এখন insert_at_head(head, 100) কল করলে list হবে:
      100 → 10 → 50 → 20 → NULL
    */
    insert_at_head(head, 100);
    insert_at_head(head, 500);

    // পুরো linked list প্রিন্ট
    print_linked_list(head);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    Node *previewsNode;
    int value;
    Node *next;
    Node(int value)
    {
        previewsNode = NULL;
        this->value = value;
        next = NULL;
    }
};