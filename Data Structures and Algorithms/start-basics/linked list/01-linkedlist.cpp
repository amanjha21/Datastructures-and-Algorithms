#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = 0;
    }
};
class Linkedlist
{
private:
    Node *head;

public:
    Linkedlist()
    {
        head = 0;
    }
    void insertAtTail(int x)
    {
        Node *p;
        p = head;
        if (!head)
        {
            head = new Node(x);
            return;
        }
        while (p->next)
            p = p->next;
        p->next = new Node(x);
        p = p->next;
        p->next = 0;
    }
    void display()
    {
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    void insertFromArray(int A[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            insertAtTail(A[i]);
        }
    }
    // void recursiveDisplay(Node *p = head)
    // {
    //     if (p)
    //     {
    //         return recursiveDisplay(p->next);
    //         cout << p->data << " ";
    //     }
    //     return;
    // }
    void insertAt(int n, int x)
    {
        Node *p, *temp;
        p = head;
        if (!n)
        {
            temp = p;
            head = new Node(x);
            head->next = temp;
            return;
        }
        for (int i = 0; i < n - 1; i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = new Node(x);
        p = p->next;
        p->next = temp;
    }
    void insertFromArrayAt(int A[], int l, int n)
    {
        for (int i = 0; i < l; i++)
        {
            insertAt(n, A[i]);
            n++;
        }
    }
    void removeAt(int n, int m = 1)
    {
        Node *p, *temp;
        p = head;
        for (int i = 0; i < n - 1; i++)
        {
            p = p->next;
        }
        temp = p;
        for (int j = 0; j < m; j++)
        {
            p = p->next;
        }
        temp->next = p->next;
    }
    void get(int n)
    {
        Node *p = head;
        for (int i = 0; i < n; i++)
            p = p->next;
        cout << p->data;
    }
};
int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    Linkedlist A;      //linkedlist oject using class linkedlist class
    A.insertAtTail(2); //insert at end of linked list
    A.insertAtTail(3);
    A.insertFromArray(x, 5); //insert values from arrary at end of list
    A.insertAt(0, 100);      // insert element at particular index
    A.display();             // display all the elements of linkedlist
    cout << endl;
    A.removeAt(4, 2); //remove no. of element/s from particular index
    A.display();
    cout << endl;
    A.get(2); //get or display element at particular index
    // A.recursiveDisplay();
}