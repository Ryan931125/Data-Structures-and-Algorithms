#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#define int long long

typedef struct node{
    int num;
    struct node *under;
}Node;

Node *genNode(int num,Node *under){
    Node *ret=(Node *)malloc(sizeof(Node));
    assert(ret!=NULL);
    ret->num=num;
    ret->under=under;
    return ret;
}

signed main(){
    //setup
    int n,m;
    scanf("%lld%lld",&n,&m);
    int amount[n];
    Node *tops[n],*bots[n];
    for (int i=0;i<n;i++){
        amount[i]=0;
        tops[i]=bots[i]=NULL;
    }

    //running commands
    int ope,i;
    for (int t=0;t<m;t++){
        scanf("%lld%lld",&ope,&i);
        i--;

        switch (ope){
        case 1:{//Add a card numbered u to the top of deck i.
            int u;
            scanf("%lld",&u);
            Node *ptr=genNode(u,tops[i]);
            tops[i]=ptr;
            if (bots[i]==NULL)
                bots[i]=ptr;
            amount[i]++;
            break;
        }

        case 2:{//Remove a card from the top of deck i.
            if (bots[i]==tops[i])
                bots[i]=tops[i]=NULL;
            else
                tops[i]=tops[i]->under;
            amount[i]--;
            break;
        }
        case 3:{//Move all cards from deck i onto the top of deck "end". 
            int end;
            scanf("%lld",&end);
            end--;
            amount[end]+=amount[i];
            amount[i]=0;
            if (tops[i]==NULL&&amount[i]==0)
                break;
            if (tops[end]==NULL){
                tops[end]=tops[i];
                bots[end]=bots[i];
                tops[i]=bots[i]=NULL;
                break;
            }
            bots[i]->under=tops[end];
            tops[end]=tops[i];
            tops[i]=bots[i]=NULL;
            break;
        }
        case 4:{//Merge deck i into deck "dest" in a shuffling manner.
            int dest;
            scanf("%lld",&dest);
            dest--;
            amount[dest]+=amount[i];
            amount[i]=0;
            if (tops[i]==NULL)
                break;
            if (tops[dest]==NULL){
                tops[dest]=tops[i];
                bots[dest]=bots[i];
                tops[i]=bots[i]=NULL;
                break;
            }

            Node *head,*tail;
            head=tail=tops[i];
            tops[i]=tops[i]->under;
            bool take_deck_i=false;
            while (tops[i]&&tops[dest]){
                if (take_deck_i){
                    tail->under=tops[i];
                    tops[i]=tops[i]->under;
                    take_deck_i=false;
                }
                else{
                    tail->under=tops[dest];
                    tops[dest]=tops[dest]->under;
                    take_deck_i=true;
                }
                tail=tail->under;
            }
            if (take_deck_i){
                tail->under=tops[i];
                tops[dest]=head;
                bots[dest]=bots[i];
                tops[i]=bots[i]=NULL;
            }
            else{
                tail->under=tops[dest];
                tops[dest]=head;
                tops[i]=bots[i]=NULL;
            }
            break;
        }
        }
    }

    //printing out the stuff
    for (int i=0;i<n;i++){
        // printf("hi\n");
        printf("%lld ",amount[i]);
        while(tops[i]!=NULL){
            printf("%lld ",tops[i]->num);
            tops[i]=tops[i]->under;
        }
        printf("\n");
    }
    return 0;
}


        

        
        