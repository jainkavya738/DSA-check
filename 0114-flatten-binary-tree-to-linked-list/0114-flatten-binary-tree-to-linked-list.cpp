/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* nextRight = NULL; 
    // Last Visited Node-> Yhe connection krta hai left subtree aur right subtree k beech ka
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->right);  
        // Yhe ulta sochna zaroori hai.... taaki connection ho paaye easily left subtree aur right subtree ka
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};