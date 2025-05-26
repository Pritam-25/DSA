class Solution {
    public:
    
      int countStudent(vector<int> &arr, int pages){
          int student = 1; int currPageCount = 0;
          
          int n = arr.size();
          
          for(int i=0; i<n; i++){
              if(currPageCount + arr[i] <= pages) 
                  currPageCount += arr[i];
              else{
                  student ++;
                  currPageCount = arr[i];
              }
          }
          
          return student;
      }
    
      int findPages(vector<int> &arr, int k) {
          // code here
          int n = arr.size();
          
          if(k>n) return -1;
          
          int low = *max_element(arr.begin(), arr.end());
          int high = accumulate(arr.begin(), arr.end(), 0);
          
          while(low <= high){
              int mid = (low + high) /2;
              
              int student = countStudent(arr, mid);
              
              if (student <= k)
                  high = mid - 1;  // Try smaller max time
              else
                  low = mid + 1;   // Need more time
          }
          
          return low;
      }
  };