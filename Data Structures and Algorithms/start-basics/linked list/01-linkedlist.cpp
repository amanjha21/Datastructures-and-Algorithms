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
    code
};
class Linkedlist
{
public:
    Node *head;

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
        cout << endl;
    }
    void insertFromArray(int A[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            insertAtTail(A[i]);
        }
    }
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
    int remove(int n)
    {
        Node *p, *q;
        int x;
        p = head;
        q = 0;
        if (n == 0)
        {
            head = p->next;
            x = p->data;
            delete p;
            return x;
        }
        for (int i = 0; i < n; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
    void get(int n)
    {
        Node *p = head;
        for (int i = 0; i < n; i++)
            p = p->next;
        cout << p->data << endl;
    }
    void count()
    {
        Node *p = head;
        int count = 0;
        while (p)
        {
            count++;
            p = p->next;
        }
        cout << count << endl;
    }
    void sumAll()
    {
        Node *p = head;
        int sum = 0;
        while (p)
        {
            sum += p->data;
            p = p->next;
        }
        cout << sum << endl;
    }
    void max()
    {
        if (!head)
            return;
        Node *p = head;
        int max = p->data;
        while (p)
        {
            if (p->data > max)
                max = p->data;
            p = p->next;
        }
        cout << max << endl;
    }
    void min()
    {
        if (!head)
            return;
        Node *p = head;
        int min = p->data;
        while (p)
        {
            if (p->data < min)
                min = p->data;
            p = p->next;
        }
        cout << min;
    }
    void search(int x)
    {
        if (!head)
            return;
        Node *p, *q = 0, *temp;
        p = head;
        if (p->data == x)
        {
            cout << p << endl;
            q = p;
            p = p->next;
        }
        while (p)
        {
            if (p->data == x)
            {
                cout << p << endl;
                q->next = p->next;
                temp = head;
                head = p;
                p->next = temp;
                p = q;
            }
            q = p;
            p = p->next;
        }
    }
    bool isSorted()
    {
        Node *p, *q;
        p = head;
        q = head;
        while (p)
        {
            if (q->data > p->data)
            {
                return false;
            }
            q = p;
            p = p->next;
        }
        return true;
    }
    void removeDuplicates()
    {
        Node *p, *q;
        p = head;
        q = p->next;
        while (q)
        {
            if (p->data == q->data)
            {
                q = q->next;
                delete p->next;
                p->next = q;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
    }
};
void recursiveDisplay(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        recursiveDisplay(p->next);
    }
}
int main()
{
    int x[5] = {-2, -1, 4, 4, 5};
    Linkedlist A; // linkedlist oject using class linkedlist class
    // A.insertAtTail(2); //insert at end of linked list
    // A.insertAtTail(3);
    A.insertFromArray(x, 5); // insert values from arrary at end of list
    // A.insertAt(0, 100);      // insert element at particular index
    A.display(); // display all the elements of linkedlist
    // cout << A.remove(0); //remove single element from index
    // A.display();
    // A.get(2); //get or display element at particular index
    // recursiveDisplay(A.head); //recursive display all elements of linkedlist
    // cout << endl;
    // A.count();  //count number of nodes in linkedlist
    // A.sumAll(); //sum all elements of linkedlist
    // A.max(); //max element in linked list
    // A.min(); //min element in linked list
    // A.search(3); //search and return address of element in linked list and element to 1st node
    A.removeDuplicates();
    A.display();
    // if (A.isSorted())
    // {
    //     cout << "yes";
    // }
    // else
    // {
    //     cout << "no";
    // };
}
