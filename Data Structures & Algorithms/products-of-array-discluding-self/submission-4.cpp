class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1);
        vector<int> suff(n, 1);

        int i = 1;
        int j = n - 2;

        while (i < n && j >= 0) {
            pref[i] = pref[i - 1] * nums[i - 1];
            suff[j] = suff[j + 1] * nums[j + 1];
            i++;
            j--;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(pref[i] * suff[i]);
        }
        return result;
    }
};
