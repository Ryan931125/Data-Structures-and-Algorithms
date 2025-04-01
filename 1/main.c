#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#define int long long

bool check(int nums[],int n){
    if (n<3||((nums[n-2]-nums[n-3])*(nums[n-1]-nums[n-2])<0))
        return true;
    return false;
}

void beauty(int n,int nums[],int on,int answers[200000][n],int *count,int cur[]){
    // printf("hi\n");
    if (!check(cur,on))
        return;
    if (on==n){
        // printf("ho\n");
        bool same=true;
        for (int i=0;i<n;i++)
            if (*count==0||cur[i]!=answers[*count-1][i]){
                same=false;
                break;
            }
        if (same)
            return;
        for (int i=0;i<n;i++)
            answers[*count][i]=cur[i];
        (*count)++;
        return;
    }
    for (int i=0;i<n;i++){
        if (nums[i]==1000000001)
            continue;
        cur[on]=nums[i];
        int temp=nums[i];
        nums[i]=1000000001;
        beauty(n,nums,on+1,answers,count,cur);
        nums[i]=temp;
        while(i<n && nums[i]==nums[i+1])
            i++;
    }
    return;
}

signed main(){
    int n;
    scanf("%lld",&n);
    int nums[n];
    for (int i=0;i<n;i++)
        scanf("%lld",&nums[i]);
    
    //bubble sort
    for (int i=n-1;i>0;i--)
        for (int j=0;j<i;j++)
            if (nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }

    //setting up skip
    // int repeats[n],skip=1;
    // for (int i=0;i<n;i++)
    //     repeats[i]=1;
    // for (int i=1;i<n;i++)
    //     if (nums[i]==nums[i-1])
    //         repeats[i]+=repeats[i-1];
    // for (int i=0;i<n;i++)
    //     skip*=repeats[i];

    //finding if legal
    int most=0,temp=1,half=(n+1)/2;
    for (int i=1;i<n;i++){
        if (nums[i]==nums[i-1])
            temp++;
        else{
            if (temp>most)
                most=temp;
            temp=1;
        }
    }
    if (most>half){
        printf("0\n");
        exit(0);
    }
    // printf("%d\n",skip);
    
    int answers[200000][n],cur[n],count=0;
    beauty(n,nums,0,answers,&count,cur);
    
    printf("%lld\n",count);
    for (int i=0;i<count;i++){
        for (int j=0;j<n;j++)
            printf("%lld ",answers[i][j]);
        printf("\n");
    }
    return 0;
}


//check function, run every time
//遞迴填入所有數字 如果on第一第二個就直接繼續填，執行check(在最後三個數字就好)，如果on最後一個答案就加一
//不然就也繼續填