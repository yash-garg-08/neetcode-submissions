class Solution {
public:
    int n;
    bool validatePalindrome(string s){
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void rec(string s, int idx, vector<vector<string>>& res, vector<string>& curr){
        if(idx == n){
            res.push_back(curr);
            return;
        }

        for(int i = idx; i < n; i++){
            if(validatePalindrome(s.substr(idx, i - idx + 1))){
                curr.push_back(s.substr(idx, i - idx + 1));
                rec(s, i+1, res, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> res;
        vector<string> curr;
        rec(s, 0, res, curr);
        return res;
    }
};
