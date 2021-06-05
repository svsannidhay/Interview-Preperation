/*
    M1 Use direction vectors (i dont like it)
    M2 DFS (good but still i need to take care of orientiations)
    M3 Math

*/

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        int upper = 0;
        int left = 0;
        int lower = r - 1;
        int right = c - 1;
        int r_len = c;
        int r_buff = 0;
        int c_len = r;
        int c_buff = 2;
        vector<int> ans;
        while(r_buff < c || c_buff < r) { 
            if(upper <= lower) {
                for(int i = r_buff / 2; i < r_len - r_buff / 2; i++) {
                    cout<<matrix[upper][i]<<" ";
                }
                upper++;
            }
            if(left <= right) {
                for(int j = c_buff / 2 ; j < c_len - c_buff / 2;j++) {
                    cout<<matrix[j][right]<<" ";
                }
                right--;
            }
            if(upper <= lower) {
                for(int i = r_len - 1 - r_buff / 2; i >= r_buff / 2; i--) {
                    cout<<matrix[lower][i]<<" ";
                }
                lower--;
            }
            if(left <= right) {
                for(int j = c_len - 1 - c_buff / 2; j >= c_buff / 2; j--) {
                    cout<<matrix[j][left]<<" ";
                }
                left++;
            }
            c_buff += 2;
            r_buff += 2;
        }
        return ans;
    }
};