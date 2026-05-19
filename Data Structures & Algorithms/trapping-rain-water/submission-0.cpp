class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, height[i]);
            left_max[i] = maxi;
        }

        maxi = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, height[i]);
            right_max[i] = maxi;
        }
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area += min(left_max[i], right_max[i]) - height[i];
        }
        return max_area;
    }
};
