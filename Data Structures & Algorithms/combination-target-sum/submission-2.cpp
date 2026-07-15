class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        recTakeNotTake(nums, target, 0, curr, result);
        return result;
    }

private:
    void recLoop(vector<int>& nums, int target, int idx,
             vector<int>& curr, vector<vector<int>>& result)
    {
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > target) break; // sorted, so nothing further can fit either
            curr.push_back(nums[i]);
            recLoop(nums, target - nums[i], i, curr, result); // same i → reuse allowed
            curr.pop_back();
        }
    }

    void recTakeNotTake(vector<int>& nums, int target, int idx,
             vector<int>& curr, vector<vector<int>>& result)
    {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        if (idx == nums.size() || nums[idx] > target) return;

        // PICK nums[idx] — stay at idx (reuse allowed)
        curr.push_back(nums[idx]);
        recTakeNotTake(nums, target - nums[idx], idx, curr, result);
        curr.pop_back();

        // SKIP nums[idx] entirely — move on, never use this value again
        recTakeNotTake(nums, target, idx + 1, curr, result);
    }
};