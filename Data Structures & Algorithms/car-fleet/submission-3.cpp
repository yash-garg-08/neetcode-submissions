class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pos_spd;

        for (int i = 0; i < n; i++) {
            pos_spd.push_back({position[i], speed[i]});
        }
        sort(pos_spd.rbegin(), pos_spd.rend());

        vector<double> st;

        for (const auto& p : pos_spd) {
            st.push_back((double)(target - p.first) / p.second);
            if (st.size() >= 2 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }
        return st.size();
    }
};
