class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }

        if (arr1 == arr2) return true;

        int l = 0;

        for (int r = s1.length(); r < s2.length(); r++) {
            arr2[s2[r] - 'a']++;
            arr2[s2[l] - 'a']--;
            l++;
            if (arr1 == arr2) return true;
        }

        return false;
    }
};
