#include <iostream>
#include <fstream>

#define MAX 50001
#define FOR(a,b,c) for(a=b;a<=c;a++)
#define FIN "topsort.in"
#define FOUT "topsort.out"

using namespace std;

       ifstream fin(FIN);
       ofstream fout(FOUT);

class TopSort {

      private:
       struct Node {
        int         info;
        struct Node *next;
       };

       int num_edges, num_nodes, visited[ MAX ];

       struct Node *L[ MAX ] , *head = NULL;

      public:
      void read();
      void solve();
      void dfs( int ); 
      void write();
};

void TopSort :: read() {

     int i,j;
     struct Node *c;
     
     fin>>num_edges;
     fin>>num_nodes;

     for(;num_edges; num_edges--) {

         fin>>i>>j; 
         c = new Node;
         c->info = j;
         c->next = L[ i ];
         L[ i ] = c; 
     }  
};

void TopSort :: dfs(int node) {

     struct Node *c, *p;

     visited[ node ] = 1;

     for(c = L[node]; c; c = c->next) 

         if( !visited[ c->info ] ) 
         
              dfs( c->info );

     //add to list
     p = new Node;
     p->info = node;
     p->next = head;
     head = p;           
}

void TopSort :: solve() {

     int node;

     FOR(node, 1, num_nodes) {  

         if(!visited[ node ]) 

            dfs( node );
     }
};

void TopSort :: write() {

     struct Node *c;

     for(c = head; c; c=c->next) {

         fout<<c->info<<" ";        
         cout<<c->info<<" ";
     }
};

int main() {

   TopSort obj;
   obj.read();
   obj.solve();
   obj.write();

    return(0);
};

