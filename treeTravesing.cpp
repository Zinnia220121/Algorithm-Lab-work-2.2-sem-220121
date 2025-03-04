#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Pre-order traversal
void preOrder(struct Node* root, vector<int>& preOrderArray)
{
    if (root == nullptr)
        return;
    preOrderArray.push_back(root->data);
    preOrder(root->left, preOrderArray);
    preOrder(root->right, preOrderArray);
}

// In-order traversal
void inOrder(struct Node* root, vector<int>& inOrderArray)
{
    if (root == nullptr)
        return;
    inOrder(root->left, inOrderArray);
    inOrderArray.push_back(root->data);
    inOrder(root->right, inOrderArray);
}

// Post-order traversal
void postOrder(struct Node* root, vector<int>& postOrderArray)
{
    if (root == nullptr)
        return;
    postOrder(root->left, postOrderArray);
    postOrder(root->right, postOrderArray);
    postOrderArray.push_back(root->data);
}

void postOrderPrint(struct Node* root)
{
    if (root == nullptr) return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout << root->data << " ";
}

void preOrderPrint(struct Node* root)
{
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> preOrderArray;
    vector<int> inOrderArray;
    vector<int> postOrderArray;

    preOrder(root, preOrderArray);
    inOrder(root, inOrderArray);
    postOrder(root, postOrderArray);

    // Print the pre-order array
    cout << "Pre-order traversal: ";
    for (int val : preOrderArray)
    {
        cout << val << " ";
    }
    cout << endl;

    // Print the in-order array
    cout << "In-order traversal: ";
    for (int val : inOrderArray)
    {
        cout << val << " ";
    }
    cout << endl;

    // Print the post-order array
    cout << "Post-order traversal: ";
    for (int val : postOrderArray)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}

