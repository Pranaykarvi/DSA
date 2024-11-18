#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Recursive function to find the parent of the target node
int findParent(struct Node* root, int target, int parent) {
    if (root == NULL) {
        return -1;
    }

    // If the current node is the target, return its parent
    if (root->data == target) {
        return parent;
    }

    // Recursively search in the left subtree
    int leftSearch = findParent(root->left, target, root->data);

    if (leftSearch != -1) {
        return leftSearch;
    }

    // Recursively search in the right subtree
    return findParent(root->right, target, root->data);
}

int main() {
    // Representation of the given tree
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int target = 3;

    // Find the parent of the target node
    int parent = findParent(root, target, -1);

    // Print the parent
    printf("%d\n", parent);

    return 0;
}
