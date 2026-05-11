class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // using stack
        int n = temperatures.size();
        stack<pair<int, int>> s;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            if (!s.empty()) {
                while (!s.empty() && temperatures[i] > s.top().first) {
                    res[s.top().second] = i - s.top().second;
                    s.pop();
                }
                s.push({temperatures[i], i});
            } else {
                s.push({temperatures[i], i});
            }
        }
        return res;

        // Using brute force
        // int n = temperatures.size();
        // vector<int> res;
        // for (int i = 0; i < n; i++) {
        //     int current = temperatures[i];
        //     int flag = 0;
        //     for (int j = i + 1; j < n; j++) {
        //         if (temperatures[j] > temperatures[i]) {
        //             res.push_back(j - i);
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if (flag == 0) {
        //         res.push_back(0);
        //     }
        // }
        // return res;
    }
};
