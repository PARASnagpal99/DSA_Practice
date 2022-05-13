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
    vector<vector<int>> levelOrder(TreeNode* root) {
             vector<vector<int>>ans ;
             queue<TreeNode*>q ;
             if(root==NULL){
                 return ans ;
             }
             q.push(root) ;
             while(!q.empty()){
                 vector<int>temp ;
                 int sz = q.size() ;
                 for(int i=0 ; i<sz ; ++i){
                     TreeNode* x = q.front() ;
                     temp.push_back(x->val) ;
                     q.pop() ;
                     if(x->left!=NULL){
                         q.push(x->left) ;
                     }
                     if(x->right!=NULL){
                         q.push(x->right) ;
                     }
                 }
                 ans.push_back(temp) ;
             }
        return ans ;
    }
};