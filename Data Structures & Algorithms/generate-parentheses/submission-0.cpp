class Solution {
   public:
    void rec(int idx, vector<string>& res, string s, stack<string> stk, int n) {
        if (idx == 2 * n) {
            if (stk.empty()) {
                res.push_back(s);
            }
            return;
        }

        // select left paranthesis
        string left = "(";
        stk.push("(");
        rec(idx + 1, res, s + left, stk, n);

        // undo
        stk.pop();

        // select right paranthesis
        string right = ")";
        if (!stk.empty() && stk.top() == "(") {
            stk.pop();
        } else {
            stk.push(")");
        }
        rec(idx + 1, res, s + right, stk, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        stack<string> stk;

        rec(0, res, s, stk, n);

        return res;
    }
};
