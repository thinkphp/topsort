#include <iostream>
#include <fstream>
#include <vector>

#define FIN "topsort.in"
#define FOUT "topsort.out"
#define MAX 50001
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define ROF(a,b,c) for(int a=b;a>=c;a--)

using namespace std;

int num_edges, num_vertices;

bool visited[50];

vector<int> vec[MAX], solution;

ifstream fin(FIN);
ofstream fout(FOUT);

//prototypes
void read();
void topsort();
void dfs(int);
void write();

int main() {

     read();

     topsort();

     write();

     return(0);
}

void dfs(int node) {

     struct Node *c;

     visited[ node ] = 1;

     for(int i = 0; i < vec[ node ].size(); i++) {
 
                if( !visited[ vec[node][ i ] ] ) {

                     dfs( vec[ node ][ i ] );  
                }
     } 

     solution.push_back( node );
}

void read() {

     int i,j;

     fin>>num_edges;
     fin>>num_vertices;

     for( ;num_edges; num_edges--) {

          fin>>i;

          fin>>j;

          vec[i].push_back(j);
     }  
}

void topsort() {

          FOR( i, 1, num_vertices )

              if( !visited[ i ] )

                 dfs( i ); 


}

void write() {

     for(vector<int>::reverse_iterator i = solution.rbegin(); i != solution.rend(); i++) {

         cout<<*i<<" ";
         fout<<*i<<" ";
     }
}
