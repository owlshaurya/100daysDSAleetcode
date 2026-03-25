/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root,
                                      struct TreeNode* p,
                                      struct TreeNode* q) {

    if(root == NULL)
        return NULL;

    // If both nodes smaller → go left
    if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both nodes greater → go right
    if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise this is LCA
    return root;
}