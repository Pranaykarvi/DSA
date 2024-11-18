// C program to find the maximum depth of a binary 
// tree using depth-first search (DFS) approach.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}; 

// Returns "maxDepth" which is the number of nodes 
// along the longest path from the root node down 
// to the farthest leaf node.
int maxDepth(struct Node* node) {
    if (node == NULL)
        return 0;

    // compute the depth of left and right subtrees
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    return (lDepth > rDepth ? lDepth : rDepth) + 1;
}

struct Node* createNode(int val) {
    struct Node* node 
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
  
    // Representation of the input tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("%d\n", maxDepth(root));
    
    return 0;
}
