#include <stdio.h>
#define MAX 5

int main() {
    int s[MAX],top=-1,n,i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        s[++top]=0;

    printf("Enter stack elements:\n");

    for(i=0;i<n;i++)
        scanf("%d",&s[i]);

    top=n-1;

    printf("Peek = %d\n",s[top]);
    printf("Pop = %d\n",s[top--]);

    printf("Stack: ");

    for(i=0;i<=top;i++)
        printf("%d ",s[i]);

    return 0;
}
