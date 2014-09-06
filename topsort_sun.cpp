#include <iostream>
#include <fstream>
#include <vector>

#define FIN "topsort.in"
#define FOUT "topsort.out"
#define MAX 50001
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define ROF(a,b,c) for(int a=b;a>=c;a--)

using namespace std;

struct Node {
       int info;
       struct Node *next;
};

int num_edges, num_vertices;

bool visited[50];


struct Node *L[MAX], *head = NULL;

ifstream fin(FIN);
ofstream fout(FOUT);

//prototypes
void read();
void topsort();
void dfs(int);
void add_to_list(int,struct Node *&);
void write();

int main() {

     read();

     topsort();

     write();

     return(0);
}

void add_to_list(int j, struct Node *&l) {

     struct Node *c;

     c = new Node;
     c->info = j;
     c->next = l;
     l = c;  
}

void dfs(int node) {

     struct Node *c;

     visited[ node ] = 1;
 
     for(c = L[ node ]; c; c = c->next) {

           if(!visited[ c->info  ]) 

               dfs( c->info );
     }

     add_to_list(node, head);
}

void read() {

     int i,j;

     fin>>num_edges;
     fin>>num_vertices;

     for( ;num_edges; num_edges--) {

          fin>>i;

          fin>>j;

          add_to_list(j, L[ i ]); 
     }  
}

void topsort() {


          FOR( i, 1, num_vertices )

              if( !visited[ i ] )

                 dfs( i ); 


}

void write() {

     struct Node *c;

     for(c = head; c; c = c->next) 

             cout<<c->info<<" ";   

     /*

      Your Turn; Your choice!

     OR
       c = head;

       while( c ) {

              cout<<c->info<<" ";

              c = c->next;
       }  

     */

     /*
     OR
       c = head;

       while( c ) {

              prinf("%d ", c->info);

              c = c->next;
       }  

     */

}
