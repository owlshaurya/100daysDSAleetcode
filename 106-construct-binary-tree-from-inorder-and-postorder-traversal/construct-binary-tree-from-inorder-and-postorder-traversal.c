#include <stdlib.h>

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* build(int inorder[], int postorder[],
                       int start, int end, int* postIndex) {

    if(start > end)
        return NULL;

    int rootVal = postorder[(*postIndex)--];
    struct TreeNode* root = createNode(rootVal);

    if(start == end)
        return root;

    int index = findIndex(inorder, start, end, rootVal);

    // Build RIGHT first
    root->right = build(inorder, postorder, index + 1, end, postIndex);
    root->left = build(inorder, postorder, start, index - 1, postIndex);

    return root;
}

// Main function (LeetCode calls this)
struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}