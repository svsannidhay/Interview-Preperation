// METHOD 1 hashmaps
/*
  Time Complexity : O(N)
  Space Complexity : O(N)
*/

// METHOD 2 Sorting 
/*
  Time Complexity : O(NlogN)
  Space Complexity : O(1)
*/


//METHOD 3 Moore's voting algorithm

/*

  Now we have to find the numbers with frequency more that n/k 
  
  ->Its trivial to see that we can have at most k-1 elements which can occur more than n/k times.
  https://leetcode.com/problems/majority-element/
  ->Lets Solve this problem when k == 2 

    ans = -1;
    count = 0;
    for(x in arr) 
      if(x == ans) {
        count++;
      } else if(count == 0) {
        ans = x;
        count++;
      } else {
        count--
      }

    This will solve the question 

    -> Lets Solve this problem when k == 3
    class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int num1 = -1;
            int num2 = -1;
            int count1 = 0;
            int count2 = 0;
            for(int i = 0;i< nums.size() ;i++) {
                if(nums[i] == num1) {
                    count1++;
                } else if(nums[i] == num2) {
                    count2++;
                } else if(count1 == 0) {
                    num1 = nums[i];
                    count1++;
                } else if(count2 == 0) {
                    num2 = nums[i];
                    count2++;
                } else {
                    count1--;
                    count2--;
                }
            } 
            
            vector<int> ans;
            count1 = 0;
            count2 = 0;
            for(int i:nums) {
                if(i == num1) count1++;
                if(i == num2) count2++;
            }
            if(count1 > nums.size()/3) ans.push_back(num1);
            if(count2 > nums.size()/3 && num1 != num2) ans.push_back(num2);
            return ans;
        }


      we can generalise all this process for the optimal solution  
};

*/

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        vector<int> value(k,-1);
        vector<int> count(k,0);
        for(int i = 0;i < n; i++) {
            bool found = false;
            for(int j = 0;j < k-1;j++) {
                if(value[j] == arr[i]) {
                    count[j]++;
                    found = true;
                    break;
                }
            }
            if(found) continue;
            for(int j = 0;j < k-1;j++) {
                if(count[j] == 0) {
                    value[j] = arr[i];
                    count[j]++;
                    found = true;
                    break;
                }
            }
            if(found) continue;
            for(int j = 0; j < k-1; j++) count[j]--;
        }
        int ans = 0;
        for(int j = 0;j < k-1; j++) {
            int count = 0;
            for(int i = 0;i < n; i++) {
                if(arr[i] == value[j]) count++;
            }
            if(count > n/k) {
                ans++;
            }
        }
        return ans;
    }
};
