#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find LCA of two given nodes in a BST
struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    
    // If both n1 and n2 are smaller than root, LCA lies in left subtree
    if (n1 < root->val && n2 < root->val)
        return findLCA(root->left, n1, n2);
    
    // If both n1 and n2 are greater than root, LCA lies in right subtree
    if (n1 > root->val && n2 > root->val)
        return findLCA(root->right, n1, n2);
    
    // If one value is smaller and one is larger, current node is LCA
    return root;
}

// Helper function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    /* Construct the following BST
              20
             /  \
           10   30
          /  \    \
         5   15   40
    */
    struct TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->right = newNode(40);
    
    int n1 = 5, n2 = 15;
    struct TreeNode* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->val);
    else
        printf("LCA not found\n");
    
    return 0;
}
