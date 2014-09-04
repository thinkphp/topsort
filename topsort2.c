#include <stdio.h>
#include <malloc.h>

int output[50], ind = 0;

//variable n holds the number of lines from file
//variable m holds the number of nodes.
int n,m;

//matrix of adiacent
int mat[30][30];

int visited[50];

//FILE I/O
FILE *fin, *fout;

//prototypes
void read(const char*);
void solve();
void dfs(int);
void write(const char*);

//main function
int main() {

    //read from file the graph
    read("topsort.in");

    //solves the problem with the algorithm
    solve();

    //write the solution
    write("topsort2.out");

    //return SUCCESS to the Operating System
    return(0);
}

//function read
void read(const char* filename) {

     int i,j;
     fin = fopen(filename, "r");
 
     fscanf(fin,"%d",&n);
     fscanf(fin,"%d",&m);

     for(;n;n--) {

          fscanf(fin,"%d",&i);
          fscanf(fin,"%d",&j);
          mat[i][j] = 1;
     }
}

//the algorithm
void solve() {
     int i; 
 
     //loop through each node and check if visited
     for(i = 1; i <= m; i++) {

         //if is not visited the node then you can make a depth first search
         if(visited[i] == 0) {

                dfs( i ); 
         }
     }   
}

void dfs(int node) {

     int kNode;

     printf("%d ", node);

     output[ ind++ ] = node;

     visited[ node ] = 1; 

     for(kNode = 1; kNode <=m; kNode++) {
 
         if((mat[ node ][ kNode ] == 1) && visited[ kNode ] == 0) {

                dfs( kNode ); 
         } 
     }  
}

void write(const char* filename) {
 
     int i;

     fout = fopen(filename, "w");

     fprintf(fout,"%s\n", "One Solution:");

     for(i=0;i<m;i++) fprintf(fout,"%d ", output[i]);

     fclose( fout );
}