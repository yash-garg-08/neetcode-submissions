class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        recTakeNotTake(candidates, target, 0, curr, result);
        return result;
    }

   private:
    void recLoop(vector<int>& candidates, int target, int idx, vector<int>& curr,
                 vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) break;  // sorted, nothing further fits
            if (i > idx && candidates[i] == candidates[i - 1]) continue;  // skip dup at this level

            curr.push_back(candidates[i]); // do
            recLoop(candidates, target - candidates[i], i + 1, curr, result);  // i+1 → no reuse // explore
            curr.pop_back(); // undo
        }
    }

    void recTakeNotTake(vector<int>& candidates, int target, int idx, vector<int>& curr,
                        vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        if (idx == candidates.size() || candidates[idx] > target) return;

        // PICK candidates[idx] — advance to idx+1 (no reuse)
        curr.push_back(candidates[idx]);
        recTakeNotTake(candidates, target - candidates[idx], idx + 1, curr, result);
        curr.pop_back();

        // SKIP candidates[idx] — jump past the ENTIRE run of duplicates in one move
        int next = idx + 1;
        while (next < candidates.size() && candidates[next] == candidates[idx]) {
            next++;
        }
        recTakeNotTake(candidates, target, next, curr, result);
    }
};