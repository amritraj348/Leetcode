class Solution {
public:

void f(int i,vector<int>&nums,vector<int>&sub,vector<vector<int>>&ans){
    if(i==nums.size()){
        ans.push_back(sub);
        return;
    }
    sub.push_back(nums[i]);
    f(i+1,nums,sub,ans);

    sub.pop_back();
    f(i+1,nums,sub,ans);


}

    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();
        vector<int>sub;
        vector<vector<int>>ans;
        f(0,nums,sub,ans);
        
        return ans;


    }
};