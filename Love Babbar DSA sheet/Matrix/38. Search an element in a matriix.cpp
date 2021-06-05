/*

  Binary search 

  Time Complexity : O(logn + logm)
  Memory Complexity : O(1)

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int r_no = -1;
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr[mid][0] <= target && arr[mid][arr[mid].size()-1] >= target) {
                r_no = mid;
                break;
            } else if(target < arr[mid][0]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(r_no == -1) return false;
        left = 0;
        right = arr[r_no].size() - 1;
        int ans = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr[r_no][mid] == target ) {
                ans = mid;
                break;
            } else if(target < arr[r_no][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(ans == -1) return false;
        return true;
    }
};