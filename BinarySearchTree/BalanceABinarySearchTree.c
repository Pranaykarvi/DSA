#include <stdio.h>
#include <stdlib.h>

// Structure to define a node of the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inorder traversal to store elements of the tree in sorted order
void storeInorder(struct Node* root, int* nodes, int* index) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    storeInorder(root->left, nodes, index);

    // Store the node data
    nodes[(*index)++] = root->data;

    // Traverse the right subtree
    storeInorder(root->right, nodes, index);
}

// Function to build a balanced BST from a sorted array
struct Node* buildBalancedTree(int* nodes, int start, int end) {
    // Base case
    if (start > end) {
        return NULL;
    }

    // Get the middle element and make it the root
    int mid = (start + end) / 2;
    struct Node* root = newNode(nodes[mid]);

    // Recursively build the left and right subtrees
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}

// Function to balance a BST
struct Node* balanceBST(struct Node* root) {
    int nodes[100]; // Assuming a maximum of 100 nodes for simplicity
    int index = 0;

    // Store the nodes in sorted order
    storeInorder(root, nodes, &index);

    // Build the balanced tree from the sorted nodes
    return buildBalancedTree(nodes, 0, index - 1);
}

// Function to print the tree (Inorder Traversal)
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Constructing an unbalanced BST
    //        10
    //       /  \
    //      5    15
    //     /       \
    //    2         20
    //   /
    //  1

    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(2);
    root->left->left->left = newNode(1);
    root->right = newNode(15);
    root->right->right = newNode(20);

    struct Node* balancedRoot = balanceBST(root);
    printf("Inorder traversal of balanced BST: ");
    inorder(balancedRoot);
    printf("\n");

    return 0;
}
