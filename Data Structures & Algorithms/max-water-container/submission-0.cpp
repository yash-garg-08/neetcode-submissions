class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxi = INT_MIN;

        while(i < j){
            int area = min(heights[i], heights[j]) * (j - i);
            maxi = max(maxi, area);

            if(heights[i] <= heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};
