#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(const string &infix)
{
    stack<char> s;
    string postfix;

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop(); // Remove '('
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    int choice;
    string infix;

    while (true)
    {
        cout << "\n--- Infix to Postfix Converter ---\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear newline from buffer

        switch (choice)
        {
        case 1:
            cout << "Enter infix expression: ";
            getline(cin, infix);

            cout << "Postfix expression: " << infixToPostfix(infix) << endl;
            break;

        case 2:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
