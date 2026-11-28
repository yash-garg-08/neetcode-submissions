#include <deque>
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // ====================Brute force approach====================

        // vector<int> res;
        // int l = 0;
        // int r = k - 1;
        // while (r < nums.size()) {
        //     int maxi = INT_MIN;
        //     for (int i = l; i <= r; i++) {
        //         maxi = max(maxi, nums[i]);
        //     }
        //     res.push_back(maxi);
        //     r++;
        //     l++;
        // }
        // return res;

        // ====================Optimal approach====================

        // This type of data structure is called monotoic Increasing/Decreasing
        // In this we store values in a data structe in Increasing/Decreasing order
        // Below we are using Monotoic Decreasing Deque means we storing data in our
        // Deque in decreasing order
        if (nums.size() == 1) return {nums[0]};
        vector<int> res;
        vector<int> index_arr;
        deque<int> dq;


        for (int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k - 1){
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
