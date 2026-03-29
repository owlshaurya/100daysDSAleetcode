void flatten(struct TreeNode* root) {
    if(root == NULL) return;

    struct TreeNode* stack[2000];
    int top = -1;

    stack[++top] = root;

    while(top != -1) {
        struct TreeNode* curr = stack[top--];

        if(curr->right)
            stack[++top] = curr->right;

        if(curr->left)
            stack[++top] = curr->left;

        if(top != -1)
            curr->right = stack[top];

        curr->left = NULL;
    }
}