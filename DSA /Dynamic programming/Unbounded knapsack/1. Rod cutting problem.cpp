class Solution{
  public:
    // Top - Down (Recursive)
    int memo[1001][1001];
    int solve_memo(int price[],int n,int w) {
        if(n == 0 || w == 0) return 0;
        if(memo[n][w] != -1) return memo[n][w];
        memo[n][w] = solve_memo(price,n-1,w);
        if(n <= w) {
            memo[n][w] = max(memo[n][w],price[n-1] + solve_memo(price,n,w - n));
        }
        return memo[n][w];
    }
    // Bottom- up dp
    int solve_dp(int price[],int n) {
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i <= n; i++) dp[0][i] = 0;
        for(int i = 0;i <= n; i++) dp[i][0] = 0;
        
        for(int i = 1; i <= n; i++ ) {
            for(int j = 1; j <= n ;j++) {
                if(i <= j) {
                    dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j - i]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
    
    
    int cutRod(int price[], int n) {
        memset(memo,-1,sizeof(memo));
        return solve_dp(price,n);
    }
};