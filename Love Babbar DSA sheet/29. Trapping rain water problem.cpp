// METHOD 1 
/*

  Making prefix array and suffix array to store the maximum elemen to the left of the array
  and maximum element to the right of the array.
  Then ans += height[i] - max(left,right)


  Time complexity: O(N)

  Space Complexity: O(N)

*/

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        vector<int> dp_left;
        vector<int> dp_right(n+1,0);
        dp_left.push_back(0);
        for(int i = 1;i < n; i++) {
            dp_left.push_back(max(dp_left[i-1],arr[i-1]));
        }
        for(int j = n-2; j >= 0; j--) {
            dp_right[j] = max(dp_right[j+1],arr[j+1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += max(0,min(dp_left[i],dp_right[i]) - arr[i]);
        }
        return ans;
    }
};


// METHOD 2 : OBSERVATION 

/*

    If we find the poistion of the largest element then it gurantees that 
    between 0 and pos_max there is no height greater than pos_max
    So the answer will only depend upon the left maximum

    and similarly between pos_max to size-1 the left maximum is always pos_max 
    So the answer will only depend upon the right maximum 

    So the question can be broken down into two seperate problems 


    Time Comlexity : O(N)
    Space Complexity : O(1)

*/


class Solution {
public:
    int trap(vector<int>& height) {
        int pos_max = -1;
        int val = -1;
        for(int i = 0;i < height.size(); i++) {
            if(height[i] > val) {
                pos_max = i;
                val = height[i];
            }
        }
        int ans = 0;
        int l_max = 0;
        for(int i = 0; i < pos_max; i++)  {
            ans += max(0,l_max - height[i]);
            l_max = max(l_max,height[i]);
        }
        int r_max = 0;
        for(int i = height.size()-1;i > pos_max; i--) {
            ans += max(0,r_max - height[i]);
            r_max = max(r_max,height[i]);
        }
        return ans;
    }
    
};