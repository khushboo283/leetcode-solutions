
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool normal = true, reversed = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i)
                normal = false;

            if (nums[(pos - i + n) % n] != i)
                reversed = false;
        }

        int ans = INT_MAX;

        if (normal)
            ans = min(pos, n - pos + 2);

        if (reversed)
            ans = min(ans, 1 + min(n - 1 - pos, pos + 1));

        return ans == INT_MAX ? -1 : ans;
    }
};
