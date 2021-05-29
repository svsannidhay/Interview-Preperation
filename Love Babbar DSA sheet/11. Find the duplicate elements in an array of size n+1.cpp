// METHOD 1
/*

  By understanding the pigeonhole principle 

  We can see that if we sort the array and if some adjacent elemtents are same then it
  must be the only element which is repeated 

  Complexity : O(nlogn)
  Memory : O(N)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = -1;
        for(int i = 0;i < nums.size()  - 1 ;i++) {
            if(nums[i] == nums[i+1]) {
                ans = nums[i];
            }
        }
        return ans;
    }
};

// METHOD 2 
/*

  We can make a hashmap and if an element have the frequency > 1 it means its the answer 

  Complexity : O(N)
  Memory : O(N)

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mapit;
        int ans = -1;
        for(int i = 0;i < nums.size() ;i++) {
            mapit[nums[i]]++;
            if(mapit[nums[i]] > 1) {
                ans = nums[i];
            }
        }
        return ans;
    }
};

// METHOD 3
/*
  Changing the array into the custom hashmap 

  we can store the frequecy of x at arr[x] as arr[x] + n 
  then the frequency of x will be arr[x] / n
  and the original value at index x will be arr[x] % n;

  Complexity : O(N)
  Space Complexity: O(1)

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i]--;
        }
        int ans = -1;
        for(int i = 0;i < nums.size(); i++) {
            nums[nums[i] % nums.size()] += nums.size();
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] / nums.size() > 1) ans = i + 1;
        }
        return ans;
    }
};


// METHOD 4
/*
  Floyd's ALgorithm (Tortoise and hare)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while(tortoise != hare);
        // Phase 2
        cout<<hare;
        tortoise = nums[0];
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};

