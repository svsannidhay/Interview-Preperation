class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> sorted;
        for(int i = 0;i < N;i++) {
             for(int j = 0 ;j < N;j++) {
                 sorted.push_back(Mat[i][j]);
             }
        }
        sort(sorted.begin(),sorted.end());
        int it = 0;
        for(int i = 0;i < N;i++) {
             for(int j = 0 ;j < N;j++) {
                 Mat[i][j] = sorted[it];
                 it++;
             }
        }
        return Mat;
    }
};