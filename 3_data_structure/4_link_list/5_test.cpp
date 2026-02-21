#include <bits/stdc++.h>
using namespace std;

// Node class: Linked List এর প্রতিটি ঘর (node) বোঝায়
class Node
{
public:
    int value;  // ডাটার মান রাখবে
    Node *next; // পরের node এর address রাখবে

    // Constructor: যখন নতুন node বানানো হবে তখন value সেট হবে
    Node(int val)
    {
        this->value = val; // node এর value সেট করা
        this->next = NULL; // শুরুতে কোনো node এর সাথে যুক্ত না
    }
};

int main()
{
    // তিনটি node তৈরি করা
    Node *head = new Node(50); // প্রথম node, এটাকেই Head বলা হয়
    Node *a = new Node(80);    // দ্বিতীয় node
    Node *b = new Node(40);    // তৃতীয় node

    // Node গুলোকে একে অপরের সাথে যুক্ত করা
    head->next = a; // head → a
    a->next = b;    // a → b
    // b->next = NULL (constructor থেকেই NULL আছে)

    /*
        এখন Linked List এর structure:
        head(50) → a(80) → b(40) → NULL
    */

    // Traversal করার জন্য temp pointer ব্যবহার
    Node *temp = head; // temp প্রথমে head কে point করবে

    // পুরো linked list একবার print করা
    while (temp != NULL)
    {
        cout << temp->value << endl; // বর্তমান node এর value print
        temp = temp->next;           // পরের node এ চলে যাওয়া
    }

    // আবার traversal করার জন্য নতুন pointer
    Node *temp2 = head;

    // আবার পুরো linked list print করা
    while (temp2 != NULL)
    {
        cout << temp2->value << endl; // বর্তমান node এর value print
        temp2 = temp2->next;          // পরের node এ চলে যাওয়া
    }

    return 0;
}
