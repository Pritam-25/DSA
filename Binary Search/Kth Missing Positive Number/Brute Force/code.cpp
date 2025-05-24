class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int n = arr.size();
    
            for(int i = 0; i < n; i++) {
                if (arr[i] <= k) k++;  // If current number is not missing, shift k
                else break;            // If arr[i] > k, the k-th missing is before arr[i]
            }
    
            return k;
        }
    };
    