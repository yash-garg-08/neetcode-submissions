class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<int> s1f(26, 0);
        vector<int> s2f(26, 0);

        for (char& ch : s1) {
            s1f[ch - 'a']++;
        }
        int i = 0, j = 0;

        while (j < m) {
            s2f[s2[j] - 'a']++;
            if (j - i + 1 > n) {
                s2f[s2[i] - 'a']--;
                i++;
            }
            if (s1f == s2f) return true;
            j++;
        }
        return false;
    }
};
