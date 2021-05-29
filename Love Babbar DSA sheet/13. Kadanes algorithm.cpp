class Solution {
  public:
  // arr: input array
  // n: size of array
  //Function to find the sum of contiguous subarray with maximum sum.
  int maxSubarraySum(int arr[], int n)
  {

    // Your code here
    vector<int> dp;
    dp.push_back(arr[0]);
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
      dp.push_back(max(arr[i], arr[i] + dp[i - 1]));
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};