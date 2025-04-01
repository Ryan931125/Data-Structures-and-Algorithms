#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#define int long long
#define MAXLAYER 64

void swap()




signed main(){
    int n, t, m;
    scanf("%d%d%d",&n,&t,&m);
    int ranks[n][3], reward_count=0; // 分別是label, 計數器, power
    for (int i=0;i<n;i++){
        ranks[i][0]=i+1;
        ranks[i][1]=0;
        scanf("%d",&ranks[i][2]);
    }
    int operation;
    for (int i=0;i<t;i++){
        //deal with cases
        switch (operation){
        case 1:
            int label;
            scanf("%d",&label);
            //attack and deal with reward_count
            break;
        case 2:
            reward_count++;
            break;
        case 3:
            //對 ranks[][2]做二分搜
            break;
        case 4:
            
    }
    return 0;
}


// 分數用一般陣列 ranks
// 操作2加幾次分用一個計數器跟一個額外的count陣列存
// 操作3要先處理全部count剩下的 再用二分搜找到東西
// 四用二維vector存 存前綴和
// 但四先用
// game record用二維vector存每次誰加了幾分