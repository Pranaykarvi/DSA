
//Using DFS


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


// BFS

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Structure for a stack node
struct StackNode {
    struct Node* treeNode;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newStackNode(struct Node* treeNode) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->treeNode = treeNode;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a tree node onto the stack
void push(struct StackNode** top, struct Node* treeNode) {
    struct StackNode* stackNode = newStackNode(treeNode);
    stackNode->next = *top;
    *top = stackNode;
}

// Function to check if the stack is empty
int isStackEmpty(struct StackNode* top) {
    return top == NULL;
}

// Function to pop a tree node from the stack
struct Node* pop(struct StackNode** top) {
    if (isStackEmpty(*top))
        return NULL;

    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct Node* popped = temp->treeNode;
    free(temp);
    return popped;
}

// Function to print leaf nodes from left to right
void printLeafNodes(struct Node* root) {
    // Base case
    if (!root)
        return;

    // Implement iterative preorder traversal to find leaf nodes
    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isStackEmpty(stack)) {
        root = pop(&stack);

        // If node is a leaf node, print its data
        if (!root->left && !root->right)
            printf("%d ", root->data);

        // Push right child first so left child is processed first
        if (root->right)
            push(&stack, root->right);
        if (root->left)
            push(&stack, root->left);
    }
}

// Driver program to test above functions
int main() {
    // Create a binary tree
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


