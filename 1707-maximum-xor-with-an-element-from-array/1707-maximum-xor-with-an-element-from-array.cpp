struct Node{
    Node* link[2] = {NULL};
    
    bool containsKey(int bit){
        return (link[bit] != NULL);
    }
    void put(int bit,Node* node){
        link[bit]= node;
    }
    Node* get(int bit){
        return link[bit];
    }

};

class Trie{
    private : Node* root ;
    public : 
    Trie(){
        root = new Node() ;
    }
    
    void insert(int num){
        Node* node = root ;
        
        for(int i=31 ; i>=0 ; i--){
            int bit ;
            if(num & (1 << i)){
                bit = 1 ;
            }else {
                bit = 0 ;
            }
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
             node = node->get(bit);
        }
       
    }
       
    int findMax(int num){
        Node* node = root ;
        int maxNum = 0 ;
        for(int i=31 ; i>=0 ; i--){ 
            int bit ;
            if(num & (1 << i)){
                bit = 1 ;
            }else {
                bit = 0 ;
            }
            
            if(node->containsKey(!bit)){
                maxNum = maxNum | (1 << i) ;
                node = node->get(!bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxNum ;
    }
        
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() , q = queries.size() ;
        
        Trie trie ;
        
        vector<pair<int,pair<int,int>>>OfflineQueries ;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0 ; i<q ; ++i){
            OfflineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
        
        int i = 0 ;
        
        sort(OfflineQueries.begin(),OfflineQueries.end());
        
        vector<int> ans(q,-1);
        
        for(auto &it : OfflineQueries){
            
            while(i < n && nums[i] <= it.first){
                trie.insert(nums[i]);
                i++;
            }
            
            if(i!=0) ans[it.second.second] = trie.findMax(it.second.first);
        }
        
        
        return ans ;
        
        
    }
};