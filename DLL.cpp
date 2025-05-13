#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertNodes(int count)
    {
        int value;
        for (int i = 0; i < count; i++)
        {
            cout << "Enter value " << i + 1 << " to insert: ";
            cin >> value;
            Node *newNode = new Node(value);
            if (!head)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;
                while (temp->next)
                    temp = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
            }
        }
    }

    void insertAfterPosition(int position, int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            cout << "The list is empty. Inserting at the beginning.\n";
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 1; temp && i < position; i++)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Position exceeds the list length.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;

        cout << "Inserted " << value << " after position " << position << ".\n";
    }

    void deleteNode(int value)
    {
        if (!head)
        {
            cout << "The DLL is empty. Cannot delete.\n";
            return;
        }

        Node *temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp)
        {
            cout << "Value not found in the list.\n";
            return;
        }

        if (temp == head)
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Value deleted successfully.\n";
    }

    void deleteAtPosition(int position)
    {
        if (!head)
        {
            cout << "The DLL is empty.\n";
            return;
        }

        Node *temp = head;
        for (int i = 1; temp && i < position; i++)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Position out of range.\n";
            return;
        }

        if (temp == head)
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Node at position " << position << " deleted.\n";
    }

    void findEvenNodes() const
    {
        if (!head)
        {
            cout << "The DLL is empty.\n";
            return;
        }

        Node *temp = head;
        int nodeNo = 1;
        bool found = false;
        cout << "Even numbers in the list:\n";

        while (temp)
        {
            if (temp->data % 2 == 0)
            {
                cout << "Node " << nodeNo << ": " << temp->data << "\n";
                found = true;
            }
            temp = temp->next;
            nodeNo++;
        }

        if (!found)
            cout << "No even numbers found in the list.\n";
    }

    void printList() const
    {
        if (!head)
        {
            cout << "The DLL is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "Doubly linked list: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    DoublyLinkedList dll;
    int choice, value, count, position;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Nodes\n";
        cout << "2. Insert After Position\n";
        cout << "3. Display List\n";
        cout << "4. Find Even Numbers\n";
        cout << "5. Delete Node\n";
        cout << "6. Delete At Position\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter how many values to insert: ";
            cin >> count;
            dll.insertNodes(count);
            dll.printList();
            break;
        case 2:
            cout << "Enter position to insert after: ";
            cin >> position;
            cout << "Enter value to insert: ";
            cin >> value;
            dll.insertAfterPosition(position, value);
            dll.printList();
            break;
        case 3:
            dll.printList();
            break;
        case 4:
            dll.findEvenNodes();
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            dll.deleteNode(value);
            dll.printList();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            dll.deleteAtPosition(position);
            dll.printList();
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
}
