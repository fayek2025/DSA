#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left ;
    Node* right ;
};

struct Node* createNode(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node*));

    if(newnode != NULL)
    {
        newnode -> data = data;
        newnode -> left = NULL;
        newnode -> right = NULL;
    }

    return newnode;
}

//MNode insertion
struct Node* insertNode(struct Node* root, int data)
{
    if(root == NULL)
    {
       return createNode(data);
    }

    else if(data > root -> data)
    {
       root -> right = insertNode(root->right , data);
    }
    else if(data < root -> data)
    {
       root-> left =   insertNode(root -> left , data);
    }

    return root;
}


void InorderTraverse(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    InorderTraverse(root->left);
    cout << root->data << " ";
    InorderTraverse(root -> right);
}


void PreorderTraverse(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    cout << root->data << " ";
    PreorderTraverse(root->left);
    PreorderTraverse(root->right);
}


void PostorderTraverse(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    PostorderTraverse(root->left);
    PostorderTraverse(root->right);
    cout << root-> data <<  " ";
}

struct Node* searchNode (struct Node* root , int key)
{
    if(root == NULL || root -> data == key)
    {
        return root;
    }

    if(root -> data < key)
    {
        return searchNode(root->right , key);
    }

    else if(root -> data > key)
    {
        return searchNode(root -> left , key);
    }

}


Node* deleteNode(Node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in the left subtree
    if (k < root->data) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in the right subtree
    else if (k > root->data) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    // If key is same as root's key, then this is the node to be deleted
    // Node with only one child or no child
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest
    // in the right subtree)
    Node* succParent = root;
    Node* succ = root->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    // Copy the inorder successor's content to this node
    root->data = succ->data;

    // Delete the inorder successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;
    
    delete succ;
    return root;
}

int main()
{
    Node* root = NULL;

    int n;
    cin >> n;
    int a;
   
  
    for (int i = 0; i < n; i++)
    {
        cin >> a;
       root =  insertNode(root ,a);
    }
    
    int key = 70;
    deleteNode(root , 20);
    // Node* value = (struct Node*)malloc(sizeof(struct Node));
    // value = searchNode(root , key);
    // cout << value -> data << endl;
    cout << "Inorder Traverse: " << endl;
    InorderTraverse(root);
    cout << endl;
    cout << "Post Order Traverse: " << endl;
    PreorderTraverse(root);
    cout << endl;
    cout << "PreOrder Traverse: " << endl;
    PreorderTraverse(root);
    cout << endl;

}