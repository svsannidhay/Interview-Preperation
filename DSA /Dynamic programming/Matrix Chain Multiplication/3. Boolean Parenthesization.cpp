// AC solution 
class Solution{
public:
    int memo[201][201][2];
    
    int solve_memo(string &s,int i,int j,int k) {
        if(i > j) return 0;
        if(memo[i][j][k] != -1) return memo[i][j][k];
        if(i == j) {
            if(k == 1) {
                if(s[i] == 'T') return memo[i][j][k] = 1;
                else return memo[i][j][k] =  0;
            } else {
                if(s[i] == 'F') return memo[i][j][k] =  1;
                else return memo[i][j][k] =  0;
            }
        }
        
        int ans = 0;
        for(int l = i + 1 ; l <= j - 1; l++) {
            if(s[l] == '&') {
                if(k == 1) {
                    ans += solve_memo(s,i,l-1,1) * solve_memo(s,l+1,j,1);
                } else {
                    ans += solve_memo(s,i,l-1,1) * solve_memo(s,l+1,j,0) + solve_memo(s,i,l-1,0) * solve_memo(s,l+1,j,1) + solve_memo(s,i,l-1,0) * solve_memo(s,l+1,j,0); 
                }
            }
            if(s[l] == '|') {
                if(k == 1) {
                    ans += solve_memo(s,i,l-1,1) * solve_memo(s,l+1,j,1) + solve_memo(s,i,l-1,1) * solve_memo(s,l+1,j,0) + solve_memo(s,i,l-1,0) * solve_memo(s,l+1,j,1);
                } else {
                    ans += solve_memo(s,i,l-1,0) * solve_memo(s,l+1,j,0);
                }
            }
            if(s[l] == '^') {
                if(k == 1) {
                    ans += solve_memo(s,i,l-1,1) * solve_memo(s,l+1,j,0) + solve_memo(s,i,l-1,0) * solve_memo(s,l+1,j,1);
                } else {
                    ans += solve_memo(s,i,l-1,1) * solve_memo(s,l+1,j,1) + solve_memo(s,l+1,j,0) * solve_memo(s,i,l-1,0);
                }
            }
            
        }
        return memo[i][j][k] = ans % 1003;
    }
    
    int countWays(int N, string S){
        memset(memo,-1,sizeof(memo));
        return solve_memo(S,0,N-1,1);
    }
};


// Clean code 

class Solution{
public:
    int memo[1001][1001][2];
    
    int solve_memo(string s,int i,int j,int k) {
        if(i > j) return 0;
        if(memo[i][j][k] != -1) return memo[i][j][k];
        if(i == j) {
            if(k == 1) {
                if(s[i] == 'T') return memo[i][j][k] = 1;
                else return memo[i][j][k] =  0;
            } else {
                if(s[i] == 'F') return memo[i][j][k] =  1;
                else return memo[i][j][k] =  0;
            }
        }
        
        int ans = 0;
        for(int l = i + 1 ; l <= j - 1; l++) {
            int left_T = solve_memo(s,i,l-1,1);
            int left_F = solve_memo(s,i,l-1,0);
            int right_T = solve_memo(s,l+1,j,1);
            int right_F = solve_memo(s,l+1,j,0);
            
            if(s[l] == '&') {
                if(k == 1) {
                    ans += left_T * right_T;
                } else {
                    ans += left_T * right_F + left_F * right_T + left_F * right_F; 
                }
            }
            if(s[l] == '|') {
                if(k == 1) {
                    ans += left_T * right_T + left_T * right_F + left_F * right_T;
                } else {
                    ans += left_F * right_F;
                }
            }
            if(s[l] == '^') {
                if(k == 1) {
                    ans += left_T * right_F + left_F * right_T;
                } else {
                    ans += left_T * right_T + right_F * left_F;
                }
            }
        }
        return memo[i][j][k] = ans;
    }
    
    int countWays(int N, string S){
        memset(memo,-1,sizeof(memo));
        return solve_memo(S,0,N-1,1);
    }
};