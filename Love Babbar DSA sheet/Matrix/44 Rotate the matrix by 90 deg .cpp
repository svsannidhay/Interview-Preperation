/*

  Intution        
  1  2  3  4
  5  6  7  8
  9  10 11 12
  13 14 15 16 

  we need 

  13 9 5 1
  14 10 6 2 
  15 11 7 3
  16 12 8 4 

  First lets find the transpose of given matrix 

  1 5 9  13 
  2 6 10 14
  3 7 11 15 
  4 8 12 16 

  Reverse each row and we will get the require matrix. 

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
        for(int i = 0;i < matrix.size(); i++) {
            for(int j = start; j <matrix[i].size();j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
            start++;
        }
        for(int i =0 ; i< matrix.size();i++) {
            int start = 0;
            int end = matrix[i].size()-1;
            while(start <= end) {
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};