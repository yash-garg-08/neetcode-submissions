class Solution {
   public:
    vector<vector<int>> res;
    int n;
    void findSum(vector<int>& nums, int target, int i, vector<int> val) {
        if (target == 0) {
            res.push_back(val);
            return;
        }
        if (i == n) return;

        // not take
        findSum(nums, target, i + 1, val);

        // take
        if (nums[i] <= target) {
            val.push_back(nums[i]);
            findSum(nums, target - nums[i], i, val);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> val;
        findSum(nums, target, 0, val);
        return res;
    }
};
