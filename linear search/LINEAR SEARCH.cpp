#include <stdio.h>

int main() {
    int a[20],n,key,i,found=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&key);

    for(i=0;i<n;i++) {
        if(a[i]==key) {
            printf("Element found at position %d",i);
            found=1;
            break;
        }
    }

    if(!found)
        printf("Element not found");

    return 0;
}
