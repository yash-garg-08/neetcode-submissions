class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        vector<int> output;
        int count_zero = 0;

        for (const auto& num : nums) {
            if (num == 0) {
                count_zero++;
                if (count_zero > 1) {
                    vector<int> out_res_for_zero(n, 0);
                    return out_res_for_zero;
                }
            } else {
                prod *= num;
            }
        }

        if (count_zero == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    output.push_back(prod);
                } else {
                    output.push_back(0);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                output.push_back(prod / nums[i]);
            }
        }

        return output;
    }
};
