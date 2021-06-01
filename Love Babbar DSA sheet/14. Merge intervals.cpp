bool compare(vector<int> a,vector<int> b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    } 
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        vector<vector<int>> ans;
        int currx = intervals[0][0];
        int curry = intervals[0][1];
        for(int i = 1 ;i<intervals.size();i++) {
            if(curry >= intervals[i][0]) {
                currx = min(currx,intervals[i][0]);
                curry = max(curry,intervals[i][1]);
            } else {
                vector<int> a;
                a.push_back(currx);
                a.push_back(curry);
                currx = intervals[i][0];
                curry = intervals[i][1];
                ans.push_back(a);
            }
        }
        vector<int> a;
        a.push_back(currx);
        a.push_back(curry);
        ans.push_back(a);
        return ans;
    }
};