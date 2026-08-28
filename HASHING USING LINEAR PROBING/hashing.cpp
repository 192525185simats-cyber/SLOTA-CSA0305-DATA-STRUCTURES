#include <stdio.h>
#define SIZE 7

int main() {
    int h[SIZE],i,key,index;

    for(i=0;i<SIZE;i++)
        h[i]=-1;

    for(i=0;i<4;i++) {
        scanf("%d",&key);

        index=key%SIZE;

        while(h[index]!=-1)
            index=(index+1)%SIZE;

        h[index]=key;
    }

    for(i=0;i<SIZE;i++)
        printf("%d : %d\n",i,h[i]);

    return 0;
}
