class Solution {
   public:
    void recTakeNotTake(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int> curr,
                        set<vector<int>>& s) {
        if (idx == nums.size()) {
            sort(curr.begin(), curr.end());

            if (s.find(curr) == s.end()) {
                res.push_back(curr);
                s.insert(curr);
            }
            return;
        }

        // not take
        recTakeNotTake(nums, idx + 1, res, curr, s);
        // take
        curr.push_back(nums[idx]);
        recTakeNotTake(nums, idx + 1, res, curr, s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        set<vector<int>> s;
        recTakeNotTake(nums, 0, res, curr, s);
        return res;
    }
};
