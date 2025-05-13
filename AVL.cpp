#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

// Get height of a node
int getHeight(Node *node)
{
    if (!node)
        return 0;
    return node->height;
}

// Get balance factor
int getBalance(Node *node)
{
    if (!node)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Update height
void updateHeight(Node *node)
{
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotation
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert into AVL tree
Node *insert(Node *node, int key)
{
    if (!node)
        return new Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    updateHeight(node);
    int balance = getBalance(node);

    // Perform rotations
    if (balance > 1 && key < node->left->data) // Left Left
        return rightRotate(node);

    if (balance < -1 && key > node->right->data) // Right Right
        return leftRotate(node);

    if (balance > 1 && key > node->left->data)
    { // Left Right
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data)
    { // Right Left
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find node with minimum value
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete node
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with one or no child
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root)
        return root;

    updateHeight(root);
    int balance = getBalance(root);

    // Perform rotations
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Traversals
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    int choice, value;

    do
    {
        cout << "\nAVL Tree Menu:\n";
        cout << "1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n";
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
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
