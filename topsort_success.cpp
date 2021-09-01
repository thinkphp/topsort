#include <stdio.h>
#include <malloc.h>
#define FIN "sortaret.in"
#define FOUT "sortaret.out"
#define MAX 500001
 
struct Node {
 
       int info;
       struct Node *next;
};
 
int num_nodes, num_edges, visited[MAX];
 
struct Node *G[ MAX ], *head = NULL;
 
void dfs(int node) {
 
       struct Node *c, *p;
 
       visited[ node ] = 1;
 
       for(c = G[node]; c; c=c->next) {
 
           if(!visited[c->info]) {
 
             dfs(c->info);
           }
       }
 
       p = (struct Node*)malloc(sizeof(struct Node));
       p->info = node;
       p->next = head;
       head = p;
}
 
int main(int argc, char const *argv[]) {
 
    int i, j;
    struct Node *c;
 
    freopen(FIN, "r", stdin);
 
    freopen(FOUT, "w", stdout);
 
    scanf("%d %d", &num_nodes, &num_edges);
 
    while(num_edges--) {
 
          scanf("%d %d", &i, &j);
          c = (struct Node*)malloc(sizeof(struct Node));
          c->info = j;
          c->next = G[ i ];
          G[ i ] = c;
    }
  
    for(int node = 1; node <= num_nodes; ++node) {
 
             if(!visited[node]) {
 
                 dfs(node);
             }
    }
 
    for(c = head; c; c = c->next) {
 
        printf("%d ", c->info);
    }
  return 0;
