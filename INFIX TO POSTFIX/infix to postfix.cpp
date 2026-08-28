#include <stdio.h>
#include <ctype.h>

char stack[50];
int top=-1;

int priority(char c) {
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main() {
    char in[50],post[50],c;
    int i=0,j=0;

    scanf("%s",in);

    while((c=in[i++])!='\0') {
        if(isalnum(c))
            post[j++]=c;

        else if(c=='(')
            stack[++top]=c;

        else if(c==')') {
            while(stack[top]!='(')
                post[j++]=stack[top--];
            top--;
        }

        else {
            while(top!=-1 &&
                  priority(stack[top])>=priority(c))
                post[j++]=stack[top--];

            stack[++top]=c;
        }
    }

    while(top!=-1)
        post[j++]=stack[top--];

    post[j]='\0';

    printf("%s",post);

    return 0;
}
