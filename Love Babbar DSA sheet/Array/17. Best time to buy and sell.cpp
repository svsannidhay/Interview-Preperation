class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int suff_max = 0;
        int ans = 0; 
        for(int i = prices.size() - 1;i >= 0; i--) {
            suff_max = max(suff_max,prices[i]);
            ans = max(ans,suff_max - prices[i]);
        }
        return ans;
    }
};