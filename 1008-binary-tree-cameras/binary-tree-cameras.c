#include <stdlib.h>

int cameras = 0;

// DFS
int dfs(struct TreeNode* root) {
    if(root == NULL)
        return 2; // covered

    int left = dfs(root->left);
    int right = dfs(root->right);

    // If any child needs camera
    if(left == 0 || right == 0) {
        cameras++;
        return 1; // has camera
    }

    // If any child has camera
    if(left == 1 || right == 1)
        return 2; // covered

    return 0; // needs camera
}

// Main function
int minCameraCover(struct TreeNode* root) {
    cameras = 0; // IMPORTANT reset

    if(dfs(root) == 0)
        cameras++;

    return cameras;
}