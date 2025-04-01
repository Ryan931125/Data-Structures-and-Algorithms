#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#define LL long long

void compute_prefix_function(LL P[], LL pi[], LL len){
    pi[1]=0;
    LL k=0;
    for (LL q=2;q<=len;q++){
        while (k>0 && P[k+1]!=P[q])
            k=pi[k];
        if (P[k+1]==P[q])
            k++;
        pi[q]=k;
    }
    return;
}

void KMP_Matcher(LL T[], LL P[], LL n, LL m, LL matches[], LL pi[]){
    LL q=0;
    for (LL i=1;i<=n;i++){
        while (q>0 && P[q+1]!=T[i])
            q=pi[q];
        if (P[q+1]==T[i])
            q++;
        if (q==m){
            matches[i-m]=1;
            q=pi[q];
        }
    }
}

int main(){
    //input
    LL k, n, m, q;
    scanf("%lld%lld%lld%lld", &k, &n, &m, &q);
    char T[k+5][n+5], P[k+5][m+5];
    for (LL i=1;i<=k;i++)
        scanf("%s", T[i]);
    for (LL i=1;i<=k;i++)
        scanf("%s", P[i]);
    LL T1[n+5], P1[m+5];//1-based

    //dealing with T-prime, P-prime
    LL p, value;
    for (LL j=0;j<n;j++){
        p=0;
        for (LL i=1;i<=k;i++){
            if (isupper(T[i][j]))  value=T[i][j]-65;
            else    value=T[i][j]-71;
            p=(52 * p + value) % q;
        }
        T1[j+1]=p;
        printf("%lld ",p);
    }
    printf("\n");
    for (LL j=0;j<m;j++){
        p=0;
        for (LL i=1;i<=k;i++){
            if (isupper(P[i][j]))  value=P[i][j]-65;
            else    value=P[i][j]-71;
            p=(52 * p + value) % q;
        }
        P1[j+1]=p;
        printf("%lld ",p);
    }
    printf("\n");

    LL pi[m+5];
    compute_prefix_function(P1, pi, m);

    // printf("pi: ");
    // for (int i=1;i<=m;i++)
    //     printf("%lld ",pi[i]);
    // printf("\n");

    LL matches[n+5];
    for (LL i=0;i<n+5;i++)
        matches[i]=0;
    
    KMP_Matcher(T1, P1, n, m, matches, pi);

    //printing valid shifts
    bool valid, found_shift=false, found_spurious=false;
    for (LL i=0;i<=n-m;i++){
        if (matches[i]==0)
            continue;
        
        found_shift=true;
        printf("%lld ", i);
        valid=true;
        for (LL j=1;j<=k;j++)
            for (LL r=i;r<=i+m-1;r++)
                if (T[j][r]!=P[j][r-i]){
                    valid=false;
                    break;
                }
        if (!valid){
            matches[i]=2;
            found_spurious=true;
        }
    }
    if (!found_shift)
        printf("-1");
    printf("\n");

    //printing squrious hits
    if (!found_spurious){
        printf("-1");
        return 0;
    }
    for (LL i=0;i<=n-m;i++)
        if (matches[i]==2){
            found_spurious=true;
            printf("%lld ",i);
        }

    return 0;
}