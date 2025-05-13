#include <iostream>
using namespace std;

// Recursive function to print Fibonacci series up to n terms
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative (non-recursive) function to print Fibonacci series
void fibonacciNonRecursive(int n)
{
    int a = 0, b = 1, c;
    if (n >= 1)
        cout << a << " ";
    if (n >= 2)
        cout << b << " ";
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

int main()
{
    int choice, n;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Fibonacci Series (Non-Recursive)\n";
        cout << "2. Fibonacci Series (Recursive)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of terms: ";
            cin >> n;
            cout << "Fibonacci Series (Non-Recursive): ";
            fibonacciNonRecursive(n);
            break;

        case 2:
            cout << "Enter the number of terms: ";
            cin >> n;
            cout << "Fibonacci Series (Recursive): ";
            for (int i = 0; i < n; i++)
            {
                cout << fibonacciRecursive(i) << " ";
            }
            cout << endl;
            break;

        case 3:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
