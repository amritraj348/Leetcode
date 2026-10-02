class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // First row
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Remaining rows
        for(int i = 1; i < m; i++) {

            for(int j = 0; j < n; j++) {

                int up = dp[i-1][j];

                int diagonal_left = 1e9;
                if(j > 0)
                    diagonal_left = dp[i-1][j-1];

                int diagonal_right = 1e9;
                if(j < n-1)
                    diagonal_right = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] +
                           min(up, min(diagonal_left, diagonal_right));
            }
        }

        // Minimum value in last row
        int ans = 1e9;

        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[m-1][j]);
        }

        return ans;
    }
};