class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int n=nums.size();
       int maxi=INT_MIN;

       for(int i=0;i<n;i++){
        maxi=max(nums[i],maxi);
       }

       int low=1;
       int high=maxi;
       int ans=0;

       while(low<=high){
        int mid=low+(high-low)/2;

        int m=0;
        for(int i=0;i<n;i++){
            m+=ceil((double)nums[i]/mid);
        }
        if(m<=threshold){
             high=mid-1;
             ans=mid;
        }
        else low=mid+1;
       }
       return ans;
    }
};