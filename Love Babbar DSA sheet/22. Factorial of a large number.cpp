class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;
        for(int i = 2; i <= N; i++) {
            for(int j = 0; j < ans.size(); j++) {
                int curr = ans[j] * i + carry;
                carry = curr / 10;
                ans[j] = curr % 10;
            }
            
            while(carry > 0) {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
