/*

  Approach : 
    Find and store the inorder traversal of the given bianry tree. 
    Now we know that this must be sorted for a binary tree to be BST
    So problem reduces to finding the minimum no of swaps required to sort an array.
*/

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums) {
        unordered_map<int,int> original_pos;
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        for(int i = 0;i < sorted.size(); i++) {
            original_pos[sorted[i]] = i;
        }
        
        int ans = 0;
        vector<bool> visited(nums.size()+1,false);
        for(int i=  0;i < nums.size();i++) {
            if(!visited[i]) {
                int start = i;
                visited[start] = true;
                int end = original_pos[nums[i]];
                int cycle_size = 1;
                while(end != start) {
                    visited[end] = true;
                    end = original_pos[nums[end]];
                    cycle_size++;
                }
                ans += cycle_size - 1;
            }
        }
        return ans;
	}
};