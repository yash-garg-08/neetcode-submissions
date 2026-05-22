class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        unordered_set<char> un;
        un.insert(s[0]);
        int i = 0;
        int j = 1;
        int maxLen = 1;
        while (j < n) {
            if (un.find(s[j]) != un.end()) {
                un.erase(s[i]);
                i++;
            } else {
                un.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
        }
        return maxLen;
    }
};
