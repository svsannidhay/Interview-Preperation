// METHOD 1 Recurisve Brute force 

//METHOD 2 
/*

Every string have a suffix like this 

        5  
      3   4 
    1       2 

  Increasing from back and than decreasing 

  Step 1 : - Find the last element where the last peak take its final step up 
            (select first element from back where a[i] < a[i+1]) say we found x
            x = 3 in this case 
  Step 2 : - Find the right most element which is greater than x and 
            Swap(x,arr[ind2])
            Here Swap(3,4);
      5 
    4   3 
  1       2

  Step 3 : - reverse the last slope i.e from ind1 + 1 to end
      
  1 4 2 3 5 
  is the next permutation.

  Edge case : - 
    If we don't find the first break point then we just reverse the whole array 



  Time Complexity : - O(N)
  Space complexity : - O(1)

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int break_point = -1;
        for(int i = nums.size()-2;i >=0 ;i--) {
            if(nums[i] < nums[i+1]) {
                break_point = i;
                break;
            }
        }
        if(break_point == -1) {
            reverse(nums.begin(),nums.end());
            return;
        } else {
            int index2 = -1;
            for(int i = nums.size()-1;i >=0 ;i--) {
                if(nums[i] > nums[break_point]) {
                    index2 = i;
                    break;
                }
            }
            swap(nums[break_point],nums[index2]);
            int left = break_point+1;
            int right = nums.size()-1;
            while(left < right) {
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
    }
};