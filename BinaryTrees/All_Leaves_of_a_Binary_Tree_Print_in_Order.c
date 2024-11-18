#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to print leaf nodes from left to right
void printLeafNodes(struct Node* root) {
    // If node is NULL, return
    if (!root)
        return;

    // If node is a leaf node, print its data
    if (!root->left && !root->right) {
        printf("%d ", root->data);
        return;
    }

    // If left child exists, check for leaf nodes recursively
    if (root->left)
        printLeafNodes(root->left);

    // If right child exists, check for leaf nodes recursively
    if (root->right)
        printLeafNodes(root->right);
}

// Driver program to test above functions
int main() {
    // Create the binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    // Print the leaf nodes
    printLeafNodes(root);
    printf("\n");

    return 0;
}
