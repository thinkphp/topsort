#include <stdio.h>
#include <malloc.h>
#define SIZE 50001

struct TNode {
	   int data;
	   struct TNode *next;
	   
};

typedef struct TNode Node;

Node *G[SIZE];

int seen[SIZE], 
    sol[SIZE], 
    V[SIZE];

void DFS(int node) {

     seen[node] = 1;

     Node *q;

     q = G[node];

     while(q) {

     	if(!seen[q->data]) 

     		DFS(q->data);

     	q = q->next;
     }      

     sol[++sol[0]] = node;
}

int main(int argc, char const *argv[])
{
	int nodes, edges, x, y;

	const char *inFile = "sortaret.in" ;
	const char *outFile = "sortaret.out";

    freopen(inFile, "r", stdin);

    scanf("%d %d", &nodes, &edges);
    
    for(int i = 1; i <= nodes; ++i) G[i] = NULL;

    while(edges--) {

          scanf("%d %d", &x, &y);

          Node *c = (Node*)malloc(sizeof(Node));
                c->data = y;
                c->next = G[x];
                G[x] = c;
                V[y] = 1;
    }

    for(int i = 1; i <= nodes; ++i) {

    	if(V[i] == 0) 

    	   DFS(i);	     	
    }

    freopen(outFile, "w", stdout);

    for(int i = sol[0]; i >= 1; --i) printf("%d ", sol[i]);

    return 0;
}
