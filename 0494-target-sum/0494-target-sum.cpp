class Solution {
public:
    int solve(int ind, int sum, vector<int>& nums,
              int target, vector<vector<int>>& dp) {

        if(ind == nums.size()) {
            return sum == target;
        }

        if(dp[ind][sum + 1000] != -1)
            return dp[ind][sum + 1000];

        int plus = solve(ind + 1, sum + nums[ind],
                         nums, target, dp);

        int minus = solve(ind + 1, sum - nums[ind],
                          nums, target, dp);

        return dp[ind][sum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2001, -1));

        return solve(0, 0, nums, target, dp);
    }
};