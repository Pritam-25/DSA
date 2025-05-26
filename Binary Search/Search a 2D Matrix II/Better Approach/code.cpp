class Solution {
    public:
        bool binarySearch(vector<int> &row, int target) {
            int low = 0;
            int high = row.size() - 1;
    
            while (low <= high) {
                int mid = (low + high) / 2;
    
                if (row[mid] == target) return true;
                else if (row[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
    
            return false;
        }
    
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rowCount = matrix.size();
    
            for (int i = 0; i < rowCount; i++) {
                if (binarySearch(matrix[i], target)) 
                    return true;
            }
    
            return false;
        }
    };
    