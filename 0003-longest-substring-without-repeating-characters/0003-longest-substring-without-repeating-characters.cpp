class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int maxi=0;
        vector<int>hash(256,-1);
        for(int r=0;r<n;r++){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            hash[s[r]]=r;

            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};