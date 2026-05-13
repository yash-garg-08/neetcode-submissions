class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        while (true) {
            long long totalTIme = 0;
            for (int pile : piles) {
                totalTIme += ceil((double)pile  / speed);
            }
            if (totalTIme <= h) {
                return speed;
            }
            speed++;
        }
    }
};
