/*

  METHOD : Binary search over solution space (1 to 1e9)

  Time Complexity : O(log(1e9) * R * log(C))
  Space Complexity : O(1)
*/

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int start = 1;
        int end = 1e8;
        while(start <= end) {
            int mid  = (start + end) / 2;
            int count_lesser = 0;
            for(int i = 0;i < r; i++) {
                int curr_lesser = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
                count_lesser += curr_lesser;
            }
            if(count_lesser < (r*c + 1) / 2) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};