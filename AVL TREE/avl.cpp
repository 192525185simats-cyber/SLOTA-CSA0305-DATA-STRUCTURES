#include <stdio.h>
#include <stdlib.h>

struct node {
    int key, height;
    struct node *left, *right;
};

int height(struct node *n) {
    if(n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

struct node* newnode(int k) {
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    n->key = k;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct node* rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct node* leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

int balance(struct node *n) {
    if(n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

struct node* insert(struct node *n, int k) {
    if(n == NULL)
        return newnode(k);

    if(k < n->key)
        n->left = insert(n->left, k);
    else
        n->right = insert(n->right, k);

    n->height = 1 + max(height(n->left), height(n->right));

    if(balance(n) > 1 && k < n->left->key)
        return rightRotate(n);

    if(balance(n) < -1 && k > n->right->key)
        return leftRotate(n);

    if(balance(n) > 1 && k > n->left->key) {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    if(balance(n) < -1 && k < n->right->key) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void inorder(struct node *r) {
    if(r != NULL) {
        inorder(r->left);
        printf("%d ", r->key);
        inorder(r->right);
    }
}

int main() {
    struct node *root = NULL;
    int a[] = {10, 20, 30, 40, 50, 25};
    int i;

    for(i = 0; i < 6; i++)
        root = insert(root, a[i]);

    printf("Inorder: ");
    inorder(root);

    return 0;
}
