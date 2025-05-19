#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to count the number of nodes in the tree
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to check if the tree is a complete binary tree
bool isComplete(struct Node* root, int index, int nodeCount) {
    // If tree is empty, it's complete
    if (root == NULL)
        return true;

    // If index assigned to current node is greater than number of nodes, it's not complete
    if (index >= nodeCount)
        return false;

    // Recursively check left and right subtrees
    return isComplete(root->left, 2 * index + 1, nodeCount) &&
           isComplete(root->right, 2 * index + 2, nodeCount);
}

// Function to check if the tree satisfies the max heap property
bool isHeap(struct Node* root) {
    // Leaf nodes always satisfy heap property
    if (root->left == NULL && root->right == NULL)
        return true;

    // If right child is missing, check only left child
    if (root->right == NULL)
        return (root->data >= root->left->data) && isHeap(root->left);

    // If both children exist, check both
    if (root->data >= root->left->data &&
        root->data >= root->right->data &&
        isHeap(root->left) &&
        isHeap(root->right))
        return true;

    return false;
}

// Function to check if a binary tree is a heap
bool isBinaryHeap(struct Node* root) {
    int nodeCount = countNodes(root);
    return isComplete(root, 0, nodeCount) && isHeap(root);
}

// Driver Code
int main() {
    struct Node* root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);

    if (isBinaryHeap(root))
        printf("The given Binary Tree is a Heap.\n");
    else
        printf("The given Binary Tree is NOT a Heap.\n");

    return 0;
}