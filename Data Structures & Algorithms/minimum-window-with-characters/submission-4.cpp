class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        int m = s.length();
        int n = t.length();
        int count = n;
        int i = 0;
        int j = 0;
        int window_size = INT_MAX;
        unordered_map<char, int> mp;
        int start_i = 0;

        for (const auto& c : t) {
            mp[c]++;
        }

        while (j < m) {
            if (mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;

            while (count == 0) {
                int current_window_size = j - i + 1;
                if (current_window_size < window_size) {
                    window_size = current_window_size;
                    start_i = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }

            j++;
        }
        return window_size == INT_MAX ? "" : s.substr(start_i, window_size);
    }
};
