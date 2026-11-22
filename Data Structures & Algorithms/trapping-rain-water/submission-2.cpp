class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        // vector<int> left_max(n);
        // vector<int> right_max(n);

        // left_max[0] = height[0];
        // for (int i = 1; i < n; i++) {
        //     left_max[i] = max(left_max[i - 1], height[i]);
        // }

        // right_max[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; i--) {
        //     right_max[i] = max(right_max[i + 1], height[i]);
        // }

        // int res = 0;
        // for(int i=0; i<n; i++){
        //     res += min(left_max[i], right_max[i]) - height[i];
        // }

        // return res;

        int res = 0;
        int l = 0;
        int r = n-1;
        int left_max = 0;
        int right_max = 0;

        while(l < r){
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);

            if(left_max < right_max){
                res += left_max - height[l];
                l++;
            }else{
                res += right_max - height[r];
                r--;
            }
        }

        return res;

    }
};
