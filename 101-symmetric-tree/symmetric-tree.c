/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int isMirror(struct TreeNode* t1, struct TreeNode* t2) {

    if(t1 == NULL && t2 == NULL)
        return 1;

    if(t1 == NULL || t2 == NULL)
        return 0;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return true;

    return isMirror(root->left, root->right);
}