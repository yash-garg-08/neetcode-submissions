class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // treating value of array as indexes and looping
        // through them with slow and fast pointer 
        // until they meet
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        slow = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast) {
                return slow;
            }
        }
    }
};