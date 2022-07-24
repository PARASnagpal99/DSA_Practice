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
    // At every node we have two choices , its left or right subtree can be part of diameter or longer one is part of diameter 
    // in short either diameter can pass through it only or its half part . 
    
    int func(TreeNode* root , int &res){
        if(root == nullptr) return 0 ; // base case 
        
        int l = func(root->left,res);
        int r = func(root->right,res);
        
        int temp = max(l,r) + 1 ; // if diameter not passes through it ;
        int ans =  max(temp , 1 + l + r) ; // 1 + l + r means diamter passes through it ;
        res = max(res,ans) ;
        
        return temp ;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0 ;
        int res = 0 ;
        func(root,res);
        return res - 1 ;
    }
};