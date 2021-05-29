// METHOD 1
/*
  Make an array of all possible heights with the tower number, i.e. if height of any tower is h then we will insert h+k in the array and h-k(we will insert h-k in the array only if h-k ≥ 0). 
Sort the array.
Find the index upto which height of every tower is included from the starting. Initialise the answer to the difference between height at this index and starting index.
Then with the help of two pointer technique increment the left pointer which was initially at 0 such that one of the tower is not included.
Similarly increment right pointer to make all towers included and update the answer. Do this until end of the array.
*/

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

class Solution {
  public:
    int getMinDiff(int ar[], int n, int k) {
        vector< pair<int,int> > arr;
        int cnt = 0;
        unordered_map<int,int> mapit;
        for(int i = 0;i < n; i++) {
            if(ar[i] - k >= 0) {
                arr.push_back(make_pair(i,ar[i] - k));
            }
        }
        for(int i = 0;i < n; i++) {
            arr.push_back(make_pair(i,ar[i] + k));
        }
        sort(arr.begin(),arr.end(),compare);
        int ans = 10000000;
        int left = 0;
        int right = 0;
        while(right < arr.size()){
            if(mapit[arr[right].first] == 0) cnt++;
            mapit[arr[right].first]++;
            while(cnt == n) {
                mapit[arr[left].first]--;
                if(mapit[arr[left].first] == 0) {
                    cnt--;
                }
                left++;
            }
            if(left-1 != -1) {
                if(mapit[arr[left - 1].first] == 0) cnt++;
                left--;
                mapit[arr[left].first]++;
            }
            if(cnt == n) {
                ans = min(ans,arr[right].second - arr[left].second);
            }
            right++;

        }
        return ans;
    }
};