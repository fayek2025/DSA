#include <bits/stdc++.h>

using namespace std;


int parent[100] = {0};

int ranks[100] = {0};

void make(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    
    
    
}


int find(int x)
{
    if(x != parent[x])
    {
        parent[x] = find(parent[x]); 
    }
    return parent[x];
}


void Union(int x , int y)
{
    int x_rank = parent[x];
    int y_rank = parent[y];

    if(x_rank == y_rank)
    {
        return;
    }

    if(ranks[x_rank] > ranks[y_rank])
    {
        parent[y_rank] = x_rank;
        
    }
    else if(ranks[y_rank] > ranks[x_rank])
    {
        parent[x_rank] = y_rank;
       
    }
    else
    {
        parent[x_rank] = y_rank;
        ranks[y_rank]++;
    }

}

int main()
{
    make(5); 
	Union(0, 2); 
	Union(4, 2); 
	Union(3, 1); 
	
	if (find(4) == find(0)) 
		cout << "Yes\n"; 
	else
		cout << "No\n"; 
	if (find(4) == find(2)) 
		cout << "Yes\n"; 
	else
		cout << "No\n"; 

	return 0; 
}