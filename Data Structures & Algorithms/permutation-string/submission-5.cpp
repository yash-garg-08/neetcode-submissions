class Solution {
   public:
    bool checkPerm(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return (s1 == s2);
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int l = 0;
        int r = s1.length() - 1;

        while (r < s2.length()) {
            if (checkPerm(s1, s2.substr(l, r - l + 1))) {
                return true;
            }
            r++;
            l++;
        }
        return false;
    }
};
