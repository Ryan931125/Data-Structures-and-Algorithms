#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#define int long long
//六個操作分別實作
//1. downstream, 每個node有一個linked list存下流路徑，用兩個array存head跟tail
//2. upstream, 用一般陣列存上流node，如果如果沒有就存-1，不用特判
//怎麼讓pathway消失？
//3. plan, 用一般陣列紀錄目前走過的路徑，每個位置存從零走下來的前綴和，二分搜（數學要處理一下
//4. guess, 單調隊列, linked list 存值，先dfs一遍，往下走不用做事，往上走判斷要不要刪掉，指令四印出最大，
//指令六等等
//5. discover, 用queue存寶藏, 每個寶藏上存如果輸出還剩多少值，或是在哪個點會變負的，存到queue的尾
//如果queue的長度比路徑長度還長，就輸出queue的頭；如果往上走，就判斷寶藏是不是存在那個點，是就pop掉
//6. construct, dungeons新增一條路, maxdeep新算一次, upstream加一條

typedef struct dpath{
    int length;
    int dest;
    struct dpath *next;
}Dpath;

Dpath *get_path(int length, int dest, Dpath *next){
    Dpath *temp=(Dpath *)malloc(sizeof(Dpath));
    assert(temp!=NULL);
    temp->length=length;
    temp->dest=dest;
    temp->next=next;
    return temp;
}

typedef struct maxdeep{
    int depth;
    int dun_num;
    struct maxdeep *next;
    struct maxdeep *previous;
}Maxdeep;

Maxdeep *get_max_deep(int depth, int dun_num, Maxdeep *next, Maxdeep *previous){
    Maxdeep *temp=(Maxdeep *)malloc(sizeof(Maxdeep));
    assert(temp!=NULL);
    temp->depth=depth;
    temp->dun_num=dun_num;
    temp->next=next;
    temp->previous=previous;
    return temp;
}

typedef struct treasure{
    int found_at_dungeon, lost_at;
    int remaining_value;
}Treasure;


typedef struct dungeon{
    Dpath *downstream_head;
    Dpath *downstream_tail;
    int upstream;
    Maxdeep *max_deep_head;
    Maxdeep *max_deep_tail;
}Dungeon;

Dungeon *init_dungeon(){
    Dungeon *temp=(Dungeon *)malloc(sizeof(Dungeon));
    assert(temp!=NULL);
    temp->downstream_head=temp->downstream_tail=get_path(-1,-1,NULL);
    temp->max_deep_head=temp->max_deep_tail=get_max_deep(-1,-1,NULL,NULL);
    temp->upstream=-1;
    return temp;
}

int find_min_index(int route_length[], int node_num, int value);
void init_max_deep(Dungeon *dungeons[], int num_dungeons);
Treasure treasures[1000005];


signed main(){
    int num_dungeons, num_roads, num_operations;
    scanf("%lld%lld%lld",&num_dungeons, &num_roads, &num_operations);

    //for operation 3
    int route_node[num_dungeons], node_num=0;
    int  route_length[1000005];

    //for operation 5
    int t_start=1, t_end=1;

    for (int i=0;i<1000005;i++){
        treasures[i].found_at_dungeon=-1;
        treasures[i].lost_at=-1;
        treasures[i].remaining_value=-1;
    }

    Dungeon *dungeons[num_dungeons];
    for (int i=0;i<num_dungeons;i++){
        dungeons[i]=init_dungeon();
        route_length[i]=route_node[i]=0;
    }
    //downstream_head is a blank node
    //max_deep is also a blank node
    
    for (int i=0;i<num_roads;i++){
        int from, to;
        int length;
        scanf("%lld%lld%lld", &from, &to, &length);
        dungeons[from]->downstream_tail->next=get_path(length,to,NULL);
        dungeons[from]->downstream_tail=dungeons[from]->downstream_tail->next;
        dungeons[to]->upstream=from;
    }
    init_max_deep(dungeons,num_dungeons);

    int location=0;
    for (int i=0;i<num_operations;i++){
        int ope;
        scanf("%lld",&ope);
        switch(ope){
        case 1:{
            if (dungeons[location]->downstream_head->next==NULL)
                printf("-1\n");
            else{
                node_num++; //1
                route_node[node_num]=dungeons[location]->downstream_head->next->dest; //1
                route_length[node_num]=route_length[node_num-1]+dungeons[location]->downstream_head->next->length;
                location=dungeons[location]->downstream_head->next->dest;
                printf("%lld\n",location);
            }
            break;
        }
        case 2:{
            if (location==0)
                printf("-1\n");
            else{
                int previous_dungeon=location;

                if (treasures[t_end-1].found_at_dungeon==location)
                    t_end--;

                node_num--;
                location=dungeons[location]->upstream;
                dungeons[location]->downstream_head->next=dungeons[location]->downstream_head->next->next;
                printf("%lld\n",location);

                //ensure downstream_tail function
                if (dungeons[location]->downstream_head->next==NULL)
                    dungeons[location]->downstream_tail=dungeons[location]->downstream_head;

                //remove longest depth
                if (previous_dungeon == dungeons[location]->max_deep_head->next->dun_num)
                    dungeons[location]->max_deep_head->next=dungeons[location]->max_deep_head->next->next;

                //ensure max_deep_tail function
                if (dungeons[location]->max_deep_head->next==NULL)
                    dungeons[location]->max_deep_tail=dungeons[location]->max_deep_head;

                //change treasure place
                if (treasures[t_end-1].found_at_dungeon>location)
                    treasures[t_end-1].found_at_dungeon=location;
            }
            break;
        }
        case 3:{//int
            int value;
            scanf("%lld",&value);
            int index=find_min_index(route_length, node_num, value);
            printf("%lld\n", route_node[index]);
            break;
        }
        case 4:{
            if (dungeons[location]->downstream_head->next == NULL)
                printf("0\n");
            else
                printf("%lld\n",dungeons[location]->max_deep_head->next->depth);
            //leaf node has no paths (see if max_deep_tail->next == NULL)
            break;
        }
        case 5:{//int
            int value;
            scanf("%lld",&value);
            
            if (location == 0){
                printf("value remaining is %lld\n",value);
                break;
            }

            treasures[t_end].found_at_dungeon=location;
            if (value - route_length[node_num] >= 0){
                treasures[t_end].remaining_value = value - route_length[node_num];
                treasures[t_end].lost_at = -1;
            }
            else{
                treasures[t_end].lost_at = route_node[find_min_index(route_length, node_num, value)-1];
                treasures[t_end].remaining_value = -1;
            }
            t_end++;

            if (t_end-t_start > node_num){
                if (treasures[t_start].lost_at==-1)//remaining value
                    printf("value remaining is %lld\n",treasures[t_start].remaining_value);
                else
                    printf("value lost at %lld\n",treasures[t_start].lost_at);
                t_start++;
            }
            break;
        }
        case 6:{
            int dest;
            int length;
            scanf("%lld%lld",&dest,&length); 
            dungeons[location]->downstream_tail->next=get_path(length,dest,NULL);
            dungeons[location]->downstream_tail=dungeons[location]->downstream_tail->next;
            dungeons[dest]->upstream=location;

            int tmp_depth=length;
            if (dungeons[dest]->max_deep_head->next!=NULL)
                tmp_depth+=dungeons[dest]->max_deep_head->next->depth;

            while (dungeons[location]->max_deep_tail->previous!=NULL && dungeons[location]->max_deep_tail->depth < tmp_depth)
                dungeons[location]->max_deep_tail=dungeons[location]->max_deep_tail->previous;
                // printf("test1\n");

            dungeons[location]->max_deep_tail->next=get_max_deep(tmp_depth,dest,NULL,dungeons[location]->max_deep_tail);
            dungeons[location]->max_deep_tail=dungeons[location]->max_deep_tail->next;

            break;
        }
        }

    }
    return 0;
}

int find_min_index(int route_length[], int node_num, int value){
    int l=0, r=node_num, m;
    while (r-l>1){
        m=(r+l)/2;
        if (value-route_length[node_num]+route_length[m]>=0)
            r=m;
        else
            l=m;
    }
    if (value-route_length[node_num]+route_length[l]>=0)
        return l;
    return r;
}

void init_max_deep(Dungeon *dungeons[], int num_dungeons){
    for (int i=num_dungeons-1;i>=0;i--){
        Dpath *ptr=dungeons[i]->downstream_head->next;
        //ptr is downstream path
        while (ptr!=NULL){
            int tmp_depth=ptr->length;
            if (dungeons[ptr->dest]->max_deep_head->next!=NULL)
                tmp_depth+=dungeons[ptr->dest]->max_deep_head->next->depth;


            while (dungeons[i]->max_deep_tail->previous!=NULL && dungeons[i]->max_deep_tail->depth < tmp_depth)
                dungeons[i]->max_deep_tail=dungeons[i]->max_deep_tail->previous;

            dungeons[i]->max_deep_tail->next=get_max_deep(tmp_depth,ptr->dest,NULL,dungeons[i]->max_deep_tail);
            dungeons[i]->max_deep_tail=dungeons[i]->max_deep_tail->next;
            ptr=ptr->next;
        }
        
    }
    return;
}
