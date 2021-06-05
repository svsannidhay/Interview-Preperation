// METHOD 1 (HASHING)
/*

  Maintaing the prefix sums if the current sum have appeared before 
  which means we could subtract that and we have a subarray with 0 sum. 

  Time Complexity : O(N)
  Space Complexity : O(N)

*/
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n) {
        unordered_map<long long int,int> pref_sum;
        long long int sum = 0;
        pref_sum[sum]++;
        for(int i = 0;i < n; i++) {
            sum += arr[i];
            pref_sum[sum]++;
            if(pref_sum[sum] >= 2) return true;
        }
        return false;
    }
};