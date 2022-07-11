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
    void func(TreeNode* root , vector<int> &res){
        if(!root) return ;
        func(root->left,res);
        func(root->right,res);
        res.push_back(root->val);
    }
    
    
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res ;
        if(!root) return res ;
        func(root,res) ;
        return res ;
    }
};