/*

  BASIC TWO POINTERS 

  Time Complexity : O(N)
  Space Complexity : O(1)
*/

class Solution{
  public:

    int sb(int arr[], int n, int x) {
        int left = 0;
        int right = 0;
        int sum = arr[0];
        int ans = 1e7;
        while(right < n) {
            if(sum < x) {
                right++;
                sum += arr[right];
            } else {
                if(sum > x) ans = min(ans,right - left + 1);
                sum -= arr[left];
                left++;
            }

        }
        return ans;
    }
};