class Solution {
   public:
    bool checkAnamgram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();

        for (int i = 0; i + n <= s2.length(); i++) {
            if (checkAnamgram(s1, s2.substr(i, n))) {
                return true;
            }
        }
        return false;
    }
};
