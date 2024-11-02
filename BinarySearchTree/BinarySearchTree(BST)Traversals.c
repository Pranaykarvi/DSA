//inorder
#include <stdio.h>
#include <stdlib.h>

// Structure describing a node of the tree
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

// Inorder Traversal
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    // Traverse left subtree
    printInorder(node->left);

    // Visit node
    printf("%d ", node->data);

    // Traverse right subtree
    printInorder(node->right);
}

// Driver code
int main() {
    // Build the tree
    struct Node* root = newNode(100);
    root->left = newNode(20);
    root->right = newNode(200);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->left = newNode(150);
    root->right->right = newNode(300);

    // Function call
    printf("Inorder Traversal: ");
    printInorder(root);
    printf("\n");

    return 0;
}
//preordr
#include <stdio.h>
#include <stdlib.h>

// Structure describing a node of the tree
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

// Preorder Traversal
void printPreOrder(struct Node* node) {
    if (node == NULL)
        return;

    // Visit node
    printf("%d ", node->data);

    // Traverse left subtree
    printPreOrder(node->left);

    // Traverse right subtree
    printPreOrder(node->right);
}

// Driver code
int main() {
    // Build the tree
    struct Node* root = newNode(100);
    root->left = newNode(20);
    root->right = newNode(200);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->left = newNode(150);
    root->right->right = newNode(300);

    // Function call
    printf("Preorder Traversal: ");
    printPreOrder(root);
    printf("\n");

    return 0;
}
//postorder

#include <stdio.h>
#include <stdlib.h>

// Structure to define a node
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

// PostOrder Traversal
void printPostOrder(struct Node* node) {
    if (node == NULL)
        return;

    // Traverse left subtree
    printPostOrder(node->left);

    // Traverse right subtree
    printPostOrder(node->right);

    // Visit node
    printf("%d ", node->data);
}

// Driver code
int main() {
    struct Node* root = newNode(100);
    root->left = newNode(20);
    root->right = newNode(200);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->left = newNode(150);
    root->right->right = newNode(300);

    // Function call
    printf("PostOrder Traversal: ");
    printPostOrder(root);
    printf("\n");

    return 0;
}
