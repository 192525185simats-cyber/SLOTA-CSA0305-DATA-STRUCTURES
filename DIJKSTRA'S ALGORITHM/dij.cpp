#include <stdio.h>
#define INF 9999

int main() {
    int a[10][10],dist[10],vis[10]={0};
    int n,i,j,src,u,min;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    scanf("%d",&src);

    for(i=0;i<n;i++)
        dist[i]=INF;

    dist[src]=0;

    for(i=0;i<n-1;i++) {
        min=INF;
        u=-1;

        for(j=0;j<n;j++)
            if(!vis[j] && dist[j]<min) {
                min=dist[j];
                u=j;
            }

        if(u==-1)
            break;

        vis[u]=1;

        for(j=0;j<n;j++)
            if(a[u][j] && !vis[j] &&
               dist[u]+a[u][j]<dist[j])
                dist[j]=dist[u]+a[u][j];
    }

    for(i=0;i<n;i++)
        printf("To %d = %d\n",i,dist[i]);

    return 0;
}
