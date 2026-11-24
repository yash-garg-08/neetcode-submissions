class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0; i<rows; i++){
            if(target < matrix[i][cols-1]){
                vector<int> arr = matrix[i];
                int left = 0;
                int right = cols-1;
                while(left <= right){
                    int mid = left + (right-left)/2;
                    if(target < arr[mid]){
                        right = mid - 1;
                    }else if(target > arr[mid]){
                        left = mid + 1;
                    }else{
                        return true;
                    }
                }
            }else if(target == matrix[i][cols-1]){
                return true;
            }
        }
        return false;
    }
};
