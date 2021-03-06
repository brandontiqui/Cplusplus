#include <iostream>
using namespace std;

struct node
{
	int v;
	node* next;
	node (int x, node* t)
	{
		v = x;
		next = t;
	}
};

typedef node *link;

int **malloc2d(int, int);
void printMatrix(int **, int);
link *convertToList (int **, link *, int);
void printList (link * a, int size);
void printLista (link * a, int size);

// program begins function execution
int main ()
{
	// input number of vertices
	int i, j, V;
	cout << "Enter the number of vertices: ";
	cin >> V;
	
	int **adj = malloc2d(V, V); // dynamically allocate matrix
	for (i = 0; i < V; i++) // initialize matrix with 0's
		for (j = 0; j < V; j++)
			adj[i][j] = 0;
	for (i = 0; i < V; i++) // initialize diagonal with 1's
		adj[i][i] = 1;
	
	// input the edges
	cout << "Enter the coordinates for an edge (or 'Ctrl' + 'Z'): ";
	while (cin >> i >> j)
	{
		adj[i][j] = 1;
		adj[j][i] = 1;
		cout << "Enter the coordinates for an edge (or 'Ctrl' + 'Z'): ";
	}

	// convert to list
	link *aList = new link [V];
	aList = convertToList(adj, aList, V);
	cout << endl;

	// print matrix
	cout << "Adjacency Matrix: " << endl;
	printMatrix (adj, V);
	cout << endl << endl;

	// print adjacency list
	cout << "Adjacency List: " << endl;
	printLista (aList, V);

	return 0; // indicates successful completion
} // end function main


int **malloc2d(int r, int c)
{
	int **t = new int*[r];
	for (int i = 0; i < r; i++)
		t[i] = new int[c];
	return t;
} // end function malloc2d

void printMatrix (int ** a, int size)
{
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++)
			if (a[i][j] == 1)
				cout << "There is an edge between " << i << " and " 
					<< j << "." << endl;
} // end function print

link *convertToList (int ** b, link * a, int size)
{
	// create array
	for (int i = 0; i < size; i++)
		a[i] = 0;

	// create lists
	for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++)
		{
			if (b[i][j] == 1) // if an edge exists on the matrix
			{ // create the edges on the adjacency list
				a[i] = new node(j, a[i]);
			}
		}
	return a;
} // end function convertToList

void printList (link * a, int size)
{

	for (int i = 0; i < size; i++)
	{
		while (a[i]->next != NULL)
		{
			cout << "There is an edge between " << i << " and " 
					<< a[i]->v << "." << endl;
			a[i] = a[i]->next;
		}
	}
} // end function print

void printLista (link * a, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (link finger = a[i]; finger != NULL; finger = finger->next)
        {
            cout << "There is an edge between " << i << " and " 
                    << finger->v << "." << endl;
        }
    }
} // end function print

