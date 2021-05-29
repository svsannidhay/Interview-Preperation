class Solution{
  public:
    int minJumps(int arr[], int n) {
        
        int next_jump = 0;
        int jumps = 0;
        int ans = 0;
        
        for(int i = 0;i < n - 1; i++) {
            
            next_jump = max(next_jump,i + arr[i]);
            
            if(jumps == 0) {
                ans++;
                jumps = next_jump - i;
                if(jumps == 0) return -1;
                // cout<<i<<","<<jumps<<" ";
            }
            
            jumps--;
            
        }
    
        
        return ans;
    }
};
