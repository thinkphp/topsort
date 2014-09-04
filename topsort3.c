#include <stdio.h>
#include <malloc.h>

typedef struct cell {
        int node;
        int time;
} Cell;

Cell cells[30],*p;

int time = 0;

int output[50], ind = 0;

//matrix of adiacent
int mat[30][30], 
    visited[50], 
    n, 
    m;

//FILE I/O
FILE *fin, *fout;

//prototypes
void read(const char*);
void solve();
void dfs(int);
void write(const char*);
void initCells();
Cell* bubblesort(Cell*);

//main function
int main() {     
   
    //read from file the graph
    read("topsort.in");

    initCells();

    //solves the problem with this magic algorithm
    solve();

    int kk;
    for(kk=1;kk<=m;kk++) {
        printf("%d %d || ", cells[kk].node, cells[kk].time);
    }
     
  
    //p = cells;

    //p = bubblesort(p);

    //write the solution
    //write("topsort2.out");

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

     cells[ node ].time = time++;  

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

void initCells() {
    int i;
    for(i=1;i<=m;i++) {
            cells[i].node = i;
            cells[i].time = -1;
    }
}

Cell* bubblesort(Cell *p) {

    int i,swapped;
 
    do {

       swapped = 0;

       for(i = 1; i <= m; i++) {

        if(p[i].time > p[i+1].time) {

           Cell temp;
           temp = p[i];
           p[i] = p[i+1];
           p[i+1] = temp; 
        }         
    }
    }while(swapped);

  return p;
}