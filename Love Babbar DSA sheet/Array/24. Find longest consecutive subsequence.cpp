class Solution {
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        vector<int> is_there(100005,0);
        for(int i = 0;i < N; i++) {
            is_there[arr[i]] = 1;   
        }
        int ans = 0;
        int count = 0;
        for(int i = 1; i <= 100004; i++) {
            if(is_there[i] == 1) {
                count++;
            } else {
                ans = max(ans,count);
                count = 0;
            }
        }
        return ans;
    }
};