#include <iostream>
#include <fstream>
#include <vector>
#define push push_back
#define FIN "sortaret.in"
#define FOUT "sortaret.out"

using namespace std;

class TopologicalSort {

      public:
      TopologicalSort(vector<vector<int>*> &adjcencyList, int n, int m) :

                      nNodes(n), nEdges(m), adjList(adjcencyList)
      {
              visited.resize( nNodes + 1, false );              
      }

      void execute() {

           for(int i = 1; i <= nNodes; ++i) {

           	   if(!visited[i]) {

           	   	   dfs(i);      
           	   }  
           }    
      }

      void dfs(int node) {

      	   if(!visited[node]) {

      	   	   visited[ node ] = true;

      	   	   if(adjList[ node ]) 

          	   	   for(vector<int>::iterator it = adjList[node]->begin(); it != adjList[node]->end();++it) 

                       dfs(*it);   
          	   	   
               solution.push(node);                                  	   	   	       
      	   } 

      }

      vector<int> getSolution() {

      	     return solution;
      }
      	
      private:
      int nNodes;
      int nEdges;
      vector<vector<int>* >& adjList;
      vector<int> solution;
      vector<bool> visited;	

};

int main(int argc, char const *argv[])
{
	int nodes, edges, 
	    x, y;

	ifstream fin(FIN);	
	ofstream fout(FOUT);

    if(!fin || !fout) {

       cout<<"Error opening one of \""<<FIN<<"\" or \""<<FOUT<<"";	
    }	

    fin>>nodes>>edges;

    vector<vector<int>* > adjList;

    adjList.resize(nodes + 1, NULL);

    for(int i = 0; i < edges; ++i) {
         
    	fin>>x>>y;

    	if(adjList[x] == NULL) {

         	adjList[x] = new vector<int>();         	
         }

    	adjList[x]->push(y);
    }


	//solve the problem:
    TopologicalSort obj(adjList, nodes, edges);
                    obj.execute();
    vector<int> v = obj.getSolution();                    
    
    for(std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {

    	fout<<(*it)<<" ";
    }

    //clean up
    for(int i = 0; i < adjList.size(); ++i) {

    	if(adjList[i]!= NULL) delete adjList[i];
    }

    //close handler files
    fin.close();

    fout.close();

	return 0;
}
