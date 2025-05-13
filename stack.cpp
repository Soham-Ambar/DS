#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

bool isMatchingParentheses(const string &exp)
{
    stack<char> s;
    for (char ch : exp)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s.empty();
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void infixToPostfix(const string &infix, string &postfix)
{
    stack<char> s;
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
                s.pop();
        }
        else
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
}

int evaluatePostfix(const string &postfix)
{
    stack<int> s;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    int choice;
    string exp, postfix;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Check Matching Parentheses\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter expression: ";
            getline(cin, exp);
            if (isMatchingParentheses(exp))
                cout << "Balanced Parentheses\n";
            else
                cout << "Unbalanced Parentheses\n";
            break;
        case 2:
            cout << "Enter infix expression: ";
            getline(cin, exp);
            postfix.clear();
            infixToPostfix(exp, postfix);
            cout << "Postfix Expression: " << postfix << endl;
            break;
        case 3:
            cout << "Enter postfix expression: ";
            getline(cin, exp);
            cout << "Evaluated Result: " << evaluatePostfix(exp) << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}