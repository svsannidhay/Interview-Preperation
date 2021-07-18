class Solution{
public:
    
    // Top - down memoised solution 
    
    int memo[1001][1001];
    int solve_memo(int arr[],int i,int j) {
        if(i >= j) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int cost = INT_MAX;
        for(int k = i ; k <= j-1; k++) {
            int temp_ans = 0;
            temp_ans += solve_memo(arr,i,k);
            temp_ans += solve_memo(arr,k+1,j);
            temp_ans += arr[i-1] * arr[k] * arr[j];
            cost = min(cost,temp_ans);
        }
        return memo[i][j] = cost;
    }

    int matrixMultiplication(int N, int arr[])  {
        memset(memo,-1,sizeof(memo));
        return solve_memo(arr,1,N-1);
    }
};