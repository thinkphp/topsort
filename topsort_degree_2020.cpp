#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FIN "sortaret.in"
#define FOUT "sortaret.out"
#define SIZE 50010

using namespace std;

vector<int> G[SIZE];
bool seen[SIZE];
long Degree[SIZE];
int nodes, edges, i, x, y;

ofstream fout(FOUT);

void dfs(int node) {

	 if(seen[node]) return;

     seen[node] = true;

     for_each(G[node].begin(), G[node].end(), dfs);

     fout<<node<<" ";
}

int main(int argc, char const *argv[])
{
	ifstream fin(FIN);
	

	fin>>nodes>>edges;

	while(edges--) {
		  fin>>x>>y;
		  G[y].push_back(x);
		  Degree[x]++;
	}

    for(i = 1; i <= nodes; ++i) {

    	if(!seen[i] && Degree[i] == 0) 

    		dfs(i);
    }  
	return 0;
}
