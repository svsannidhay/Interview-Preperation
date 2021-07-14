class Solution
{
    public:
    
    // Top down memoized 
    int memo[1001][1001];
    
    int find_lcs_memo(string s1,string s2,int n,int m) {
        if(n == 0 || m == 0) return memo[n][m] = 0;
        if(memo[n][m] != -1) return memo[n][m];
        if(s1[n-1] == s2[m-1]) {
            memo[n][m] = 1 + find_lcs_memo(s1,s2,n-1,m-1);
        } else {
            memo[n][m] = max(find_lcs_memo(s1,s2,n-1,m),find_lcs_memo(s1,s2,n,m-1));
        }
        return memo[n][m];
    }
     
    // Bottom up dp 
    
    int find_lcs_dp(string s1,string s2,int n,int m) {
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i <= n;i++) dp[i][0] = 0 ;
        for(int i = 0; i <= m;i++) dp[0][i] = 0;
        
        for(int i = 1;i <= n;i++) {
            for(int j =1;j<=m;j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        
    } 
     
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        // memset(memo,-1,sizeof(memo));
        return n + m -  find_lcs_dp(X,Y,m,n);
    }
};