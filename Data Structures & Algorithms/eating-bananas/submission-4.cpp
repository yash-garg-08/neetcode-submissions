class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (const auto& pile : piles) {
            maxi = max(maxi, pile);
        }

        int left = 1;
        int right = maxi;
        int result_speed = 0;

        while (left <= right) {
            int koko_speed = (right + left) / 2;

            long long totalTime = 0;
            for (const auto& pile : piles) {
                totalTime += (pile + koko_speed - 1) / koko_speed;
            }

            if (totalTime <= h) {
                result_speed = koko_speed;
                right = koko_speed - 1;
            } else {
                left = koko_speed + 1;
            }
        }

        return result_speed;
    }
};
