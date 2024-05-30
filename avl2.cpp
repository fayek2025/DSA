#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* right;
    struct node* left;
    int height;
};

int height( struct node* n)
{
    if(n == NULL) 
    {
        return 0;
    }
    return n->height ;
}


int getbalance(node* n)
{
    if(n == NULL)
    {
        return 0;
    }

    return height(n->left) - height(n->right);
}

node* createNode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> right = NULL;
    newnode -> left = NULL;
    newnode -> height = 1;

    return (newnode);
}

node* rightRotate(node* y)
{
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y-> left = T2;

    //adjusting height
    y->height = 1+ max(height(y->left) , height(y->right));
    x->height = 1+ max(height(x->left) , height(x->right));

    return x;

}

node* leftRotate(node* x)
{
    node *y = x->right; 
	node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	// Return new root 
	return y; 

}

node* insert(node* node , int data)
{
   if (node == NULL) 
		return(createNode(data)); 

	if (data < node->data) 
		node->left = insert(node->left, data); 
	else if (data > node->data) 
		node->right = insert(node->right, data); 
	else // Equal datas not allowed 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this 
		ancestor node to check whether 
		this node became unbalanced */
	int balance = getbalance(node); 

	// If this node becomes unbalanced,
	// then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && data < node->left->data) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && data > node->right->data) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && data > node->left->data) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && data < node->right->data) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
}



void preOrder(node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->data << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 
int main()
{
    node *root = NULL; 

	
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);

	

	cout << "Preorder traversal of the "
			"constructed AVL tree is \n"; 
	preOrder(root); 
}