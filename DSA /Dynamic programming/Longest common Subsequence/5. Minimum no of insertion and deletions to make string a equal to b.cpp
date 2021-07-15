class Solution {
  int memo[1001][1001];
    int solve_lcs_memo (string &str1,string &str2,int n,int m) {
        if(n == 0 || m == 0)  return memo[n][m] = 0;
        if(memo[n][m] != -1) return memo[n][m];
        if(str1[n-1] == str2[m-1]) memo[n][m] = 1 + solve_lcs_memo(str1,str2,n-1,m-1);
        else memo[n][m] = max(solve_lcs_memo(str1,str2,n-1,m),solve_lcs_memo(str1,str2,n,m-1));
        return memo[n][m];
    } 

    

	public:
	int minOperations(string str1, string str2) { 
	    memset(memo,-1,sizeof(memo));
	    int lcs = solve_lcs_memo(str1,str2,str1.length(),str2.length());
	    return str1.length() - lcs + str2.length() - lcs;
	} 
};