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
            // if they meet then cycle detected
            if (slow == fast) {
                break;
            }
        }

        // after cycle detection leave fast as their postion
        // and restart slow from zero
        // where they meet is the starting point of cycle
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