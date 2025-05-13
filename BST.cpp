#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void mirror(Node *root)
{
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

void inorderNonRecursive(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderNonRecursive(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *node = s.top();
        s.pop();
        cout << node->data << " ";
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}

void postorderNonRecursive(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    Node *root = NULL;
    int choice, value;

    do
    {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Recursive Inorder Traversal\n";
        cout << "4. Recursive Preorder Traversal\n";
        cout << "5. Recursive Postorder Traversal\n";
        cout << "6. Non-Recursive Inorder Traversal\n";
        cout << "7. Non-Recursive Preorder Traversal\n";
        cout << "8. Non-Recursive Postorder Traversal\n";
        cout << "9. Count Nodes\n";
        cout << "10. Mirror Image\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "Recursive Inorder: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Recursive Preorder: ";
            preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Recursive Postorder: ";
            postorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Non-Recursive Inorder: ";
            inorderNonRecursive(root);
            cout << endl;
            break;
        case 7:
            cout << "Non-Recursive Preorder: ";
            preorderNonRecursive(root);
            cout << endl;
            break;
        case 8:
            cout << "Non-Recursive Postorder: ";
            postorderNonRecursive(root);
            cout << endl;
            break;
        case 9:
            cout << "Total nodes: " << countNodes(root) << endl;
            break;
        case 10:
            mirror(root);
            cout << "Tree mirrored successfully.\n";
            break;
        case 11:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 11);

    return 0;
}
