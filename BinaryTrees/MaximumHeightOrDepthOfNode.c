#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new Binary Tree Node
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find the depth of a given node in a Binary Tree
int findDepth(struct Node* root, int x) {
    // Base case
    if (root == NULL)
        return -1;

    // Initialize distance as -1
    int dist = -1;

    // Check if x is current node or is in left or right subtree
    if ((root->data == x)
        || (dist = findDepth(root->left, x)) >= 0
        || (dist = findDepth(root->right, x)) >= 0)

        // Return depth of the node
        return dist + 1;

    return dist;
}

// Helper function to find the height of a given node in the binary tree
int findHeightUtil(struct Node* root, int x, int* height) {
    // Base Case
    if (root == NULL) {
        return -1;
    }

    // Store the maximum height of the left and right subtree
    int leftHeight = findHeightUtil(root->left, x, height);
    int rightHeight = findHeightUtil(root->right, x, height);

    // Update height of the current node
    int ans = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    // If current node is the required node
    if (root->data == x)
        *height = ans;

    return ans;
}

// Function to find the height of a given node in a Binary Tree
int findHeight(struct Node* root, int x) {
    // Store the height of the given node
    int h = -1;

    // Stores height of the Tree
    findHeightUtil(root, x, &h);

    // Return the height
    return h;
}

// Driver Code
int main() {
    // Binary Tree Formation
    struct Node* root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->left->right->right = newNode(45);
    root->right->left = newNode(30);
    root->right->right = newNode(35);

    int k = 25;

    // Function call to find the depth of a given node
    printf("Depth: %d\n", findDepth(root, k));

    // Function call to find the height of a given node
    printf("Height: %d\n", findHeight(root, k));

    return 0;
}
