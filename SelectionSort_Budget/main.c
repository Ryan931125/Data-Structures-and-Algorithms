#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int Get_Min_Index(int a[], int l, int r){
    int m = l; // store current min. index
    for (int i = l+1;i<r;i++){// update if i-th element smaller
        if (a[m] > a[i])
            m = i;
    }
    return m;
}

int Selection_Sort(int a[],int len,int budget){
    int swaps=0;
    for (int i=0;i<len && swaps<budget;i++){
        int m = Get_Min_Index(a, i, len);
        if (i != m){
            swaps++;
            int temp=a[i];
            a[i]=a[m];
            a[m]=temp;
        }
    }
    return swaps; // which has been sorted in place
}

signed main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int nums[n];
    for (int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    int swaps=Selection_Sort(nums,n,m);
    
    //printing
    printf("The array is ");
    for (int i=0;i<n;i++)
        printf("%d ",nums[i]);
    printf("after %d swaps.\n",swaps);

    return 0;
}
