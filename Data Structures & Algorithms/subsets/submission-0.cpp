class Solution {
public:
    vector<vector<int>> res;
    int n;
    void makeSubset(vector<int>& nums, int i, vector<int> val){
        if(i == n){
            res.push_back(val);
            return;
        }
        // not take
         makeSubset(nums, i+1, val);
        // take
        val.push_back(nums[i]);
        makeSubset(nums, i+1, val);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> val;
        makeSubset(nums, 0, val);
        return res;
    }
};
