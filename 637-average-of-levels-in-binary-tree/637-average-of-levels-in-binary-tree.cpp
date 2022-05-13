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
    vector<double> averageOfLevels(TreeNode* root) {
           vector<double>ans ;
            if(root==NULL){
                return ans ;
            }
            queue<TreeNode*>q ;
            q.push(root);
            while(!q.empty()){
                vector<int>temp ;
                int sz = q.size() ;
                double sum = 0 ;
                for(int i=0 ; i<sz ; ++i){
                    TreeNode* x = q.front() ;
                    q.pop() ;
                    temp.push_back(x->val);
                    sum+=(x->val);
                    if(x->left!=NULL){
                        q.push(x->left);
                    }                   
                    if(x->right!=NULL){
                        q.push(x->right);
                    }
                }
                ans.push_back(sum/temp.size());
                sum = 0 ;
            }
        return ans ;
    }
};