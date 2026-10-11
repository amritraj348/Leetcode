class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
         sort(nums.begin(),nums.end());
        int maxi=1;
        int cntCurrent=0;
        int lastSmaller=INT_MIN;
        for(int i=0;i<n;i++){
            int x=nums[i];

            if(lastSmaller==(x-1)){
                cntCurrent+=1;
                lastSmaller=nums[i];
            }
            else if(lastSmaller!=x){
                cntCurrent=1;
                lastSmaller=nums[i];
            }

            maxi=max(maxi,cntCurrent);
        }
        return maxi;
    }
};