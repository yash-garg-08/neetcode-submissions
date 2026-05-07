class MinStack {
   public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {}

    void push(int val) {
        st.push(val);
        val = min(val, min_st.empty() ? val : min_st.top());
        min_st.push(val);
    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};
