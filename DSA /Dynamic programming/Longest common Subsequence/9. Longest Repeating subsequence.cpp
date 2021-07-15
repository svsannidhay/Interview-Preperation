class Solution{
	public:
    //Top down memoised
    int memo[1001][1001];
    int solve_memo(string &a,string &b,int n,int m) {
        if(n == 0 || m ==0) return memo[n][m] = 0;
        if(memo[n][m] != -1) return memo[n][m];
        if(a[n-1] == b[m-1] && n != m) {
            memo[n][m] = 1  +  solve_memo(a,b,n-1,m-1);
        } else {
            memo[n][m] = max(solve_memo(a,b,n,m-1),solve_memo(a,b,n-1,m));
        }
        return memo[n][m];
    }

    //Bottom up dp

    int solve_dp(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i = 1;i <= n ;i++) {
            for(int j =1 ;j <= n;j++) {
                if(s[i-1] == s[j-1] && i != j) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            } 
        }
        return dp[n][n];
        
    }

  int LongestRepeatingSubsequence(string str){
      memset(memo,-1,sizeof(memo));
          return solve_memo(str,str,str.length(),str.length());
          // return solve_dp(str);
  }

};