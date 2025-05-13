#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int data, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        Node *newNode = new Node(data);
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 1; temp != NULL && i < position - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFront()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int position)
    {
        if (head == NULL || position < 1)
        {
            cout << "Invalid position or list is empty!" << endl;
            return;
        }
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        for (int i = 1; temp != NULL && i < position; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, data, position;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Front\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            list.insertFront(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            list.insertEnd(data);
            break;
        case 3:
            cout << "Enter data and position: ";
            cin >> data >> position;
            list.insertAtPosition(data, position);
            break;
        case 4:
            list.deleteFront();
            break;
        case 5:
            list.deleteEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            list.deleteAtPosition(position);
            break;
        case 7:
            list.display();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
