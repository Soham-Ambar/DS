#include <iostream>
using namespace std;

#define SIZE 5

int circularQueue[SIZE];
int rear = -1, front = -1;

bool isFull()
{
    return (rear + 1) % SIZE == front;
}

bool isEmpty()
{
    return front == -1 && rear == -1;
}

void enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is Full\n";
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }
    circularQueue[rear] = value;
}

int dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty.\n";
        return -1;
    }
    else if (front == rear)
    {
        int deq = circularQueue[front];
        front = rear = -1;
        return deq;
    }
    else
    {
        int deq = circularQueue[front];
        front = (front + 1) % SIZE;
        return deq;
    }
}

void displayQueue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Circular Queue: ";
    int i = front;
    while (true)
    {
        cout << circularQueue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

// Stack for reversal
#define MAX 5
int stack[MAX], top = -1;

bool isStackEmpty()
{
    return top == -1;
}

void push(int value)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if (isStackEmpty())
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack[top--];
}

// Auxiliary queue
int queue[MAX], frontQ = -1, rearQ = -1;

void enqueueQueue(int value)
{
    if (rearQ == MAX - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }
    if (frontQ == -1)
        frontQ = 0;
    queue[++rearQ] = value;
}

int dequeueQueue()
{
    if (frontQ == -1 || frontQ > rearQ)
    {
        cout << "Queue Underflow\n";
        return -1;
    }
    return queue[frontQ++];
}

void reverseStack()
{
    if (isStackEmpty())
    {
        cout << "Stack is Empty, Nothing to Reverse\n";
        return;
    }

    while (!isStackEmpty())
    {
        enqueueQueue(pop());
    }

    while (frontQ <= rearQ)
    {
        push(dequeueQueue());
    }
}

void displayStack()
{
    if (isStackEmpty())
    {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// Main menu
int main()
{
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Circular Queue Operations\n";
        cout << "2. Reverse Stack using Queue\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int queueChoice;
            do
            {
                cout << "\nCircular Queue Operations:\n";
                cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    enqueue(value);
                    break;
                case 2:
                    cout << "Dequeued: " << dequeue() << endl;
                    break;
                case 3:
                    displayQueue();
                    break;
                case 4:
                    cout << "Returning to Main Menu...\n";
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (queueChoice != 4);
            break;
        }

        case 2:
        {
            int stackChoice, n;
            do
            {
                cout << "\nStack Operations:\n";
                cout << "1. Enter elements\n2. Reverse Stack\n3. Display Stack\n4. Back to Main Menu\n";
                cout << "Enter choice: ";
                cin >> stackChoice;

                switch (stackChoice)
                {
                case 1:
                    cout << "Enter number of elements: ";
                    cin >> n;
                    cout << "Enter values to push: ";
                    for (int i = 0; i < n; i++)
                    {
                        cin >> value;
                        push(value);
                    }
                    break;
                case 2:
                    reverseStack();
                    cout << "Stack Reversed\n";
                    break;
                case 3:
                    displayStack();
                    break;
                case 4:
                    cout << "Returning to Main Menu...\n";
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (stackChoice != 4);
            break;
        }

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}
