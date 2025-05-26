class Solution {
    public:
    
      int calcPainter(vector<int> &arr, int work){
          int painter = 1; 
          int currentwork = 0;
          
          for(int i=0; i<arr.size(); i++){
              if(currentwork+arr[i] <= work)
                  currentwork += arr[i];
              else{
                  painter ++;
                  currentwork = arr[i];
              }
          }
          
          return painter;
      }
      
      int minTime(vector<int>& arr, int k) {
          // code here
          int n = arr.size();
          
          int low = *max_element(arr.begin(), arr.end());
          int high = accumulate(arr.begin(), arr.end(), 0);
          
          while(low <= high){
              int mid = (low+high)/2;
              
              int painters = calcPainter(arr, mid);
              
              if (painters <= k)
                  high = mid - 1;  // Try smaller max time
              else
                  low = mid + 1;   // Need more time
          }
          
          // return minimum time
          return low;
      }
  };