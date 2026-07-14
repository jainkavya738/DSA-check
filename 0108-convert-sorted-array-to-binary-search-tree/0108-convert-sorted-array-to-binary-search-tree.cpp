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
    TreeNode* insert(TreeNode* root, vector<int>& nums, int st, int end){
        if(st > end) return NULL;
        
        int mid = st + (end - st)/2;

        root = new TreeNode(nums[mid]);
        root->left = insert(root->left, nums, st, mid-1);
        root->right = insert(root->right, nums, mid+1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;

        root = insert(root, nums, 0, nums.size()-1);

        return root;
    }
};