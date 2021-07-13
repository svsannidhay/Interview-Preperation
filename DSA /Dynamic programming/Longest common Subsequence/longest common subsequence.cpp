class Solution
{
    // top - down memoized
    int memo[1001][1001];
    int solve_lcs(int x,int y,string &s1,string &s2) {
        if(x == 0 || y == 0) return 0;
        if(memo[x][y] != -1) return memo[x][y];
        if(s1[x - 1] == s2[y-1]) {
            memo[x][y] = 1 + solve_lcs(x-1,y-1,s1,s2); 
        } else {
            memo[x][y] = max(solve_lcs(x-1,y,s1,s2),solve_lcs(x,y-1,s1,s2));
        }
        return memo[x][y];
    }
    // bottom - up dp 
    int solve_dp(int x,int y,string s1,string s2) {
        int dp[x+1][y+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<= x; i++) dp[i][0] = 0;
        for(int i = 0;i <= y; i++) dp[0][i] = 0;
        
        for(int i = 1;i <= x; i++) {
            for(int j = 1; j <= y; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[x][y];
    }
    
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2) {
        // memset(memo,-1,sizeof(memo));
        return solve_dp(x,y,s1,s2);
    }
};