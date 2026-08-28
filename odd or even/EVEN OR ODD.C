#include <stdio.h>

int main() {
    int n,a,i;

    scanf("%d",&n);

    for(i=0;i<n;i++) {
        scanf("%d",&a);

        if(a%2==0)
            printf("%d - Even\n",a);
        else
            printf("%d - Odd\n",a);
    }

    return 0;
}
