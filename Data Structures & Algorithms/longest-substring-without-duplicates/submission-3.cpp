class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxi = 0;
        while (i < n && j < n) {
            while (mp[s[i]] > 0) {
                mp[s[j]]--;
                j++;
            }
            maxi = max(maxi, i - j + 1);
            mp[s[i]]++;
            i++;
        }
        return maxi;
    }
};
