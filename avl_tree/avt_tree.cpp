#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    int height;
};


//Finding height of a node
int height(Node* N)
{
    if(N == NULL) return 0;
    return N->height; 
}

Node* rightrotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x-> right  = y;
    y->left = T2;

    y->height = max(height(y->left) , height(y->right)) + 1;
    x->height = max(height(x->right) , height(x->left)) + 1;

    return x; 
}

Node* leftrotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    
    return y;

}


Node* newnode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node -> height = 1;
    return node;
}


int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
} 

Node* insertnode(Node* root , int key)
{
    if(root == NULL) 
    {
        return (newnode(key));
    }
    else if(key > root->key)
    {
        root->right = insertnode(root->right , key);
    }
    else if(key < root->key)
    {
        root->left = insertnode(root->left , key);
    }
    else
    {
        return root;
    }


    root -> height = 1 + max(height(root->left) , height(root->right));

    int balance = getBalance(root);


    if(balance > 1 && key < root->left->key)
    {
        return rightrotate(root);
    }
    else if(balance < -1 && key > root->right->key)
    {
        return leftrotate(root);
    }
    else if(balance > 1 && key > root->left->key)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root); 
    }
    else if(balance < -1 && key < root->right->key)
    {
        root -> right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
} 

int main()  
{  
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insertnode(root, 10);  
    root = insertnode(root, 20);  
    root = insertnode(root, 30);  
    root = insertnode(root, 40);  
    root = insertnode(root, 50);  
    root = insertnode(root, 25);  
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
}  

