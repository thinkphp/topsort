#include <iostream>
#include <fstream>
#include <vector>
#define SIZE 50100
#define push push_back 

using namespace std;

vector<int> G[ SIZE ];
int Deg[SIZE];
int nodes, edges;

void read() {

     int x, y;
     const char *inFile = "sortaret.in";
      
	 ifstream fin(inFile);  

	 fin>>nodes>>edges;

	 while(edges--) {
	 	fin>>x>>y;
	 	G[x].push(y);
	 	Deg[y]++;
	 }
 
     fin.close(); 	 
}

void topsort() {

     const char *outFile = "sortaret.out";

     ofstream fout(outFile);  

     int i, k = 0;

     while(k < nodes) {

           for(i = 1; i <= nodes; ++i) {

                   if(Deg[i] == 0) {

                   	  fout<<i<<" ";

                   	  k++;

                   	  --Deg[i];

                   	  for(vector<int>::iterator it = G[i].begin(); it != G[i].end(); ++it) 

                   	  	  --Deg[*it];
                   }

           }
     }
}


int main(int argc, char const *argv[])
{
	
    read();
    topsort();

	return 0;
}
