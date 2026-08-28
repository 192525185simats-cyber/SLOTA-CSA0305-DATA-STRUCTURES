#include <stdio.h>

int main() {
    int a[10][10],visited[10]={0};
    int q[10],front=0,rear=0;
    int n,i,j,start;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    scanf("%d",&start);

    q[rear++]=start;
    visited[start]=1;

    printf("BFS: ");

    while(front<rear) {
        int v=q[front++];

        printf("%d ",v);

        for(i=0;i<n;i++) {
            if(a[v][i] && !visited[i]) {
                visited[i]=1;
                q[rear++]=i;
            }
        }
    }

    return 0;
}
