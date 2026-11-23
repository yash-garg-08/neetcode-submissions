class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push({temperatures[i], i});
            } else {
                while (!st.empty() && st.top().first < temperatures[i]) {
                    res[st.top().second] = i - st.top().second;
                    st.pop();
                }
                st.push({temperatures[i], i});
            }
        }
        return res;
    }
};
