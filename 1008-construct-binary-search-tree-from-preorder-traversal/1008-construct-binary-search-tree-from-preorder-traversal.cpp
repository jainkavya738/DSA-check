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
    int i = 0;
    TreeNode* helper(vector<int>& pre, int bound){
        if(i >= pre.size() || pre[i] > bound) return NULL;

        TreeNode* root = new TreeNode(pre[i++]);

        root->left = helper(pre, root->val);
        root->right = helper(pre, bound);

        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MAX);
    }
};