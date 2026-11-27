class Solution {
   public:
    int characterReplacement(string s, int k) {
        // approach is create a window and keeps the windows most frequent elements value/count
        // stored with the most frequent count in the window stored we can use this formula to check
        // if by switching k or less values will we get out our string or not formula: window_size -
        // most_freq_element <= k we will reduce the window size until this formula meet

        int l = 0;
        int res = 0;
        int maxf = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < s.length(); r++) {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);

            while ((r - l + 1) - maxf > k) {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
