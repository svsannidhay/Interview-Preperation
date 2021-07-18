class Solution{
public:
    int memo[501][501];
    
    bool ispalindrome(string &s,int i,int j) {
        bool ans = true;
        while(i <= j) {
            if(s[i] != s[j]) ans = false;
            i++;
            j--;
        }
        return ans;
    }
    
    
    int solve_memo(string &s,int i,int j) {
        if(i >= j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(ispalindrome(s,i,j)) return memo[i][j] = 0;

        int ans = INT_MAX;
        
        for(int k = i; k < j;k++) {
            int temp_ans = solve_memo(s,i,k) + solve_memo(s,k+1,j) + 1;
            ans = min(ans,temp_ans);
        }
        
        return memo[i][j] = ans;
        
    } 

    int palindromicPartition(string str) {
        memset(memo,-1,sizeof(memo));
        return solve_memo(str,0,str.length() - 1);
    }
};