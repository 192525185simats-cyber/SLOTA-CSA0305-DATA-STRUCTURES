#include <stdio.h>

struct edge {
    int u,v,w;
};

int parent[20];

int find(int x) {
    while(parent[x]!=x)
        x=parent[x];

    return x;
}

void unite(int a,int b) {
    parent[find(a)]=find(b);
}

int main() {
    struct edge e[50],temp;
    int n,m,i,j,count=0,total=0;
    int a,b;

    scanf("%d",&n);
    scanf("%d",&m);

    for(i=0;i<m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);

    /* Sort edges */
    for(i=0;i<m-1;i++) {
        for(j=i+1;j<m;j++) {
            if(e[i].w>e[j].w) {
                temp=e[i];
                e[i]=e[j];
                e[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
        parent[i]=i;

    printf("Edges in MST:\n");

    for(i=0;i<m && count<n-1;i++) {
        a=find(e[i].u);
        b=find(e[i].v);

        if(a!=b) {
            printf("%d - %d : %d\n",
                   e[i].u,e[i].v,e[i].w);

            total+=e[i].w;
            unite(a,b);
            count++;
        }
    }

    printf("Total weight = %d",total);

    return 0;
}
