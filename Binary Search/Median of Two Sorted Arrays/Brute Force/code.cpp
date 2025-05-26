class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            int m = nums2.size();
    
            vector<int> result(m + n, 0);
    
            int low = 0;
            int high = 0;
            int i = 0;
    
            while (low < n && high < m) {
                if (nums1[low] < nums2[high]) {
                    result[i] = nums1[low];
                    low++;
                } else {
                    result[i] = nums2[high];
                    high++;
                }
    
                i++;
            }
    
            while (low < n) {
                result[i] = nums1[low];
                low++;
                i++;
            }
    
            while (high < m) {
                result[i] = nums2[high];
                high++;
                i++;
            }
    
            int total = m+n;
            int mid = total / 2;
    
            if (total % 2 == 0)
                return (result[mid - 1] + result[mid]) / 2.0;
    
            return result[mid];
        }
    };