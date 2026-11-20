class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;

        set<int> st;

        for(const auto& num : nums){
            st.insert(num);
        }

        vector<int> new_nums;

        for(int i : st){
            new_nums.push_back(i);
        }


        int new_size = new_nums.size();

        int count_max = 0;
        int count = 0;

        for(int i=1; i<new_size; i++){
            if(new_nums[i] == new_nums[i-1] + 1){
                count++;
                count_max = max(count_max, count);
            }else{
                count = 0;
            }
        }
        return count_max+1;
    }
};
