
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));

        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long right = dp[i][j][0];
                long long down = dp[i][j][1];

                if (i == 0 && j == 0)
                    right = 1;

                if (grid[i][j] == 1) {

                    if (right && i + 1 < m) {
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + right) % MOD;
                    }

                    if (down && j + 1 < n) {
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + down) % MOD;
                    }

                    continue;
                }

                long long ways = (right + down) % MOD;

                if (j + 1 < n) {
                    if (grid[i][j + 1] == 0) {
                        dp[i][j + 1][0] = (dp[i][j + 1][0] + ways) % MOD;
                    }
                    else if (i + 1 < m) {
                        dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + ways) % MOD;
                    }
                }

                if (i + 1 < m) {
                    if (grid[i + 1][j] == 0) {
                        dp[i + 1][j][1] = (dp[i + 1][j][1] + ways) % MOD;
                    }
                    else if (j + 1 < n) {
                        dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + ways) % MOD;
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};
