class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int op3 = op1 + op2;
                s.push(op3);
            } else if (tokens[i] == "-") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int op3 = op2 - op1;
                s.push(op3);
            } else if (tokens[i] == "*") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int op3 = op1 * op2;
                s.push(op3);
            } else if (tokens[i] == "/") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                int op3 = op2 / op1;
                s.push(op3);
            } else {
                int num = stoi(tokens[i]);
                s.push(num);
            }
        }
        return s.top();
    }
};
