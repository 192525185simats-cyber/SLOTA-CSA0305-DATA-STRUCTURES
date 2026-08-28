#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

int main() {
    int ch, x, i;

    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d",&ch);

        if(ch == 1) {
            if(rear == MAX-1)
                printf("Overflow");
            else {
                scanf("%d",&x);
                if(front == -1) front = 0;
                q[++rear] = x;
            }
        }
        else if(ch == 2) {
            if(front == -1 || front > rear)
                printf("Underflow");
            else
                printf("Deleted = %d",q[front++]);
        }
        else if(ch == 3) {
            for(i=front;i<=rear;i++)
                printf("%d ",q[i]);
        }
        else
            break;
    }

    return 0;
}
