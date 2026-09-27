class Solution {
public:

    int solve(int ind, int start, vector<int>& nums, vector<int>& dp) {

        if(ind < start)
            return 0;

        if(ind == start)
            return nums[start];

        if(dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + solve(ind - 2, start, nums, dp);

        int notPick = solve(ind - 1, start, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Case 1: Don't rob first
        int case1 = solve(n - 1, 1, nums, dp1);

        // Case 2: Don't rob last
        int case2 = solve(n - 2, 0, nums, dp2);

        return max(case1, case2);
    }
};