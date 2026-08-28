#include <stdio.h>

int main() {
    int n,i;
    long fact=1;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
        fact=fact*i;

    printf("Factorial of %d = %ld",n,fact);

    return 0;
}
