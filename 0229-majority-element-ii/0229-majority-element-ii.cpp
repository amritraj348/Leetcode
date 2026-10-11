class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        vector<int>l;
         int majority1;
        int majority2;
        for(int i=0;i<n;i++){
            if(cnt1==0&&nums[i]!=majority2){
                cnt1=1;
                majority1=nums[i];
            }
            else if(cnt2==0&&nums[i]!=majority1){
                cnt2=1;
                majority2=nums[i];
            }
            else if(majority1==nums[i]){
                cnt1++;
            }
            else if(majority2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int cnt3=0;
        int cnt4=0;
        for(int i=0;i<n;i++){
            if(majority1==nums[i]){
                cnt3++;
            }
            else if(majority2==nums[i]){
                cnt4++;
            }
        }
        if(cnt3>n/3){
            l.push_back(majority1);
        }
         if(cnt4>n/3){
            l.push_back(majority2);
        }
        return l;
    }
};