// METHOD 1

/*

  SORT the array sweep with the windoe of size m and choose greedly

  TC : O(N)
  SC : O(1)

*/

class Solution {
public:
  long long findMinDiff(vector<long long> a, long long n, long long m)
  {
    sort(a.begin(), a.end());
    long long int ans = 1e18;
    int left = 0;
    int right = m - 1;
    while (right < n)
    {
      ans = min(ans, a[right] - a[left]);
      left++;
      right++;
    }
    return ans;
  }
};