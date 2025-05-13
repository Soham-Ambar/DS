#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{
    Node *head;
    Node *tail;

public:
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtFront(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (tail == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insertAtPos(int data, int Pos)
    {
        if (Pos < 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (Pos == 1)
        {
            insertAtFront(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *temp = head;
        for (int i = 0; temp != NULL && i < Pos - 2; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Index out of Bound" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main()
{
    Linkedlist l1;
    int a, value, Position;
    int i = 1;

    while (i)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at end\n";
        cout << "3. Display list\n";
        cout << "4. Insert At Position\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> a;

        switch (a)
        {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            l1.insertAtFront(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            l1.insertAtEnd(value);
            break;
        case 3:
            cout << "Linked List: ";
            l1.display();
            break;
        case 4:
            cout << "Enter Position: ";
            cin >> Position;
            cout << "Enter value to insert: ";
            cin >> value;
            l1.insertAtPos(value, Position);
            break;
        case 5:
            i = 0;
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
