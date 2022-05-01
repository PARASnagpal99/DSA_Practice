class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int>st ;
        st.insert(candyType.begin(),candyType.end());
        int x = st.size();
        int ans = min(x,n/2);
        return ans ;
    }
};