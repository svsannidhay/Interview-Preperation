class Solution{
  public:
    // TOp - down memoized
    long long int memo[1001][1001];
    long long int solve_memo(int S[],int n,int sum) {
        if(sum == 0) return 1;
        if(n == 0) return 0;
        if(memo[n][sum] != -1) return memo[n][sum];
        
        memo[n][sum] = solve_memo(S,n-1,sum);
        if(S[n-1] <= sum) {
            memo[n][sum] += solve_memo(S,n,sum - S[n-1]);
        }
        
        return memo[n][sum];
        
    }
  
    // botton up dp
    
    long long int solve_dp(int S[],int n,int sum) {
        long long int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i <= sum; i++) dp[0][i] = 0;
        for(int i = 0;i <= n; i++) dp[i][0] = 1;
        
        for(int i = 1;i <= n; i++) {
            for(int j = 1;j <= sum; j++) {
                if(S[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
        
    }
  
    long long int count( int S[], int m, int n ){
        // memset(memo,-1,sizeof(memo));
        return solve_dp(S,m,n);
        
    }
};