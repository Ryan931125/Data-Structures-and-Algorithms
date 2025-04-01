#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
// #define int long long

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *getnode(int data,Node *next){
    Node *temp=(Node *)malloc(sizeof(Node));
    assert(temp!=NULL);
    temp->data=data;
    temp->next=next;
    return temp;
}

bool floyd_cycle_detection(Node *head){
    Node *hare=head, *tortoise=head;
    printf("%d ",hare->data);
    while(hare!=NULL && hare->next!=NULL){
        
        hare=hare->next->next;
        tortoise=tortoise->next;
        if (hare!=NULL)
            printf("%d ",hare->data);
        if (hare==tortoise){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    scanf("%d",&n);
    Node *nodes[n];
    int nexts[n];
    for (int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        nodes[i]=getnode(a, NULL);
        nexts[i]=b-1;
    }
    for (int i=0;i<n;i++){
        if (nexts[i]==-1)
            nodes[i]->next=NULL;
        else
            nodes[i]->next=nodes[nexts[i]];
    }
    Node *temp=nodes[0];
    // for (int i=0;i<n;i++){
    //     printf("%d ",temp->data);
    //     temp=temp->next;
    // }
    floyd_cycle_detection(temp);
}

