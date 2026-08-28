#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *r, int x) {
    if(r == NULL) {
        r = (struct node *)malloc(sizeof(struct node));
        r->data = x;
        r->left = NULL;
        r->right = NULL;
        return r;
    }

    if(x < r->data)
        r->left = insert(r->left, x);
    else
        r->right = insert(r->right, x);

    return r;
}

void inorder(struct node *r) {
    if(r != NULL) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node *r) {
    if(r != NULL) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r) {
    if(r != NULL) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

int main() {
    struct node *root = NULL;
    int a[] = {50,30,70,20,40,60,80};
    int i;

    for(i = 0; i < 7; i++)
        root = insert(root, a[i]);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
