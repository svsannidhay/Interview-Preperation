class Solution {
// Top down memoized
int memo[1001][1001];
int solve_memo(int coins[],int n,int sum) {
    if(sum == 0) return 0;
    if(n == 0) return INT_MAX - 1;
    if(memo[n][sum] != -1) return memo[n][sum];
    if(n == 1) {
        if( (sum % coins[n-1]) == 0) {
            return sum / coins[n-1]; 
        } else {
            return INT_MAX - 1;
        }
    }
    memo[n][sum] = solve_memo(coins,n-1,sum);
    if(coins[n-1] <= sum) {
        memo[n][sum] = min(memo[n][sum],1 + solve_memo(coins,n,sum - coins[n-1]));
    }
    return memo[n][sum];
    
};


// Bottom up dp
int solve_dp(int coins[],int n,int sum) {
    int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= sum; i++) dp[0][i] =  INT_MAX - 1;
    for(int i = 0; i <= n;i++) dp[i][0] = 0;
    
    for(int i = 1;i <= sum; i++) {
        if(i % coins[0] == 0) {
            dp[1][i] = i / coins[0];
        } else {
            dp[1][i] = INT_MAX-1;
        }
    }
    
    for(int i = 2;i <= n; i++) {
        for(int j = 1;j <= sum ;j++) {
            if(coins[i-1] <= j) {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];   
            }
        }
    }
    return dp[n][sum];
        
}
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    memset(memo,-1,sizeof(memo));
	    if(solve_memo(coins,M,V) >= INT_MAX - 1) return -1;
	    else return solve_memo(coins,M,V);
	} 
	  
};