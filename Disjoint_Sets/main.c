#include <stdio.h>

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

typedef struct node{
    int p;
    int rank;
}Node;
Node objects[1000005];
int Find_Set(int x){
    if (x != objects[x].p)
        objects[x].p=Find_Set(objects[x].p);
    return objects[x].p;
}

void Link(int x, int y){
    if (objects[x].rank>objects[y].rank)
        objects[y].p=x;
    else{
        objects[x].p=y;
        if (objects[x].rank==objects[y].rank)
            objects[y].rank++;
    }
}

void Print_Path(int x){
    int k=x;
    while (objects[k].p!=k){
        printf("%d ",k);
        k=objects[k].p;
    }
    printf("%d\n",k);
}

void Union(int x, int y){
    int v=Find_Set(x), w=Find_Set(y);
    if (v!=w)
        Link(v,w);
}

int main(){
    int n,m;
    ReadInt(&n);
    ReadInt(&m);
    for (int i=1;i<=n;i+=1){
        objects[i].p=i;
        objects[i].rank=0;
    }

    int ope;
    int x, y;
    for (int i=0;i<m;i+=1){
        ope=readchar();
        ReadInt(&x);
        if (ope==(int)'F')
            Find_Set(x);
        else if (ope == (int)'U'){
            ReadInt(&y);
            Union(x,y);
        }
        else
            Print_Path(x);
    }
    return 0;
}
