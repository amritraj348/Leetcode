class Solution {
public:

    bool f(int ind, vector<int>& nums, int target,
           vector<vector<int>>& dp) {

        // We found the required sum
        if (target == 0)
            return true;

        // No elements left
        if (ind == 0)
            return nums[0] == target;

        // Already calculated
        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Don't take current element
        bool notTake = f(ind - 1, nums, target, dp);

        // Take current element
        bool take = false;

        if (nums[ind] <= target) {
            take = f(ind - 1, nums, target - nums[ind], dp);
        }

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        // If total sum is odd, equal partition is impossible
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, nums, target, dp);
    }
};