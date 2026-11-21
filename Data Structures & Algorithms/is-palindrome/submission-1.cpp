class Solution {
   public:
    bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length();

        while (l < r) {
            while (l < r && !isAlphanumeric(s[l])) {
                l++;
            }
            while (r > l && !isAlphanumeric(s[r])) {
                r--;
            }
            if( tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
