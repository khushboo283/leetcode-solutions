class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n && valid; start += k) {
                int descents = 0;

                for (int j = 0; j < k; ++j) {
                    int curr = start + j;
                    int next = start + (j + 1) % k;

                    if (nums[curr] > nums[next]) {
                        ++descents;
                    }
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                vector<int> block(nums.begin() + start,
                                  nums.begin() + start + k);
                vector<int> target(sorted.begin() + start,
                                   sorted.begin() + start + k);

                sort(block.begin(), block.end());

                if (block != target) {
                    valid = false;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};