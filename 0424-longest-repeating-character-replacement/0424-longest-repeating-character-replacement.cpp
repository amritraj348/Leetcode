class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxi=0;
        int maxFreq=0;
        vector<int>hash(26,0);
        while(r<n){
            hash[s[r]-'A']++;

            maxFreq=max(maxFreq,hash[s[r]-'A']);

            if((r-l+1)-maxFreq>k){
                hash[s[l]-'A']--;
                l++;
            }
             if((r-l+1)-maxFreq<=k){
                maxi=max(r-l+1,maxi);
            }
            r++;

        }
        return maxi;
    }
};