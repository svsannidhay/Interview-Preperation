// https : //practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
class Solution{
public:
  int memo[201][2001];
  bool ssb_memo(int arr[], int sum, int n)
  {
    if (n == 0)
      return false;
    if (sum == 0)
      return true;
    if (memo[n][sum] != -1)
      return memo[n][sum];
    bool verdict = ssb_memo(arr, sum, n - 1);
    if (arr[n - 1] <= sum)
    {
      verdict = verdict || ssb_memo(arr, sum - arr[n - 1], n - 1);
    }
    return memo[n][sum] = verdict;
  }
  
	int minDifference(int arr[], int n)  { 
    memset(memo,-1,sizeof(memo));
    
    int ans = 1e7;
    int start = 0;
    int sum = 0;
    for(int i =0 ;i< n;i++) {
        sum += arr[i];
    }
    for(int i = 0; i <= sum; i++) {
        if(ssb_memo(arr,i,n) == true) {
            ans = min(ans,abs(i-(sum-i)));
        }
    }
    return ans;
	}
};
