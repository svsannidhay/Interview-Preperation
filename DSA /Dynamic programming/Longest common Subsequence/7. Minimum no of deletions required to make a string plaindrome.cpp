class Solution{
  public:
    int memo[1001][1001];
    int lcs_memo(string s1,string s2,int n,int m) {
        if(n == 0 || m == 0) return 0;
        if(memo[n][m] != -1) return memo[n][m];
        if(s1[n-1] == s2[m-1]) {
            memo[n][m] = 1 + lcs_memo(s1,s2,n-1,m-1);
        } else {
            memo[n][m] = max(lcs_memo(s1,s2,n-1,m) , lcs_memo(s1,s2,n,m-1));
        }
        return memo[n][m];
    }
    
    int minimumNumberOfDeletions(string S) { 
        memset(memo,-1,sizeof(memo));
        string s = S;
        reverse(S.begin(),S.end());
        int longest_palindromic_subsequence = lcs_memo(s,S,S.length(),S.length());
        
        return S.length() - longest_palindromic_subsequence;
    } 
};