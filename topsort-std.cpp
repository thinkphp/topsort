#include <cstdio>
#include <iostream>
#include <vector>
#define pb push_back
#define num_node 50001

using namespace std;

FILE *fin, *fout;

int n,m;

vector<int> arr[ num_node ], time;

int filled[20];

void read(const char*);
void writeToFile(const char*);
void dfs(int);
void topsort();
void dfs(int);
void display();

int main() {

    read("sorttop.in");

    topsort();  

    display();

    writeToFile("sorttop.out");
    
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

     fclose(fin); 
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

     time.push_back( node );
}

void display() {
     int i;
     for(i=time.size()-1;i>=0;i--) 
         printf("%d ", time[i]);
}

void writeToFile(const char* filename) {
     fout = fopen(filename,"w");
     int i;
     for(i=time.size()-1;i>=0;i--) 
         fprintf(fout,"%d ", time[i]);
     fclose(fout);

}