class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        // vector<vector<int>> all_rect;
        // int n = heights.size();

        // int maxi = 0;

        // for(int i=0; i<n; i++){
        //     int mini = INT_MAX;
        //     for(int j=i; j<n; j++){
        //         mini = min(mini, heights[j]);
        //         maxi = max(maxi, (j-i+1)*mini);
        //     }
        // }
        // return maxi;

        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> st;

        // left smaller value for each index
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // right smaller value for each index
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr_area = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans, curr_area);
        }

        return ans;
    }
};
