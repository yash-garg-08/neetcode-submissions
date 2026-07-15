class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        rec(nums, target, 0, curr, result);
        return result;
    }

private:
    void rec(vector<int>& nums, int target, int idx,
             vector<int>& curr, vector<vector<int>>& result)
    {
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > target) break; // sorted, so nothing further can fit either
            curr.push_back(nums[i]);
            rec(nums, target - nums[i], i, curr, result); // same i → reuse allowed
            curr.pop_back();
        }
    }
};