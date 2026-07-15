class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        rec(candidates, target, 0, curr, result);
        return result;
    }

   private:
    void rec(vector<int>& candidates, int target, int idx, vector<int> curr,
             vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        if (idx == candidates.size() || candidates[idx] > target) return;

        // --- SKIP branch: skip candidates[idx] AND every duplicate of it ---
        int next = idx + 1;
        while (next < candidates.size() && candidates[next] == candidates[idx]) {
            next++;
        }
        rec(candidates, target, next, curr, result);


        // --- PICK branch: take candidates[idx] ---
        curr.push_back(candidates[idx]);
        rec(candidates, target - candidates[idx], idx + 1, curr, result);
    }
};