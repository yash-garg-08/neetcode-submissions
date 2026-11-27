class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char, int> mp;
        // int n = s.length();
        // int i = 0;
        // int j = 0;
        // int maxi = 0;
        // while (i < n && j < n) {
        //     while (mp[s[i]] > 0) {
        //         mp[s[j]]--;
        //         j++;
        //     }
        //     maxi = max(maxi, i - j + 1);
        //     mp[s[i]]++;
        //     i++;
        // }
        // return maxi;

        unordered_map<char, int> mp;
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.length(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l);
            }
            res = max(res, r - l + 1);
            mp[s[r]] = r;
        }
        return res;
    }
};
