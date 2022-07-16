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
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res ;
        if(!root) return res ;
        
        stack<TreeNode*>stk1 ;
        
        stk1.push(root) ;
        
        while(!stk1.empty()){
            root = stk1.top() ;
            stk1.pop() ;
            
            res.push_back(root->val) ;
            
            if(root->left){
                stk1.push(root->left) ;
            }
            
             if(root->right){
                stk1.push(root->right) ;
            }
            
            
        }
        
        
//         while(!stk2.empty()){
//              auto curr = stk2.top() ;
//              res.push_back(curr->val);
//              stk2.pop() ;
//         }
        reverse(res.begin(),res.end());
        return res ;
        
    }
};