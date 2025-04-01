#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#define LEN 5000005
#define int long long
//prefix function可以找最長的prefix=suffix
//要怎麼找所有的prefix=suffix，找到了業
//通通改成0-based

void compute_prefix(char word[], int pi[], int len){
    pi[0]=-1;
    int k=-1;
    for (int q=1;q<len;q++){
        while (k>-1 && word[k+1]!=word[q]){
            // printf("hi ");
            k=pi[k];
        }
        if (word[k+1]==word[q])
            k++;
        pi[q]=k;
    }
    return;
}

void kmp_matcher(char T[], char P[], int lenT, int lenP, int pi[], int hit_count[]){
    int q=-1;
    for (int i=0;i<lenT;i++){
        while (q>-1 && P[q+1]!=T[i])
            q=pi[q];
        if (P[q+1]==T[i]){
            q++;
            hit_count[q]++;
        }
        if (q==lenP-1)
            q=pi[q];
    }
}

signed main(){
    char S[LEN], C[LEN];
    scanf("%s%s",S,C);
    int lenC=strlen(C), lenS=strlen(S);
    int pre_suf[lenC], pi[lenC], hit_count[lenC];
    for (int i=0;i<lenC;i++){
        pre_suf[i]=1;
        hit_count[i]=0;
        pi[i]=-1;
    }
    compute_prefix(C, pi, lenC);

    for (int i=1;i<lenC;i++)
        if (pi[i]!=-1)
            pre_suf[i]+=pre_suf[pi[i]];

    kmp_matcher(S, C, lenS, lenC, pi, hit_count);

    for (int i=lenC-1;i>-1;i--)
        if (pi[i]>-1)
            hit_count[pi[i]]+=hit_count[i];
    
    for (int i=0;i<lenC;i++)
        printf("%lld\n", pre_suf[i]*hit_count[i]);




    //testing
    // printf("pre_suf: ");
    // for (int i=0;i<lenC;i++)  
    //     printf("%lld ",pre_suf[i]);
    // printf("\npi: ");
    // for (int i=0;i<lenC;i++)
    //     printf("%lld ", pi[i]);
    //testing
    return 0;
}

