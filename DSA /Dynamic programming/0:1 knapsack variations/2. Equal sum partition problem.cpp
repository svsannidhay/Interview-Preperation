// top - down (memoized solution)
class Solution {
public:
    int dp[201][10001];
    bool ssp(vector<int> &arr,int sum, int n) {
        if(n == 0) return false;
        if(dp[n][sum] != -1) return dp[n][sum];
        if(sum == 0) return true;
        bool ret = ssp(arr,sum,n-1);
        if(arr[n-1] <= sum) 
            ret =   ret || ssp(arr,sum - arr[n-1],n-1);
        return dp[n][sum] = ret;    
    }
    
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int i = 0;i < nums.size();i++) {
            sum += nums[i];
        }    
        if(sum % 2 != 0) return 0;
        sum /= 2;
        return ssp(nums,sum,nums.size());
    }
};

// bottom up dp

class Solution {
public:
    bool ssp_dp(vector<int> & arr,int sum,int n) {
        bool dp[n+1][sum+1];
        for(int i = 0; i<= n ;i++) {
            for(int j = 0;j <= sum; j++) {
                dp[i][j] = false;        
            }
        }
        for(int i = 0;i < sum + 1; i++) dp[0][i] = false;
        for(int i = 0;i < n + 1; i++) dp[i][0] = true;
        for(int i = 1; i<= n ;i++) {
            for(int j = 1;j <= sum; j++) {
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++) {
            sum += nums[i];
        }    
        if(sum % 2 != 0) return 0;
        sum /= 2;
        return ssp_dp(nums,sum,nums.size());
    }
};