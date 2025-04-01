#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
// #define int long long

void binary_search(int a[],int key,int l,int r){
    printf("Searching %d in range [%d, %d].\n",key,l+1,r+1);
    while (l<=r){
        int m=(l+r)/2;
        if (a[m]==key){
            printf("Found at index %d.\n",m+1);
            return;
        }
        else if (a[m]>key)
            r=m-1;
        else    
            l=m+1;
        printf("Searching %d in range [%d, %d].\n",key,l+1,r+1);
    }
    printf("Not found.\n");
    return;
}

int main(){
    int n,key;
    scanf("%d%d",&n,&key);
    int nums[n];
    for (int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    binary_search(nums,key,0,n-1);
    return 0;
}
