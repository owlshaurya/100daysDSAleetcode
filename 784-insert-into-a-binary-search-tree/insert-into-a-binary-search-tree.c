/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {

    // If tree is empty → create new node
    if(root == NULL) {
        struct TreeNode* newnode =
            (struct TreeNode*)malloc(sizeof(struct TreeNode));

        newnode->val = val;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    // Go left
    if(val < root->val)
        root->left = insertIntoBST(root->left, val);

    // Go right
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}