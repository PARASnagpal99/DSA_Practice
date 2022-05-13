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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>>res ;
            if(root==NULL){
                return res ;
            }
            queue<TreeNode*>q ;
            q.push(root);
            while(!q.empty()){
                vector<int>temp ;
                int sz = q.size() ;
                for(int i=0 ; i<sz ; ++i){
                    TreeNode* x = q.front() ;
                    q.pop() ;
                    temp.push_back(x->val);
                    if(x->left!=NULL){
                        q.push(x->left);
                    }                   
                    if(x->right!=NULL){
                        q.push(x->right);
                    }
                }
                res.push_back(temp);
            }
        reverse(res.begin(),res.end());
        return res ;
    }
};