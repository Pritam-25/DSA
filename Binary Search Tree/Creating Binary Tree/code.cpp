#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;

    Node(int value)
    {
        data = value;
        right = left = NULL;
    }
};


Node* insert(Node* root, int target){
    if(!root){
        Node* temp = new Node(target);
        return temp;
    }

    if(target > root->data)
        root->right = insert(root->right, target);
    else 
        root->left = insert(root->left, target);

    return root;
}

void inOrder(Node* root){
    if(!root) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    Node* root = NULL;
    
    for (int i = 0; i < 10; i++)
    {
        root = insert(root, arr[i]);
    }
    
    // Traversal
    inOrder(root);

    return 0;
}

//* output:   1 2 3 5 6 11 14 17 18 20 