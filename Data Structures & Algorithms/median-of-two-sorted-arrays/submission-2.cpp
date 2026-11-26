class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // int m = nums1.size();
        // int n = nums2.size();
        // vector<double> arr;

        // int i = 0;
        // int j = 0;

        // while( i < nums1.size() && j < nums2.size()){
        //     if(nums1[i] <= nums2[j]){
        //         arr.push_back(nums1[i]);
        //         i++;
        //     }else{
        //         arr.push_back(nums2[j]);
        //         j++;
        //     }
        // }

        // while(i < nums1.size()){
        //     arr.push_back(nums1[i]);
        //     i++;
        // }

        // while(j < nums2.size()){
        //     arr.push_back(nums2[j]);
        //     j++;
        // }

        // return (m+n)%2 ? arr[(m+n)/2] : (arr[(m+n)/2]+arr[(m+n-1)/2])/2.0;

        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l = 0;
        int r = m;

        while (l <= r) {
            // mid
            // nums1 elements that will come before the partition
            int px = l + (r - l) / 2;
            // nums2 elements tht will come before the partition
            int py = (m + n + 1) / 2 - px;

            int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int x2 = (py == 0) ? INT_MIN : nums2[py - 1];
            int x3 = (px == m) ? INT_MAX : nums1[px];
            int x4 = (py == n) ? INT_MAX : nums2[py];

            if (x1 <= x4 && x2 <= x3) {
                if ((m + n) % 2 == 0) {
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                } else {
                    return max(x1, x2);
                }
            }
            if (x1 > x4) {
                r = px - 1;
            } else {
                l = px + 1;
            }
        }
        return -1.0;
    }
};
