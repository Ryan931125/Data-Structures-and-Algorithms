#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
// #define ll long long

void quicksort(int a[], int l, int r, int *swaps);
int partition(int a[], int l, int r, int *swaps);
void swap (int arr[], int a, int b);

int main(){
    int n,b;
    scanf("%d%d",&n,&b);
    int arr[n], totalswaps=b;
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n-1,&b);

    printf("The array is ");
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("after %d swaps.",totalswaps-b);
    return 0;
}

void quicksort(int a[], int l, int r, int *swaps){
    if ((*swaps)<=0)
        return;
    if (l<r){
        int m=partition(a,l,r,swaps);
        quicksort(a,l,m-1,swaps);
        quicksort(a,m+1,r,swaps);
    }
    return;
}

int partition(int a[], int l, int r, int *swaps){
    if ((*swaps)<=0)
        return -100;
    int pivot=a[l], i=l+1, j=r;
    while (i<j){
        while (i<=r && a[i]<=pivot)
            i++;
        while (j>=l && a[j]>pivot)
            j--;
        if (i>=j)
            break;
        if ((*swaps)>0){
            swap(a,i,j);
            (*swaps)--;
        }else break;
    }
    if (l<j && a[l]>a[j] && (*swaps)>0){
        swap(a,l,j);
        (*swaps)--;
    }
    return j;
}

void swap (int arr[], int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
    return;
}
