// C code to find level of a Node in Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int getLevel(struct Node* root, int target, int level) {
    if (root == NULL) {
        return -1;
    }

    // If the target key matches the current node's data, return the level
    if (root->data == target) {
        return level;
    }

    // Recursively call for left and right subtrees
    int leftLevel = getLevel(root->left, target, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }

    return getLevel(root->right, target, level + 1);
}

struct Node* createNode(int val) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
  
    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int target = 5;
    printf("%d\n", getLevel(root, target, 1));

    return 0;
}
