#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vertex{
    int color;
    int d_time;
    int f_time;
    int ancestor;
}Vertex;

typedef struct edge{
    int dest;
    char type;
    struct edge *next;
}Edge;

Edge *getedge(int dest){
    Edge *temp=(Edge *)malloc(sizeof(Edge));
    assert (temp!=NULL);
    temp->dest=dest;
    temp->next=NULL;
    return temp;
}

void dfs_visit(Edge *paths[], int at, int *time, Vertex vertexes[]);

int main(){
    int v;
    scanf("%d",&v);
    Vertex vertexes[v+1];

    for (int i=1;i<=v;i++){//initialize
        vertexes[i].color=1; //1 for white, 2 for grey, 3 for black
        vertexes[i].ancestor=-1;
    }

    Edge *paths[v+1], *tails[v+1], *answers[v+1];

    for (int i=1;i<=v;i++){//adjacency lists
        answers[i]=paths[i]=tails[i]=getedge(-1);
        int outdegree;
        scanf("%d",&outdegree);
        for (int j=0;j<outdegree;j++){
            int dest;
            scanf("%d",&dest);
            tails[i]->next=getedge(dest);
            // printf("gotchu\n");
            tails[i]=tails[i]->next;
        }
    }

    int time=0;
    for (int i=1;i<=v;i++){
        if (vertexes[i].color==1)
            dfs_visit(paths, i, &time, vertexes);
    }

    for (int i=1;i<=v;i++){
        printf("%d ",i);
        while (answers[i]->next!=NULL){
            // printf("hi\n");
            printf("%c",answers[i]->next->type);
            answers[i]->next=answers[i]->next->next;
        }
        printf("\n");
    }

    return 0;
}

void dfs_visit(Edge *paths[], int at, int *time, Vertex vertexes[]){
    (*time)++;
    vertexes[at].d_time=*time;
    vertexes[at].color=2;
    while (paths[at]->next!=NULL){
        int v=paths[at]->next->dest;
        if (vertexes[v].color==1){
            paths[at]->next->type='T';
            vertexes[v].ancestor=at;
            dfs_visit(paths, v, time, vertexes);
        }
        else if (vertexes[v].color==2)
            paths[at]->next->type='B';
        else{//black
            if (vertexes[at].d_time < vertexes[v].d_time)
                paths[at]->next->type='F';
            else
                paths[at]->next->type='C';
        }
        paths[at]=paths[at]->next;
    }
    vertexes[at].color=3;
    (*time)++;
    vertexes[at].f_time=*time;
    return;
}
