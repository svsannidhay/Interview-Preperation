class Solution
{
 
    // Top - down Memoised solution 
    
    int memo[1001][1001];
    int solve_memo(int wt[],int val[],int n,int w) {
        if(n == 0 || w == 0) return memo[n][w] = 0;
        if(memo[n][w] != -1) return memo[n][w];
        
        memo[n][w] = solve_memo(wt,val,n-1,w);
        if(wt[n-1] <= w) {
            memo[n][w] = max(memo[n][w],val[n-1] + solve_memo(wt,val,n-1,w - wt[n-1]));   
        }
        return memo[n][w];
    }
    
    // Bottom up dp
    
    int solve_dp(int wt[],int val[],int n,int w) {
        int dp[n+1][w+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= n; i++) {
            for(int j = 1; j <= w; j++) {
                dp[i][j] = dp[i-1][j];
                if(wt[i-1] <= j) {
                    dp[i][j] = max(dp[i][j],val[i-1] + dp[i-1][j-wt[i-1]]);
                }
            }
        }
        return dp[n][w];
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        // memset(memo,-1,sizeof(memo));
        return solve_dp(wt,val,n,W);
    }
};