#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Structure for queue node
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Structure for queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a tree node
void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue a tree node
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    struct QueueNode* temp = q->front;
    struct Node* treeNode = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return treeNode;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to delete the deepest node in binary tree
void deleteDeepest(struct Node* root, struct Node* dNode) {
    struct Queue* q = createQueue();
    enqueue(q, root);

    struct Node* curr;
    while (!isQueueEmpty(q)) {
        curr = dequeue(q);

        if (curr == dNode) {
            curr = NULL;
            free(dNode);
            return;
        }

        if (curr->right) {
            if (curr->right == dNode) {
                curr->right = NULL;
                free(dNode);
                return;
            }
            enqueue(q, curr->right);
        }

        if (curr->left) {
            if (curr->left == dNode) {
                curr->left = NULL;
                free(dNode);
                return;
            }
            enqueue(q, curr->left);
        }
    }
    free(q);
}

// Function to delete the node with the given key
struct Node* deletion(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    struct Queue* q = createQueue();
    enqueue(q, root);

    struct Node* curr = NULL;
    struct Node* keyNode = NULL;

    while (!isQueueEmpty(q)) {
        curr = dequeue(q);

        if (curr->data == key) {
            keyNode = curr;
        }

        if (curr->left) {
            enqueue(q, curr->left);
        }

        if (curr->right) {
            enqueue(q, curr->right);
        }
    }

    if (keyNode != NULL) {
        int x = curr->data;
        keyNode->data = x;
        deleteDeepest(root, curr);
    }

    free(q);
    return root;
}

// Inorder traversal of the binary tree
void inorder(struct Node* curr) {
    if (!curr) {
        return;
    }

    inorder(curr->left);
    printf("%d ", curr->data);
    inorder(curr->right);
}

int main() {
    // Construct the binary tree
    //       10
    //      /  \
    //    11    9
    //   / \   / \
    //  7  12 15  8

    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->right = newNode(9);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    int key = 11;

    // Delete the node with the given key
    root = deletion(root, key);

    // Print the inorder traversal of the tree
    inorder(root);

    return 0;
}
