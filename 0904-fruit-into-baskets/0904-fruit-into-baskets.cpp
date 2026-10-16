class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mpp;
        int n=fruits.size();
        int l=0;
        int r=0;
        int k=2;
        int maxi=0;
        while(r<n){
            mpp[fruits[r]]++;

            if(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;

            }
            if(mpp.size()<=k){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};