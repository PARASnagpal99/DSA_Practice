class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it =  upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        return letters[it%letters.size()] ;
    }
};