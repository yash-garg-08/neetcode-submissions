class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int current = temperatures[i];
            int flag = 0;
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    res.push_back(j - i);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                res.push_back(0);
            }
        }
        return res;
    }
};
