#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// 定義一維向量結構
typedef struct {
    int *data;   // 指向整數數組的指標
    int size;    // 目前向量的大小
    int capacity; // 向量的容量
} Vector;

typedef struct {
    int label;
    int power;
    int gotten_reward;
    int attacks;
    Vector gained;
} classmate;

// 初始化向量
Vector initVector() {
    Vector vec;
    vec.size = 0;
    vec.capacity = 1;
    vec.data = (int *)malloc(vec.capacity * sizeof(int));
    if (vec.data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    return vec;
}

// 釋放向量的記憶體
void freeVector(Vector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

// 在向量末尾添加元素
void pushBack(Vector *vec, int value) {
    // 如果向量已滿，則擴展容量
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int *)realloc(vec->data, vec->capacity * sizeof(int));
        if (vec->data == NULL) {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
    }
    vec->data[vec->size++] = value;
}

// 獲取向量中特定位置的值
int getElement(Vector *vec, int index) {
    if (index >= 0 && index < vec->size) {
        return vec->data[index];
    } else {
        printf("Error: Index out of range.\n");
        return -1; // 返回一個錯誤值
    }
}

int true_power(classmate players[], int reward_count, int k, int n){
    return (players[k].power+(reward_count-players[k].gotten_reward)*(n-k-1));
}

int query(classmate players[], int power, int n, int reward_count){
    //二分搜
    if (power>true_power(players,reward_count,0,n))
        return -1;
    int l=0, r=n-1, ret=-1;
    while (l<=r){
        int m=(l+r)/2;
        if (true_power(players,reward_count,m,n)==power){
            while (m<n && true_power(players,reward_count,m,n)==power)
                m++;
            return m;
        }
        else if (true_power(players,reward_count,m,n)>power){
            ret=m;
            l=m+1;
        }
        else
            r=m-1;
    }
    return ret+1;
}

signed main(){
    int n, t, m;
    scanf("%d%d%d", &n, &t, &m);

    classmate players[n]; //sort using rank
    int label_to_rank[n],reward_count=0;
    for (int i=0;i<n;i++){
        label_to_rank[i]=i+1;
        players[i].attacks=0;
        players[i].label=i+1;
        players[i].gotten_reward=0;
        scanf("%d",&players[i].power);
        players[i].gained=initVector();
    }

    int operation;
    for (int i=0;i<t;i++){
        scanf("%d",&operation);
        //deal with cases
        switch (operation){
        case 1:{ //about done
            int label;
            scanf("%d",&label);
            int rank=label_to_rank[label-1],label2=players[rank-2].label;
            // printf("attack_rank=%d\n",rank);
            if (rank==1)
                break;
            players[rank-1].attacks++;
            players[rank-1].power+=(reward_count-players[rank-1].gotten_reward)*(n-rank);
            players[rank-2].power+=(reward_count-players[rank-2].gotten_reward)*(n-rank+1);
            players[rank-1].gotten_reward=players[rank-2].gotten_reward=reward_count;
            int increase=players[rank-2].power-players[rank-1].power, num=players[rank-1].attacks;
            if (num==1)
                pushBack(&players[rank-1].gained, increase);
            else
                pushBack(&players[rank-1].gained, getElement(&players[rank-1].gained, num-2)+increase);
            
            players[rank-1].power=players[rank-2].power;
            
            classmate tmp=players[rank-1];
            players[rank-1]=players[rank-2];
            players[rank-2]=tmp;
            label_to_rank[label-1]=rank-1;
            label_to_rank[label2-1]=rank;
            break;
        }
        case 2: //about done
            reward_count++;
            break;
        case 3:{ //about done
            int power;
            scanf("%d",&power);
            int rank=query(players,power,n,reward_count);
            if (rank==-1)
                printf("0 0\n");
            else
                printf("%d %d\n",rank,players[rank-1].label);
            break;
        }
        case 4:{
            int label, m;
            scanf("%d%d", &label, &m);
            int rank=label_to_rank[label-1],num=players[rank-1].attacks;
            // printf("rank=%d, num=%d\n",rank,num);
            if (num==0){
                printf("0\n");
                break;
            }
            int back=getElement(&players[rank-1].gained, num-1);
            if (num<=m)
                printf("%d\n",back);
            else{
                int front=getElement(&players[rank-1].gained, num-1-m);
                printf("%d\n", back-front);
            }
            break;
        } 
        }
        // printf("operation:%d\n",operation);
        // printf("label to rank: ");
        // for (int i=0;i<n;i++)
        //     printf("%d ",label_to_rank[i]);
        // printf("\n");
        // printf("labels: ");
        // for (int i=0;i<n;i++)
        //     printf("%d ", players[i].label);
        // printf("\n");
        // printf("powers: ");
        // for (int i=0;i<n;i++){
        //     printf("%d ", players[i].power);
        // }
        // printf("\n\n");
    }

// getElement(&players[i].gained,0)
    printf("\n");
    //print game record
    for (int b=0;b<n;b++){
        int i=label_to_rank[b]-1;
        printf("%d ",players[i].attacks);
        for (int j=0;j<players[i].attacks;j++){
            if (j==0)
                printf("%d ",getElement(&players[i].gained,0));
            else
                printf("%d ", (getElement(&players[i].gained,j)-getElement(&players[i].gained,j-1)) );

        }
        printf("\n");
    }

    return 0;
}


// 分數用一般陣列 ranks
// 操作2加幾次分用一個計數器跟一個額外的count陣列存
// 操作3要先處理全部count剩下的 再用二分搜找到東西
// 四用二維vector存 存前綴和
// 但四先用
// game record用二維vector存每次誰加了幾分