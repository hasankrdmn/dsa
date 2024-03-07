#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;

    struct TreeNode *tmp = root -> right;
    root -> right = root -> left;
    root -> left = tmp;
    
    invertTree(root -> left);
    invertTree(root -> right);
    return root;
}
