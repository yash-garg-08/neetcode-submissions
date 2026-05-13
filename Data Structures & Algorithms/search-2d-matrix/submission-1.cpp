class Solution {
   public:
    bool binSearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > arr[mid]) {
                left = mid + 1;
            } else if (target < arr[mid]) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][cols - 1]) {
                return binSearch(matrix[i], target);
            } else {
                continue;
            }
        }
        return false;
    }
};
