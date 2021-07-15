class Solution {
public:
    
    int memo[101][10001];
    
    int lcs(string a,string b,int n,int m) {
        if(n == 0 || m == 0) return 0;
        if(memo[n][m] != -1) return memo[n][m];
        if(a[n-1] == b[m-1]) memo[n][m] = 1 + lcs(a,b,n-1,m-1);
        else memo[n][m] = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
        return memo[n][m];
    } 
    
    bool isSubsequence(string s, string t) {
        memset(memo,-1,sizeof(memo));
        if(lcs(s,t,s.length(),t.length()) == s.length()) return true;
        else return false;
    }
};