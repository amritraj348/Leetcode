class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ans=0;
        vector<bool>used(n,false);
        for(auto it:fruits){
            bool placed=false;

            for(int i=0;i<n;i++){
                if(!used[i]&&baskets[i]>=it){
                    used[i]=true;
                    placed=true;
                    break;
                }
            }
            if(!placed){
                ans++;
            }
        }
        return ans;
    }
};