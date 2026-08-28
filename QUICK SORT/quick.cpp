#include <stdio.h>

void quick(int a[], int l, int r)
{
    int i, j, p, t;

    i = l;
    j = r;
    p = a[(l + r) / 2];

    while(i <= j)
    {
        while(a[i] < p)
            i++;

        while(a[j] > p)
            j--;

        if(i <= j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }

    if(l < j)
        quick(a, l, j);

    if(i < r)
        quick(a, i, r);
}

int main()
{
    int a[20], n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick(a, 0, n - 1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
