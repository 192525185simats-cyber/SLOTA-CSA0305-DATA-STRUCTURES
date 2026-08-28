#include <stdio.h>
#define INF 9999

int main() {
    int a[10][10],selected[10]={0};
    int n,i,j,k,x,y,min,total=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    selected[0]=1;

    for(i=0;i<n-1;i++) {
        min=INF;

        for(j=0;j<n;j++) {
            if(selected[j]) {
                for(k=0;k<n;k++) {
                    if(!selected[k] &&
                       a[j][k] &&
                       a[j][k]<min) {
                        min=a[j][k];
                        x=j;
                        y=k;
                    }
                }
            }
        }

        printf("%d - %d : %d\n",x,y,min);

        total+=min;
        selected[y]=1;
    }

    printf("Total weight = %d",total);

    return 0;
}
