#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};
void insert_into_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode; // old tail in add next = newNode address
    tail = newNode;       // old tail to replace newNode
}
void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void remove_duplicate(Node *&head, Node *&tail)
{
    Node *current = head;
    // current হচ্ছে main pointer
    // যাকে ধরে আমরা বাকি list এর সাথে compare করবো

    while (current != NULL)
    {
        Node *prev = current;
        // prev রাখছি runner এর আগের node ট্র্যাক করার জন্য
        // delete করার সময় link ঠিক রাখতে এটা দরকার

        Node *runner = current->next;
        // runner দিয়ে current এর পরের সব node ঘুরে দেখবো

        while (runner != NULL)
        {
            if (runner->value == current->value)
            {
                // যদি current আর runner এর value একই হয়
                // তাহলে এটা duplicate node

                Node *deleteNode = runner;
                // যেই node টা delete করবো, সেটার address রেখে দিলাম

                prev->next = runner->next;
                // link rewrite:
                // prev -> next এখন runner এর পরের node কে point করবে
                // middle node মানে duplicate node skip হয়ে গেল

                runner = runner->next;
                // runner কে সামনে সরিয়ে দিলাম

                if (deleteNode == tail)
                {
                    // যদি delete হওয়া node টা tail হয়
                    // তাহলে tail কে update করতে হবে
                    tail = prev;
                }

                delete deleteNode;
                // memory থেকে duplicate node delete
            }
            else
            {
                // duplicate না হলে শুধু সামনে এগোই
                prev = runner;
                runner = runner->next;
            }
        }

        current = current->next;
        // current কে এক ধাপ সামনে নিলাম
        // এবার পরের value নিয়ে same process হবে
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1) // bec
        {
            break;
        }
        insert_into_tail(head, tail, value);
    }
    remove_duplicate(head, tail);
    print_linked_list(head);

    return 0;
}