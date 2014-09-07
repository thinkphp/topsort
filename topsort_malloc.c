#include <stdio.h>
#include <malloc.h>

#define MAX 50001
#define FOR(a,b,c) for(a=b;a<=c;a++)

struct Node {
 
       int          info;
       struct Node *next;
};

FILE *fin,*fout;

int num_edges, num_nodes, visited[ MAX ];

struct Node *L[ MAX ] , 
            *head = NULL;

void read(const char*);
void solve();
void dfs(int);
void write(const char*);

int main() {

    read("sortaret.in");
    solve();
    write("sortaret.out"); 

    return(0);
};

void read(const char *filename) {

     int i,j;
     struct Node *c;
     
     fin = fopen(filename,"r");
     fscanf(fin,"%d %d", &num_edges, &num_nodes);

     for(;num_edges; num_edges--) {

         fscanf(fin,"%d %d", &i, &j);

         c = (struct Node*)malloc(sizeof(struct Node)); 
         c->info = j;
         c->next = L[ i ];
         L[ i ] = c; 
     }  
};

void solve() {

     int node;

     FOR(node, 1, num_nodes) {  

         if(!visited[ node ]) 

            dfs( node );
     }
};

void dfs(int node) {

     struct Node *c,*p;

     visited[ node ] = 1;

     for(c = L[node]; c; c = c->next) 

         if( !visited[ c->info ] ) 
         
              dfs( c->info );

     //add to list
     p = (struct Node*)malloc(sizeof(struct Node)); 
     p->info = node;
     p->next = head;
     head = p;           
}

void write(const char *filename) {

     struct Node *c;

     fout = fopen(filename, "w");

     for(c = head; c ; c = c->next) 

             fprintf(fout, "%d ", c->info);

     fclose( fout ); 
}

