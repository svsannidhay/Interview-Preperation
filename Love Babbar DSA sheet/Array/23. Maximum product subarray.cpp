// METHOD : (MODIFIED KADANES)

/*

  Instead of maintaining only maximum value till now 
  
  We will maintain minimum value too so that if it's negative we can get a positive if 
  current element is positive. 

*/

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
        long long int max_val = arr[0]; 
        long long int min_val = arr[0];
        long long int ans = max(max_val,min_val);
        for(int i = 1;i < n; i++) {

            long long max_v = max(arr[i] * max_val,max((long long)arr[i],arr[i] * min_val));
            min_val = min(arr[i] * min_val,min((long long)arr[i],arr[i] * max_val));
            max_val = max_v;
            
            ans = max(ans,max(min_val,max_val));
        }
        return ans;
	}
};
