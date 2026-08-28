#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int m,n,p,q,i,j,k;

    printf("Enter order of A: ");
    scanf("%d%d",&m,&n);

    printf("Enter A elements:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter order of B: ");
    scanf("%d%d",&p,&q);

    printf("Enter B elements:\n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            scanf("%d",&b[i][j]);

    if(n!=p) {
        printf("Multiplication not possible");
        return 0;
    }

    for(i=0;i<m;i++)
        for(j=0;j<q;j++) {
            c[i][j]=0;
            for(k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }

    printf("Result:\n");
    for(i=0;i<m;i++) {
        for(j=0;j<q;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
    return 0;
}
