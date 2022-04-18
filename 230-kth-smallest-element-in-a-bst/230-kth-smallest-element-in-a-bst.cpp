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
private: 
    vector<int>arr ; 
public:
    void dfs(TreeNode* root){
        if(root!=NULL) {
        dfs(root->left) ;
        arr.push_back(root->val) ;
        dfs(root->right) ;
        }
     }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root) ;
        // sort(arr.begin(), arr.end()) ;
        return arr[k-1] ;
    }
};