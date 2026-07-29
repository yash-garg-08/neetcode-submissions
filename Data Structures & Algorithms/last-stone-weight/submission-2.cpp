class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> max_heap;

        for (int i = 0; i < n; i++) {
            max_heap.push(stones[i]);
        }

        while (max_heap.size() > 1) {
            int top1 = max_heap.top();
            max_heap.pop();
            int top2 = max_heap.top();
            max_heap.pop();

            max_heap.push(top1 - top2);
        }

        return max_heap.top();
    }
};
