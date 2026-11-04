class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void add(int v) {
        if (low.empty() || v <= *low.rbegin()) {
            low.insert(v);
            sumLow += v;
        } else {
            high.insert(v);
            sumHigh += v;
        }
        balance();
    }

    void remove(int v) {
        auto it = low.find(v);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= v;
        } else {
            it = high.find(v);
            high.erase(it);
            sumHigh -= v;
        }

        balance();
    }

    void balance() {
        while (low.size() > high.size() + 1) {
            int v = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= v;

            high.insert(v);
            sumHigh += v;
        }

        while (low.size() < high.size()) {
            int v = *high.begin();
            high.erase(high.begin());
            sumHigh -= v;

            low.insert(v);
            sumLow += v;
        }
    }

    long long getCost() {
        long long m = *low.rbegin();

        return m * low.size() - sumLow
             + sumHigh - m * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, LLONG_MAX / 2);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), LLONG_MAX / 2);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            swap(prev, curr);
        }
        return prev[n];
    }
};
