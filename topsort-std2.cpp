/*
 Topological Sort - made easy with stack and vector
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#define pb push_back
#define num_node 50001

using namespace std;

FILE *fin, *fout;

int n,m;

vector<int> arr[ num_node ];

bool filled[20];

stack<int> st;

void read(const char*);
void dfs(int);
void topsort();
void dfs(int);
void display(const char*);

int main() {

    //read
    read("sorttop.in");

    //the algorithm in action
    topsort();  

    //display the result
    display("sorttop.out");
    
    return(0);
}

void read(const char *filename) {

     int i,j,len;

     fin = fopen(filename, "r");

     fscanf(fin, "%d", &n);

     fscanf(fin, "%d", &m);

     len = n;

     for(;len;len--) {

         fscanf(fin,"%d %d",&i,&j);

         arr[i].pb(j); 
     }
}

void topsort() {

      int j;
                      
      for(j = 1; j <= m; j++)

         if(filled[ j ] == 0)

            dfs( j );
}

void dfs(int node) {
 
     int i;
    
     filled[ node ] = 1; 

     for(i = 0; i < arr[ node ].size(); i++) {

             if( filled[ arr[ node ][ i ] ] == 0) {
 
                 dfs( arr[node][i] );
             }
     }

     st.push( node );
}

void display(const char *filename) {

     fout = fopen(filename,"w");
     int out;

     while(st.size()) {
           out = st.top();

           printf("%d ",out);
           fprintf(fout,"%d ",out);

           st.pop();
     }

     fclose(fout);
}