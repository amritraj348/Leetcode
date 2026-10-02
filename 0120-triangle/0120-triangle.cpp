class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        // Last row
        if(i == triangle.size() - 1)
            return triangle[i][j];

        // Already calculated
        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        int down = triangle[i][j] +
                   solve(i + 1, j, triangle, dp);

        int diagonal = triangle[i][j] +
                       solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return solve(0, 0, triangle, dp);
    }
};