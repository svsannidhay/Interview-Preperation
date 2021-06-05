// METHOD 1
/*

  Count all the numbers less than equal to k. 
  now check for all the subarrays of size k how many elements in there are actually lesser
  than equal to k and answer for this window will be count - curr count 

  print the minimum answer 

  Time Complexity : O(N)
  Space Complexity : O(1)

*/

int minSwap(int *arr, int n, int k) {
    int count_el = 0;
    for(int i = 0;i < n; i++) {
        if(arr[i] <= k) count_el++;
    }
    // cout<<count_el<<" "; 
    int left = 0;
    int right = count_el-1;
    int curr_count = 0;
    for(int i = left;i <= right; i++) {
        if(arr[i] <= k) curr_count++;
    }
    // cout<<curr_count<<"\n";
    int ans = count_el - curr_count;
    while(right < n-1) {
        if(arr[right + 1] <= k) curr_count++;
        if(arr[left] <= k) curr_count--;
        left++;
        right++;
        ans = min(ans,count_el - curr_count);
    }
    return ans;
}
