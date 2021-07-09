// Top - down (memoized solution)

class Solution {  
    int dp[1001][1001];
    
    int solvedp(int W,int wt[],int val[],int n) {
        if(n == -1 || W == 0) return 0;
        if(dp[n][W] != -1) return dp[n][W];
        dp[n][W] = solvedp(W,wt,val,n-1);
        if(wt[n] <= W) { 
            dp[n][W] = max(dp[n][W],val[n] + solvedp(W-wt[n],wt,val,n-1));
        }
        return dp[n][W];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp,-1,sizeof(dp));
        return solvedp(W,wt,val,n-1);
    }
};


// Bottom up dp


class Solution
{
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
        int dp[n+1][W+1];
        memset(dp,0,sizeof(dp));
        //Initialization'
        
        for(int i = 0; i <= W ; i++) dp[0][i] = 0;
        for(int i = 0; i<= n ;i++) dp[i][0] = 0;
    
        for(int i = 1;i <= n ; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i-1] <= j) {
                    dp[i][j] = max(dp[i-1][j - wt[i-1]] + val[i-1],dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
        
    }
};