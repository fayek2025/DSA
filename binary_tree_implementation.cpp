
#include <bits/stdc++.h>

using namespace std;


struct node
{
    int key;
    struct node* right;
    struct node* left;
};

struct node* createNewnode(int data)
{
    struct node* newnode = (node*)malloc(sizeof(node));

    if(newnode != NULL)
    {
        newnode ->key = data;
        newnode->right = newnode->left = NULL;

    }
    return newnode;
}

struct node* insertNode(struct node* root , int data)
{
    if(root == NULL)
    {
       return createNewnode(data);   
    }

    if(data > root->key)
    {
        root -> right = insertNode(root->right , data);
    }

    if(data < root->key)
    {
        root -> left = insertNode(root ->left , data);
    }

    return root;
}

void inorderTraverse(struct node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorderTraverse(root->left);
    cout << root->key << " ";
    inorderTraverse(root->right);
    
    
}

node* deletion(struct node* root , int key)
{
    if(root == NULL)
    {
        return root;    
    }


    if(key > root ->key)
    {
        root -> right = deletion(root->right , key);
        return root;
    }
    if(key < root->key)
    {
        root -> left = deletion(root->left ,key);
        return root;
    }

    if(root->left == NULL)
    {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if(root -> right ==NULL)
    {
        node* temp = root->left;
        delete root;
        return temp;
    }

    node* succparent = root;
    node* succ = root->right;
    while (succ -> left != NULL)

    {
        succparent = succ;
        succ = succ ->left;
    }

    root -> key = succ-> key;
    if(succparent->left == succ)
    {
        succparent->left = succ->right;
    }
    else
    {
        succparent->right = succ->right;
    }

    delete succ;
    return root;
    
}

node* search(node* root , int key)
{
    if(root == NULL || root->key == key)
    {
        return root;
    }

    if(key > root-> key)
    {
       return  search(root -> right , key);
    }

    if(key < root -> key)
    {
       return search(root -> left , key);
    }
}

int main()
{
    node* root = (node*) malloc(sizeof(node));
    root = NULL;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
       root =  insertNode(root , a);
    }

    deletion(root , 100);
    cout << search(root , 20)->key << endl;
    inorderTraverse(root);
    
}