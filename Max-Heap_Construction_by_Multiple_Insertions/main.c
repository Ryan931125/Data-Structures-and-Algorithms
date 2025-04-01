#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

int heapsize=0;
void max_heap_insert(int a[], int key);
void heap_increase_key(int a[], int i, int key);
void swap(int arr[], int a, int b);

int main(){
    int n, temp;
    scanf("%d",&n);
    int ret[n+1];
    for (int i=0;i<=n;i++)
        ret[i]=0;

    for (int i=1;i<=n;i++){
        scanf("%d",&temp);
        max_heap_insert(ret, temp);
    }
    for (int i=1;i<=n;i++)
        printf("%d ",ret[i]);
    return 0;
}

void max_heap_insert(int a[], int key){
    heapsize++;
    a[heapsize]=-1;
    heap_increase_key(a,heapsize,key);
    return;
}

void heap_increase_key(int a[], int i, int key){
    a[i]=key;
    while (i>1 && a[i/2]<a[i]){
        swap(a,i/2,i);
        i/=2;
    }
    return;
}

void swap(int arr[], int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
    return;
}