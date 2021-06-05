// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// METHOD 1
/*

  make the prefix dp array which stores the best answer from 0 to i 
  and make the suffix array which stores the best answer from i to n-1

  1) Create a table profit[0..n-1] and initialize all values in it 0.
2) Traverse price[] from right to left and update profit[i] such that profit[i] stores maximum profit achievable from one transaction in subarray price[i..n-1]
3) Traverse price[] from left to right and update profit[i] such that profit[i] stores maximum profit such that profit[i] contains maximum achievable profit from two transactions in subarray price[0..i].
4) Return profit[n-1]

  TC : O(N)
  SC : O(N)


  

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp_left(prices.size(),0);
        vector<int> dp_right(prices.size(),0);
        int min_val = prices[0];
        dp_left[0] = 0;
        for(int i = 1; i < prices.size(); i++) {
            dp_left[i] = max(dp_left[i-1],prices[i] - min_val);
            min_val = min(min_val,prices[i]);
        } 
        int max_val = prices[prices.size()-1];
        dp_right[prices.size()-1] = 0;
        for(int i = prices.size()-2; i >= 0; i--) {
            dp_right[i] = max(dp_right[i+1],max_val - prices[i]);
            max_val = max(max_val,prices[i]);
        } 
        int ans = 0;
        for(int i = 0 ;i < prices.size();i++) {
            ans = max(ans,dp_left[i] + dp_right[i]);
        }
        return ans;
    }
};