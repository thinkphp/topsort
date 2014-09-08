#include <iostream>
#include <fstream>
#include <queue>

#define FIN "topsort_q.in"
#define FOUT "topsort_q.out"
#define MAX 50001
#define pb push_back

using namespace std;

ifstream fin(FIN);
ifstream fout(FOUT);

int num_edges, num_nodes;//num_vertices
vector<int> v;

vector<vector<int> > list;//or vector<int> list[MAX] c`est la meme chose
queue<int> q;
int vec[ MAX ];

void read();
void topsort();

int main() {

    read(); 
    topsort();

     return(0);
}

void read() {

     int i,j;

     fin>>num_edges;
     fin>>num_nodes;

     for(i = 0; i < num_nodes + 1; i++) list.push_back( v ); 

     for(;num_edges; num_edges--) {
 
         fin>>i;
         fin>>j;

         list[i].push_back( j );
         vec[j]++;
     }


     for(i = 1; i <= num_nodes; i++) 

         if(vec[i] == 0) 

            q.push( i );     
}

void topsort() {

     int x;

     while( q.size() ) {
 
           x = q.front();

           q.pop();

           cout<<x<<" ";

           for(int k = 0; k < list[ x ].size(); k++) {

                   vec[ list[ x ][ k ] ]--;

                   if( vec[ list[ x ][ k ] ] == 0)    
 
                       q.push( list[x ][ k] );
           }  
     }
}
