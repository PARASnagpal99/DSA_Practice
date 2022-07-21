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
    unordered_map<TreeNode*,int> dp ;
    
    int func(TreeNode* root){
        if(!root) return 0 ;
        
        if(dp.count(root)) return dp[root] ;
        
        int ans = 0 ;
        
        int notTake = rob(root->left) + rob(root->right) ;
        
        int take = (root->val) ;
        
        if(root->left) take += ( rob(root->left->left)  + rob(root->left->right) ) ;
        if(root->right) take += ( rob(root->right->left) + rob(root->right->right) ) ;
        
        ans = max(take,notTake) ;
        return dp[root] = ans ;
    }
    
    int rob(TreeNode* root) {
       int ans = func(root) ;
       return ans ;
    }
};