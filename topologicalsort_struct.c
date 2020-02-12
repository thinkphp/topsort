#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define FIN "sortaret.in"
#define FOUT "sortaret.out"
#define SIZE 50010

struct TNode {
	   int data;
	   struct TNode *next;
};

typedef struct TNode Node;

Node* head=NULL;

struct topsort {

       int nodes;
       int edges;
       void (*exe)(struct topsort*);        
       Node **adjList;
};

typedef struct topsort Topsort;

void dfs(int node, int seen[], Node**adjList, int *ret) {     
     
     seen[node] = 1;     

     for(Node *c = adjList[node]; c; c = c->next)

         if(!seen[c->data]) 

         	dfs(c->data, seen, adjList, ret);

   Node *c = (Node*)malloc(sizeof(Node));

        	  c->data = node;

        	  c->next = head;

        	  head = c;        	       
}

void execute(struct topsort *top) {
    
     int *ret = (int*)malloc(sizeof(int));     

     int seen[top->nodes + 1];

     memset(seen, 0, sizeof(seen));

     for(int i = 1; i <= top->nodes; ++i) {

     	 if(!seen[i]) {
            
            dfs(i, seen, top->adjList, ret);
     	 }
     }     

     while(head) {

    	printf("%d ", head->data); head = head->next;
    }
};

//for debug
void display(Node**adjList, int nodes) {

        printf("\n");

	    for(int i = 1; i <= nodes; ++i) {
        
        if(adjList[i]!=NULL) {

        	   Node *curr = adjList[i];

               while(curr!=NULL) {

               	 printf("%d ", curr->data);

               	 curr = curr->next;
               }
        }

        printf("\n");
    }            
}

int main(int argc, char const *argv[])
{   
	int nodes, edges, x, y;
    
    freopen(FIN, "r", stdin);    

    scanf("%d %d", &nodes, &edges);

    Node *adjList[nodes + 1];

    for(int i = 1; i <= nodes; ++i) adjList[i] = NULL;

    for(int i = 1; i <= edges; ++i) {

        scanf("%d %d", &x, &y);

        Node *c = (Node*)malloc(sizeof(Node));

        	  c->data = y;

        	  c->next = adjList[x];

        	  adjList[x] = c;        	  
    }
    
    display(adjList, nodes);
    
    freopen(FOUT, "w", stdout);    
                                
    Topsort top = {nodes, edges, execute, adjList}; 

    top.exe(&top);        

    //clean up
    for(int i = 1; i <= nodes; ++i) 

    	if(adjList[i]!=NULL) 

    	   free(adjList[i]);

	return 0;
}
