class Solution {
   public:
    // Backtracking function to generate all possible permutations
    void loopRec(vector<int>& nums, vector<int>& curr, unordered_set<int>& s,
                 vector<vector<int>>& res) {
        // Base case:
        // If the current permutation has the same size as the input,
        // we have formed one complete permutation.
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        // Try placing every number in the current position
        for (int i = 0; i < nums.size(); i++) {
            // If this number has not been used in the current permutation,
            // choose it.
            if (s.find(nums[i]) == s.end()) {
                // Mark the number as used
                s.insert(nums[i]);

                // Add it to the current permutation
                curr.push_back(nums[i]);

                // Recursively build the remaining positions
                loopRec(nums, curr, s, res);

                // ---------------- Backtracking ----------------
                // Remove the last chosen number so that we can
                // try another choice for this position.
                s.erase(nums[i]);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // Stores all permutations
        vector<vector<int>> res;

        // Stores the permutation currently being built
        vector<int> curr;

        // Keeps track of which numbers have already been used
        // in the current permutation.
        unordered_set<int> s;

        // Start generating permutations
        loopRec(nums, curr, s, res);

        return res;
    }
};