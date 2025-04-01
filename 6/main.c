#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
// #define int long long

int moves=0;

void insert(int a[], int m, int n){
    
    // for (int i=0;i<n;i++)
    //     printf("%d ",a[i]);
    // printf("\n");


    int data=a[m];
    int i=m-1;
    while (i>=0&&a[i]>data&&moves>0){
        moves--;
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=data;
    return;
}

void Insertion_sort(int a[],int n){
    for (int i=0;i<n&&moves>0;i++)
        insert(a,i,n);
    return;
}

int main(){
    int n,b;
    scanf("%d%d",&n,&b);
    moves=b;
    int a[n];
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    // for (int i=0;i<n;i++)
    //     printf("%d ",a[i]);
    // printf("\n");
    Insertion_sort(a,n);

    printf("The array is ");
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("after %d back-moves.",b-moves);
    return 0;
}
