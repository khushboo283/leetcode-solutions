class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> dp(
            m * n, vector<bool>(1024, false)
        );

        auto idx = [&](int i, int j) {
            return i * n + j;
        };

        dp[idx(0, 0)][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                int val = grid[i][j];

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[idx(i - 1, j)][x]) {
                            dp[idx(i, j)][x ^ val] = true;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[idx(i, j - 1)][x]) {
                            dp[idx(i, j)][x ^ val] = true;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[idx(m - 1, n - 1)][x])
                return x;
        }

        return -1;
    }
};