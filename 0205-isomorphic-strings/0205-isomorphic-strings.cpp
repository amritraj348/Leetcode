class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>mpp1(256,0);
         vector<int>mpp2(256,0);

         for(int i=0;i<s.size();i++){
            if(mpp1[s[i]]!=mpp2[t[i]]) return false;


         mpp1[s[i]]=i+1;
         mpp2[t[i]]=i+1;
    }
    return true;
    }
};