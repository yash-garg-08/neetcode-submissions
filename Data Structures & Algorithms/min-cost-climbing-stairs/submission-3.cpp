#include <cstring>
class Solution {
   public:
    int t[10001];
    int rec(vector<int>& cost, int i) {
        if (i >= cost.size()) return 0;

        if (t[i] != -1) {
            return t[i];
        }

        int step1 = cost[i] + rec(cost, i + 1);
        int step2 = cost[i] + rec(cost, i + 2);

        return t[i] = min(step1, step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        return min(rec(cost, 0), rec(cost, 1));
    }
};