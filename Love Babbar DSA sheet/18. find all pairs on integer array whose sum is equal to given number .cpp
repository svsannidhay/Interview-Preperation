class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> mapit;
        int ans = 0;
        for(int i = 0;i < n; i++) {
            mapit[arr[i]]++;
            if(arr[i] == k - arr[i]) ans += max(0,mapit[k - arr[i]] - 1);
            else ans += mapit[k-arr[i]];
            
        }
        return ans;
    }
};