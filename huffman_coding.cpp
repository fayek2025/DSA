#include <bits/stdc++.h>

using namespace std;

struct minheapnode
{
    char data;
    unsigned freq;
    
    struct minheapnode* left , *right;
}
;

struct minheap
{
    unsigned size;
    unsigned capacity;
    struct minheapnode** array;
};

//craeting new node
struct minheapnode* newnode(char data , unsigned freq)
{
    minheapnode* newnode = (minheapnode*)malloc(sizeof(minheapnode));

    newnode->data = data;
    newnode->freq = freq;
    newnode->left = newnode->right = NULL;
    return newnode;

}

//createminheap

struct minheap* createminheap(int capacity)
{
    minheap* temp = (minheap*)malloc(sizeof(minheap));
    temp -> size = 0;
    temp -> capacity = capacity;
    temp->array = (minheapnode**)malloc(temp->capacity*sizeof(minheapnode*));

    return temp;
}

//swapping minheapnode
void swapminheapNode(struct minheapnode** a, 
                 struct minheapnode** b) 
  
{ 
  
    struct minheapnode* t = *a; 
    *a = *b; 
    *b = t; 
} 

//minheapify

void minheapify(minheap* temp , int index)
{
    int parent = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < temp->size && temp->array[parent]->freq > temp->array[left]->freq)
    {
        parent = left;
    }

    if(right < temp->size && temp->array[parent]->freq > temp->array[right]->freq)
    {
        parent = right;
    }

    while (parent != index)
    {
        swapminheapNode(&temp->array[parent] , &temp->array[index]);
        minheapify(temp , parent);
    }
    
}

//extract minimum

struct minheapnode* extractmin(minheap* heap)
{
    minheapnode* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minheapify(heap , 0);
    return temp;
}

//
void insertminheap(struct minheap* minheap , minheapnode* minheapnode)
{
    minheap->size ++ ;
    int i = minheap->size -1;

    while (i && minheap->array[(i-1)/2]->freq > minheapnode->freq)

    {
        //parent node is swapped with smaller value
        minheap->array[i] = minheap->array[(i-1)/2];
        i = (i-1)/2;

    }
    minheap -> array[i] = minheapnode;
    
}

void buildminheap(struct minheap* heap)
{
    int n = heap->size -1 ;
    for (int i = (n-1)/2; i >= 0; i--)
    {
        minheapify(heap , i);
    }
    
}


void printarray(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int isLeaf(struct minheapnode* root)
{
    return !(root->left) && !(root->right);
}


struct minheap* createAndBuildminheap(char data[], 
                                      int freq[], int size) 
  
{ 
  
    struct minheap* minheap = createminheap(size); 
  
    for (int i = 0; i < size; ++i) 
        minheap->array[i] = newnode(data[i], freq[i]); 
  
    minheap->size = size; 
    buildminheap(minheap); 
  
    return minheap; 
}


int sizeone(minheap* minheap)
{
    return(minheap->size == 1);
}

//buildHuffmantree
struct minheapnode* buildhuffman(char data[] , int freq[] , int size)
{
    minheapnode* left , *right , *top;

    minheap* minheap = createAndBuildminheap(data , freq , size);

    while (!sizeone(minheap))
    {
       left = extractmin(minheap); 
        right = extractmin(minheap); 
  
        // Step 3: Create a new internal 
        // node with frequency equal to the 
        // sum of the two nodes frequencies. 
        // Make the two extracted node as 
        // left and right children of this new node. 
        // Add this node to the min heap 
        // '$' is a special value for internal nodes, not 
        // used 
        top = newnode('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        insertminheap(minheap, top);

    }

    return extractmin(minheap); //returning top;
    

}

//printcodes
void printhuffmancodes(minheapnode* root , int arr[] , int top)
{
    if(root->left)
    {
        arr[top] = 0;
        printhuffmancodes(root->left , arr , top+1);
    }
    if(root -> right)
    {
        arr[top] = 1;
        printhuffmancodes(root->right , arr ,top+1);
    }


    if(isLeaf(root))
    {
        cout << root->data << ": ";
        printarray(arr , top);
    }
}

void huffCode(char arr[] , int freq[] , int size)
{
    minheapnode* root = buildhuffman(arr , freq , size);
    int top = 0;
    int value[1000] ;
    printhuffmancodes(root , value , top);
}

int main() 
{ 
  
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    huffCode(arr, freq, size); 
  
    return 0; 
}