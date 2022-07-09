/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
       int ht = 0 ;
       queue<Node*>q ;
       if(root!=NULL) q.push(root) ;
       
       while(!q.empty()){
            int sz = q.size() ;
            ht++;
            for(int i=0 ; i<sz ; ++i){
                auto node = q.front() ;
                q.pop() ;
                for(auto child : node->children) q.push(child) ;
            }
       }
        
       return ht ; 
    
    }
};