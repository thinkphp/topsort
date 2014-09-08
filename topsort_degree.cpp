#include <iostream>
#include <fstream>
#include <vector>

#define FIN "topsort.in"
#define FOUT "topsort.out"
#define MAX 50001
#define pb push_back

using namespace std;

ifstream fin(FIN);
ifstream fout(FOUT);

vector<int> L[ MAX ];
int id[ MAX ], sol[ MAX ], 
    num_edges, 
    num_vertices;


//prototypes
void read();
void solve();
void write();

int main() {

    read();
    solve();
    write();

    return (0);
}

//read function
void read() {

    int i,j;

    fin>>num_edges;
    fin>>num_vertices;

    for(;num_edges; num_edges--) {

         fin>>i;
         fin>>j;  
         L[ i ].pb( j ); 
         id[ j ]++;
    } 
}

//solve function
void solve() {

     int i,
         j,
         x;

     for(i = 1; i <= num_vertices; i++)

         if( !id[ i ] ) 

             sol[ ++sol[ 0 ] ] = i;
 
     for(i = 1; i <= sol[ 0 ]; i++) {

         x = sol[i];

         for(j = 0; j < L[x].size(); j++) {

             id[ L[ x ][ j ] ]--;

             if( !id [ L[ x ][ j ] ]) sol[ ++sol[ 0 ] ] = L[ x ][ j ];
         } 
     }
}

//write function
void write() {

     int i;

     for(i = 1; i <= num_vertices; i++) 

         cout<<sol[ i ]<<" ";
}
