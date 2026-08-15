class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
         int low=1;
         int high=maxi;
         int ans=0;
         while(low<=high){
            int mid=low+(high-low)/2;

            long long totalHrs=0;

            for(int i=0;i<n;i++){
           totalHrs+=ceil((double)piles[i]/mid);
            }

            if(totalHrs<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
         }
         return ans;
    }
};