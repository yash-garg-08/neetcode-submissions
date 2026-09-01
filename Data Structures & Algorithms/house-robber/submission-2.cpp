#include <cstring>
class Solution {
   public:
    int t[101];
    int rec(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int steal = nums[i] + rec(nums, i + 2);
        int skip = rec(nums, i + 1);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        // memset(t, -1, sizeof(t));
        // return rec(nums, 0);

        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            // max(steal, skip)
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }

        return dp[n];
    }
};
