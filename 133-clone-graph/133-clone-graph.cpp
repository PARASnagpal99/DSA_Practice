/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private : 
    unordered_map<Node*,Node*>copiedNodes;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return node ;
        if(copiedNodes.find(node)==copiedNodes.end()){
            copiedNodes[node] = new Node(node->val,{});
            for(auto adj : node->neighbors){
                copiedNodes[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return copiedNodes[node] ;
    }
};