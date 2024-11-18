// C program to check if a node exists
// in a binary tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to traverse the tree in preorder
// and check if the given node exists in it
int ifNodeExists(struct Node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    // then recur on left subtree
    int res1 = ifNodeExists(root->left, key);

    // node found, no need to look further
    if (res1) return 1;

    // node is not found in left, 
    // so recur on right subtree
    int res2 = ifNodeExists(root->right, key);

    return res2;
}

struct Node* createNode(int x) {
    struct Node* newNode = 
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    
    // Binary tree  
    //          0
    //        /  \
    //       1    2
    //      / \   / \
    //     3   4 5   6
    //    /   / \
    //   7   8   9
    struct Node* root = createNode(0);
    root->left = createNode(1);
    root->left->left = createNode(3);
    root->left->left->left = createNode(7);
    root->left->right = createNode(4);
    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);
    root->right = createNode(2);
    root->right->left = createNode(5);
    root->right->right = createNode(6);

    int key = 4;

    if (ifNodeExists(root, key))
        printf("True");
    else
        printf("False");

    return 0;
}
