#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

//先跑一次，記錄每個點的f_time，並把它加進order的後面，第二次跑從order的頭開始跑，
//

typedef struct vertex{
    int colour;
    int color;
    int d_time;
    int f_time;
    int ancestor;
}Vertex;

typedef struct edge{
    int dest;
    struct edge *next;
}Edge;

Edge *getedge(int dest){
    Edge *temp=(Edge *)malloc(sizeof(Edge));
    assert (temp!=NULL);
    temp->dest=dest;
    temp->next=NULL;
    return temp;
}

void dfs_visit_1(Edge *paths[], int at, int *time, Vertex vertexes[], int *inserting, int order[]);
void dfs_visit_2(Edge *paths[], int at, int *time, Vertex vertexes[], int colour);
int compare(const void *a, const void *b);

int main(){
    int num_blocks, num_arrows, mode;
    scanf("%d%d%d", &num_blocks, &num_arrows, &mode);
    Vertex vertexes[num_blocks+1];

    for (int i=1;i<=num_blocks;i++){//initialize
        vertexes[i].color=1; //1 for white, 2 for grey, 3 for black
        vertexes[i].ancestor=-1;
        vertexes[i].colour=0;
    }

    Edge *paths_head[num_blocks+1], *paths_tail[num_blocks+1]
    , *extra_paths_head[num_blocks+1], *extra2_paths_head[num_blocks+1];
    for (int i=0;i<=num_blocks;i++)
        paths_head[i]=paths_tail[i]=extra_paths_head[i]=extra2_paths_head[i]=NULL;

    int source, dest;
    for (int i=1;i<=num_arrows;i++){//adjacency lists
        ReadInt(&source);
        ReadInt(&dest);
        if (paths_head[source]==NULL && paths_tail[source]==NULL)
            extra2_paths_head[source]=extra_paths_head[source]=
            paths_head[source]=paths_tail[source]=getedge(dest);
        else{
            paths_tail[source]->next=getedge(dest);
            paths_tail[source]=paths_tail[source]->next;
        }
    }
    
    //record f_time
    int time=0, inserting=num_blocks, order[num_blocks+1];
    for (int i=1;i<=num_blocks;i++){
        if (vertexes[i].color==1)
            dfs_visit_1(paths_head, i, &time, vertexes, &inserting, order);
    }

    //reverse paths
    Edge *newpaths_head[num_blocks+1], *newpaths_tail[num_blocks+1];
    for (int i=0;i<=num_blocks;i++)
        newpaths_head[i]=newpaths_tail[i]=NULL;

    for (int i=1;i<=num_blocks;i++){
        dest=i;
        while (extra_paths_head[i]!=NULL){
            source=extra_paths_head[i]->dest;
            if (newpaths_head[source]==NULL && newpaths_tail[source]==NULL)
                newpaths_head[source]=newpaths_tail[source]=getedge(dest);
            else{
                newpaths_tail[source]->next=getedge(dest);
                newpaths_tail[source]=newpaths_tail[source]->next;
            }
            extra_paths_head[i]=extra_paths_head[i]->next;
        }
    }

    for (int i=1;i<=num_blocks;i++){//reset
        vertexes[i].color=1; //1 for white, 2 for grey, 3 for black
        vertexes[i].ancestor=-1;
    }

    time=0;
    int num_colors=0, at;
    for (int i=1;i<=num_blocks;i++){
        at=order[i];
        if (vertexes[at].color == 1){
            num_colors++;
            dfs_visit_2(newpaths_head, at, &time, vertexes, num_colors);
        }
    }
    printf("%d\n",num_colors);

    if (mode == 1)
        return 0;

    //do some stuff
    // Vertex scc_vertexes[num_colors+1];
    Edge *scc_paths_heads[num_colors+1], *scc_paths_tails[num_colors+1];
    for (int i=0;i<=num_colors;i++)
        scc_paths_heads[i]=scc_paths_tails[i]=NULL;

    int indegree[num_colors+1];
    for (int i=1;i<=num_colors;i++)
        indegree[i]=0;

    for (int i=1;i<=num_blocks;i++){
        while (extra2_paths_head[i]!=NULL){
            dest=extra2_paths_head[i]->dest;
            if (vertexes[i].colour != vertexes[dest].colour){//source != dest
                int scc_source=vertexes[i].colour, scc_dest=vertexes[dest].colour;
                if (scc_paths_heads[scc_source]==NULL && scc_paths_tails[scc_source]==NULL)
                    scc_paths_heads[scc_source]=scc_paths_tails[scc_source]=getedge(scc_dest);
                else{
                    scc_paths_tails[scc_source]->next=getedge(scc_dest);
                    scc_paths_tails[scc_source]=scc_paths_tails[scc_source]->next;
                }
                indegree[scc_dest]++;
            }
            extra2_paths_head[i]=extra2_paths_head[i]->next;
        }
    }

    int index=0;
    for (int i=1;i<=num_colors;i++){
        if (indegree[i]==0 && index!=0){
            printf("0\n");
            return 0;
        }
        else if (indegree[i]==0)
            index=i;
    }
    assert (index!=0);

    int next=index;
    while (num_colors!=0){
        while (scc_paths_heads[index]!=NULL){
            indegree[scc_paths_heads[index]->dest]--;
            if (indegree[scc_paths_heads[index]->dest]==0){
                if (next!=index){
                    printf("0\n");
                    return 0;
                }
                else    
                    next=scc_paths_heads[index]->dest;
            }
            scc_paths_heads[index]=scc_paths_heads[index]->next;
        }
        num_colors--;
        index=next;
    }
    printf("1\n");

    return 0;
}

int compare(const void *a, const void *b)//這函式是 qsort 所需的比較函式
{
    Vertex *c= (Vertex *)a;
    Vertex *d= (Vertex *)b;
    if (c->f_time < d->f_time)
        return 1;            //傳回  1 代表 a < b
    else if (c->f_time == d->f_time)
        return 0;            //傳回   0 代表 a = b
    return -1;               //傳回 -1 代表 a > b                    
}

void dfs_visit_1(Edge *paths[], int at, int *time, Vertex vertexes[], int *inserting, int order[]){
    (*time)++;
    vertexes[at].d_time=*time;
    vertexes[at].color=2;
    while (paths[at]!=NULL){
        int v=paths[at]->dest;
        if (vertexes[v].color==1){
            vertexes[v].ancestor=at;
            dfs_visit_1(paths, v, time, vertexes, inserting, order);
        }
        paths[at]=paths[at]->next;
    }
    vertexes[at].color=3;
    (*time)++;
    vertexes[at].f_time=*time;
    order[*inserting]=at;
    (*inserting)--;
    return;
}

void dfs_visit_2(Edge *paths[], int at, int *time, Vertex vertexes[], int colour){
    vertexes[at].colour=colour;
    (*time)++;
    vertexes[at].d_time=*time;
    vertexes[at].color=2;
    while (paths[at]!=NULL){
        int v=paths[at]->dest;
        if (vertexes[v].color==1){
            vertexes[v].ancestor=at;
            dfs_visit_2(paths, v, time, vertexes, colour);
        }
        paths[at]=paths[at]->next;
    }
    vertexes[at].color=3;
    (*time)++;
    vertexes[at].f_time=*time;
    return;
}