class Solution {
  public:
  
  int solve_dp(string &s1,string &s2,int n,int m) {
      int dp[n+1][m+1];
      memset(dp,0,sizeof(dp));
      for(int i=0;i<=n;i++) dp[i][0] = 0;
      for(int i = 0; i<= m;i++) dp[0][i] = 0;
      
      int ans = 0;
      
      for(int i = 1;i <= n; i++) {
          for(int j = 1;j <= m; j++) {
              if(s1[i-1] == s2[j-1]) {
                  dp[i][j] = 1 + dp[i-1][j-1];
              } else {
                  dp[i][j] = 0;
              }
              ans = max(ans,dp[i][j]);
          }
      }
      return ans;
      
  }
  
  int longestCommonSubstr (string S1, string S2, int n, int m)    {
      
      return solve_dp(S1,S2,n,m);
  }
};