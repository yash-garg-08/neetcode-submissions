class Solution {
   public:
    // Backtracking function to generate all unique combinations
    void rec(vector<int>& candidates,
             int target,                   // Remaining target sum
             int idx,                      // Start index for this recursion
             vector<int>& curr,            // Current combination being built
             vector<vector<int>>& result)  // Stores all valid combinations
    {
        // If target becomes negative, this combination is invalid
        if (target < 0) return;

        // If target becomes 0, we found a valid combination
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        // Try every candidate starting from the current index
        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level.
            // Example:
            // candidates = [1,2,2,5]
            // After considering the first '2', skip the second '2'
            // to avoid generating duplicate combinations.
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            // Choose the current number
            curr.push_back(candidates[i]);

            // Recurse with:
            // - reduced target
            // - next index (i + 1) because each number can only be used once
            rec(candidates, target - candidates[i], i + 1, curr, result);

            // Backtrack: remove the last chosen element
            // so we can try the next candidate
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        // Sort the array so:
        // 1. Duplicate elements become adjacent.
        // 2. We can efficiently skip duplicate combinations.
        sort(begin(candidates), end(candidates));

        // Start backtracking from index 0
        rec(candidates, target, 0, curr, result);

        return result;
    }
};