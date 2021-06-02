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