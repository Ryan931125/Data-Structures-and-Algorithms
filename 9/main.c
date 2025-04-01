#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#define ll long long
//抓數字：一直到出現運算子為止，把前面幾個都抓進一個unsigned int, 原本的位子用一個k取代
//用string存infix跟postfix，用array就好

bool higher_precedence(char a, char b){
    int aa,bb;
    if (a=='+' || a=='-') aa=0;
    else aa=1;
    if (b=='+' || b=='-') bb=0;
    else bb=1;

    if (aa>=bb)
        return true;
    return false;
}

ll int calculate(ll int n1, ll int n2, char ope){
    if (ope=='+')
        return n1+n2;
    else if (ope=='-')
        return n1-n2;
    else if (ope=='*')
        return n1*n2;
    else if (ope=='/')
        return n1/n2;
    else 
        return n1%n2;
}

void infix_to_postfix(char infix[], char postfix[], ll int numbers[]){
    int len=strlen(infix), on=0, nums=0, poston=0;
    char s[len];
    for (int i=0;i<len;i++){
        char token=infix[i];
        if (isdigit(token)){
            int start=i;
            char temp[15]={0};
            while (isdigit(infix[i+1]))
                i++;
            strncpy(temp,&infix[start],i-start+1);
            printf("%s",temp);
            ll int hi=0,temp_len=strlen(temp),exp=1;
            for (int k=temp_len-1;k>=0;k--){
                hi+=(ll int)(temp[k]-'0')*exp;
                exp*=10;
            }
            numbers[nums]=hi;
            nums++;
            postfix[poston]='k';
            poston++;

        }
        else{
            if (token=='('){
                s[on]='(';
                on++;
            }
            else if (token==')'){
                while (on!=0 && s[on-1]!='('){
                    postfix[poston]=s[on-1];
                    poston++;
                    printf("%c",s[on-1]);
                    on--;
                }
                on--;
            }
            else{
                while (on!=0 && s[on-1]!='(' && higher_precedence(s[on-1],token)){
                    postfix[poston]=s[on-1];
                    poston++;
                    printf("%c",s[on-1]);
                    on--;
                }
                s[on]=token;
                on++;
            }
        }
    }
    while (on!=0){
        postfix[poston]=s[on-1];
        poston++;
        printf("%c",s[on-1]);
        on--;
    }
    return;
}

ll int postfix_eval(char postfix[], ll int numbers[]){
    int len=strlen(postfix), slen=0, on=0;
    ll int s[len];
    for (int i=0;i<len;i++){
        if (postfix[i]=='k'){//meet a number
            s[slen]=numbers[on];
            on++;
            slen++;
        }
        else{//meet a operator
            ll int n2=s[slen-1];
            slen--;
            ll int n1=s[slen-1];
            slen--;
            char ope=postfix[i];
            ll int n3=calculate(n1,n2,ope);
            // printf("\nn3=%lld\n",n3);
            s[slen]=n3;
            slen++;
        }
    }
    return s[slen-1];
}

signed main(){
    for (int i=0;i<3;i++){
        char infix[4005]={0},postfix[4005]={0};
        scanf("%s",infix);
        ll int numbers[4000]={0};
        infix_to_postfix(infix,postfix,numbers);
        printf("=");
        printf("%lld",postfix_eval(postfix,numbers));
        printf("\n");
        // printf("%s\n",postfix);
        // int k=0;
        // while (numbers[k]!=(ll int)0){
        //     printf("%d ",(int)numbers[k]);
        //     k++;
        // }
        // printf("\n");
    }
}

