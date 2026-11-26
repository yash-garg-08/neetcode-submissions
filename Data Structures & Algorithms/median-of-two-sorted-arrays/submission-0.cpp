class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<double> arr;

        int i = 0;
        int j = 0;

        while( i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }else{
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()){
            arr.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            arr.push_back(nums2[j]);
            j++;
        }

        return (m+n)%2 ? arr[(m+n)/2] : (arr[(m+n)/2]+arr[(m+n-1)/2])/2.0;
    }
};
