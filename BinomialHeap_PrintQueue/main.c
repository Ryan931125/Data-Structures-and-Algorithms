#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

typedef struct tree{
    struct tree *next;
    struct tree *child;
    //child is subtree with highest order
    int order;
    int id;
    int priority;
}Tree;

typedef struct heap{
    //head is child with smallest order
    struct tree *head;
    // struct node *tail;
}Heap;

Tree *maketree(int order, int data, int priority, Tree *next, Tree *child);
Heap *makeheap(Tree *head);
Tree *BinomialHeapMerge(Heap *h1, Heap *h2);
Heap *BinomialHeapUnion(Heap *h1, Heap *h2);
Heap *BinomialHeapInsert(Heap *h, Tree *x);
Heap *BinomialHeapExtractMax(Heap *h);//記得free
Tree *reverse(Tree *t);

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    Heap *printers[n+1];
    int num_of_jobs[n+1];
    //default printers
    for (int i=0;i<=n;i++){
        printers[i]=makeheap(NULL); //possible bug
        num_of_jobs[i]=0;
    }
    for (int i=0;i<m;i++){
        int ope;
        scanf("%d",&ope);
        switch(ope){
        case 1:{
            int job_id, priority, printer_id;
            scanf("%d%d%d", &job_id, &priority, &printer_id);
            num_of_jobs[printer_id]++;
            printers[printer_id]=BinomialHeapInsert(printers[printer_id],maketree(0,job_id,priority,NULL,NULL));
            printf("%d jobs waiting on printer %d\n",num_of_jobs[printer_id],printer_id);
            break;
        }
        case 2:{
            int printer_id;
            scanf("%d",&printer_id);
            if (num_of_jobs[printer_id] == 0)
                printf("no documents in queue\n");
            else{
                num_of_jobs[printer_id]--;
                printers[printer_id]=BinomialHeapExtractMax(printers[printer_id]);
            }
            break;
        }
        case 3:{
            int printer_id1, printer_id2;
            scanf("%d%d",&printer_id1, &printer_id2);
            num_of_jobs[printer_id2]+=num_of_jobs[printer_id1];
            num_of_jobs[printer_id1]=0;
            printers[printer_id2]=BinomialHeapUnion(printers[printer_id1],printers[printer_id2]);
            printers[printer_id1]->head=NULL;
            printf("%d jobs waiting on printer %d after moving\n", num_of_jobs[printer_id2], printer_id2);
            break;
        }
        }
    }
    return 0;
}

Tree *maketree(int order, int id, int priority, Tree *next, Tree *child){
    Tree *ret=(Tree *)malloc(sizeof(Tree));
    assert(ret!=NULL);
    ret->child=child;
    ret->id=id;
    ret->next=next;
    ret->order=order;
    ret->priority=priority;
    return ret;
}

Heap *makeheap(Tree *head){
    Heap *ret=(Heap *)malloc(sizeof(Heap));
    assert(ret!=NULL);
    ret->head=head;
    return ret;
}

Tree *BinomialHeapMerge(Heap *h1, Heap *h2) {
    Tree *tail, *head, *head1 = h1->head, *head2 = h2->head;

    // initializing head, tail
    if (head1 == NULL && head2 == NULL)
        return NULL;
    else if (head2 == NULL) {
        head = tail = head1;
        head1 = head1->next;
    } else if (head1 == NULL) {
        head = tail = head2;
        head2 = head2->next;
    } else if (head1->order < head2->order) {
        head = tail = head1;
        head1 = head1->next;
    } else {
        head = tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL || head2 != NULL) {
        if (head1 == NULL) {
            tail->next = head2;
            break;
        } else if (head2 == NULL) {
            tail->next = head1;
            break;
        } else if (head1->order < head2->order) {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        } else {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }

    return head;
}

Heap *BinomialHeapUnion(Heap *h1, Heap *h2){
    Heap *H=makeheap(NULL);
    H->head=BinomialHeapMerge(h1,h2);
    if (H->head==NULL)
        return H;
    Tree *prev=NULL, *x=H->head, *nextone=x->next;
    while (nextone!=NULL){
        if (x->order != nextone->order || (nextone->next != NULL && nextone->next->order == x->order)){
            prev=x;
            x=nextone;
        }
        else{//x and next are of the same order
            if (x->priority >= nextone->priority){
                x->next=nextone->next;

                //insert next as a child of x, and update degree[x]
                nextone->next=x->child;
                x->child=nextone;
                x->order++;
            }
            else{
                if (prev == NULL)
                    H->head=nextone;
                else
                    prev->next=nextone;
                
                //insert x as a child of next, and update degree[next]
                x->next=nextone->child;
                nextone->child=x;
                nextone->order++;
                x=nextone;
            }
        }
        nextone=x->next;
    }
    return H;
}

Heap *BinomialHeapInsert(Heap *h, Tree *x){
    Heap *temp_heap=makeheap(x); //possible bug
    return BinomialHeapUnion(h,temp_heap);
}

Tree *reverse(Tree *t){
    if (t==NULL)
        return NULL;
    Tree *prev=NULL, *curr=t, *next=NULL;
    while (curr != NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Heap *BinomialHeapExtractMax(Heap *h){
    assert(h!=NULL);
    Tree *temp=h->head, *temp_prev=NULL, *x=h->head, *prev=NULL;
    assert(temp!=NULL);
    int prior=x->priority;
    while (temp != NULL){
        if (temp->priority > prior){
            prior=temp->priority;
            x=temp;
            prev=temp_prev;
        }
        temp_prev=temp;
        temp=temp->next;
    }
    assert(x!=NULL);
    printf("%d printed\n",x->id);
    if (prev == NULL)
        h->head=x->next;
    else
        prev->next=x->next;
    
   
    Tree *new=x->child;
    new=reverse(new);
    Heap *new_heap=makeheap(new);
    Heap *ret=BinomialHeapUnion(new_heap,h);
    
    free(x);
    return ret;
}
