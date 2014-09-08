#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>

#define MAX 50001
#define FIN "topsort.in"
#define FOUT "topsort.out"
#define FOR(a,b,c) for(int a=b;a<=c;a++)

using namespace std;

ifstream fin(FIN);
ofstream fout(FOUT);


class TopSort {

      private:
      int num_edges, num_vertices;
      vector<int> L[ MAX ];
      stack<int> myStack;
      int filled[ MAX ];  
            
      public: 
      void Init();
      void read(); 
      void solve();
      void dfs(int);
      void write();  
};

void TopSort :: Init() {

     for(int i = 1; i <= num_vertices; i++) L[i].clear();

     memset(filled, 0, sizeof(filled)); 

     while(!myStack.empty()) myStack.pop();
};

void TopSort :: read() {
      int i,j;
  
      fin>>num_edges;
      fin>>num_vertices;

      for(;num_edges; num_edges--) {

           fin>>i;
           fin>>j;
           L[i].push_back(j);      
      }
};

void TopSort :: solve() {

     for(int node = 1; node <= num_vertices; node++) {

         if(filled[ node ] == 0)

             dfs( node );
     }           
};

void TopSort :: dfs(int node) {

     filled[ node ] = 1;

     for(vector<int>::iterator it = L[node].begin(); it != L[node].end(); ++it) {

             if(filled[ *it ] == 0) {

                  dfs( *it );
             } 
     }

     myStack.push( node );
}

void TopSort :: write() {

     while(!myStack.empty()) {

            fout<<myStack.top()<<" ";
            cout<<myStack.top()<<" ";
            myStack.pop(); 
     }       
};

int main() {
    
    TopSort obj; 
    obj.read();
    obj.solve();
    obj.write();
 
    return (0);
}
