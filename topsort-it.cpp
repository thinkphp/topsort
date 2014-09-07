#include <iostream>
#include <fstream>
#include <vector>

#define MAX 50001
#define FIN "topsort.in"
#define FOUT "topsort.out"

using namespace std;

ifstream fin( FIN );
ofstream fout( FOUT );

//fstream fin("topsort.in",ios::in);
//fstream fout("topsort.out",ios::out);

int num_edges, num_vertices;

vector<int> L[MAX], solution;

bool visited[MAX];

void read();
void topsort();
void write();
void dfs(int);//depth first search = traversal in graphs

int main() {

    read();
    topsort();
    write();
 
  return(0);
}

void read() {

     int len,x,y,i;

     fin>>num_edges;
     fin>>num_vertices;
     
     len = num_edges;

     for(;len;len--) {

          fin>>x;
          fin>>y;
          L[x].push_back(y); 
     }
}

void topsort() {

     int i;

     for(i = 1; i <= num_vertices; i++) {

             if( !visited[i] ) {

                 dfs( i ); 
             }
     }
}

void dfs(int vertice ) {

     visited[ vertice ] = 1;

     for(vector<int>::iterator i = L[ vertice ].begin(); i != L[vertice].end(); i++) {

                if( !visited[ *i ] ){

                     dfs( *i );
                }         
     }

     solution.push_back( vertice );
}


void write() {
     
     for(vector<int>::reverse_iterator i = solution.rbegin(); i != solution.rend(); i++) {

                      cout<<(*i)<<" ";
                      fout<<(*i)<<" "; 
     }
}