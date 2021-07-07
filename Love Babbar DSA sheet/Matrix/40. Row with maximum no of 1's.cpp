/*
    Method 1 : Binary search 
    Time Complexity : R * log(C)
    Space Complexity : O(1)
*/
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int count_ones = 0;
        int ans = -1;
        for(int i = 0;i < n; i++) {
            int s = 0;
            int e = m-1;
            int curr = m;
            while(s <= e) {
                int mid = (s + e) / 2;
                if(arr[i][mid] == 1) {
                    e = mid - 1;
                    curr = mid;
                } else {
                    s = mid + 1;
                }
            }
            curr = m - curr;
            // cout<<curr<<" ";
            // cout<<"\n";
            if(curr > count_ones) {
                count_ones = curr;
                ans = i;
            }
        }
        return ans;
	}

};

/*
  Following method works in O(m+n) time complexity in worst case. 
Step1: Get the index of first (or leftmost) 1 in the first row.
Step2: Do following for every row after the first row 
...IF the element on left of previous leftmost 1 is 0, ignore this row. 
...ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.
The time complexity is O(m+n) because we can possibly go as far left as we came ahead in the first step.

*/
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int ans = 0;
        int idx = -1;
        for(int i = 0; i < n; i++) {
            while(ans + 1 <= m && arr[i][m - (ans+1)] == 1) {
                ans++;
                idx = i;
            }
        }
        return idx;
	}

};