class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int majority=-1;
        for(int i=0;i<n;i++){

            if(cnt==0){
                cnt++;
                majority=nums[i];
            }

            else if(nums[i]==majority){
                cnt++;
            }

            else{
                cnt--;
            }
        }

        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majority){
                cnt1++;
            }
        }
        
        if(cnt1>n/2){
            return majority;
        }
        return -1;
    }
};