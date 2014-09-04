#include <stdio.h>
#include <malloc.h>

int output[50], ind = 0;

//variable n holds the number of lines from file
//variable m holds the number of nodes.
int n,m;

//struct node for list adiacent
typedef struct Node {
        int info;
        struct Node *next;
} Node;

Node *L[20];

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
    write("topsort.out");

    //return SUCCESS to the Operating System
    return(0);
}

//function read
void read(const char* filename) {
     int i,j;
     fin = fopen(filename, "r");
 
     struct Node *p;

     fscanf(fin,"%d",&n);
     fscanf(fin,"%d",&m);

     for(i = 1; i <= m; i++) {
         L[i] = NULL;
     }
      
     for(;n;n--) {

          fscanf(fin,"%d",&i);
          fscanf(fin,"%d",&j);

          //read with list of adiacence
          p = (struct Node*)malloc(sizeof(struct Node));
          p->info = j;
          p->next = L[i];
          L[i] = p;  
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

     struct Node *c;

     int x;

     printf("%d ", node);

     output[ind++] = node;

     visited[ node ] = 1; 

     c = L[ node ];

     while( c ) {

           x = c->info;

           if(visited[ x ] == 0) {

              dfs( x ) ;
           }  

           c = c->next;
     }      
}

void write(const char* filename) {
 
     int i;

     fout = fopen(filename, "w");

     fprintf(fout,"%s\n", "One Solution:");

     for(i=0;i<m;i++) fprintf(fout,"%d ", output[i]);

     fclose( fout );
}