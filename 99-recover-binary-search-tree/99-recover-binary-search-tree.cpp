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
    void dfs(TreeNode* root , vector<int> &nums){
        if(!root) return ;
        dfs(root->left,nums);
        nums.push_back(root->val);
        dfs(root->right,nums);
    }
    
    void dfs2(TreeNode* root , vector<int> &nums , int& i){
        if(!root) return ;
        dfs2(root->left,nums,i);
        if(root->val!=nums[i]){
            root->val = nums[i] ;
        }
        i++;
        dfs2(root->right,nums,i);
    }
    
    
    
    void recoverTree(TreeNode* root) {
        vector<int> nums ;
        dfs(root,nums);
        sort(nums.begin(),nums.end());
        int i = 0 ;
        dfs2(root,nums,i);
        return ;
    }
};