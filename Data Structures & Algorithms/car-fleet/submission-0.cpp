class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            ps.push_back({position[i], speed[i]});
        }

        // sort based on first value of pair in desc order
        sort(ps.rbegin(), ps.rend());

        vector<double> st;

        for (int i = 0; i < n; i++) {
            double timeToReachTarget = ((double)(target - ps[i].first) / ps[i].second);
            st.push_back(timeToReachTarget);

            // id stack is bigger then one and
            // ttl of latest value is less then equals to last value
            // then remove the latest value as both of them become a fleet
            // and now moving with the speed of slower one
            if (st.size() >= 2 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }
        return st.size();
    }
};
