/*

  APRROACH 1 : 
  Binary search over the solution space 
  solution space is from mat[0][0] to mat[n][n]

  and then we will find the number of elements lesser than the mid for each row using bianry 
  search. 

  => Time complexity : O( log(mat[n][n] - mat[0][0]) * n * log(n) )
      Space complexity : O(1)

*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int start = mat[0][0];
  int end = mat[n-1][n-1];
  int ans = -1;
  while(start <= end) {
      int mid = (start + end) / 2;
      int count = 0;
      int last = -1;
      for(int i =0;i<n;i++) {
          int s = 0;
          int e = n-1;
          int pos = -1;
          while(s <= e) {
              int m = (s + e) / 2;
              if(mat[i][m] <= mid) {
                  s = m + 1;
                  pos = m;
              } else {
                  e = m - 1;
              }
          }
          last = max(last,mat[i][pos]);
          count += pos + 1;
      }
      if(count == k) {
          ans = last;
          break;
      }
      if(count > k) {
          end = mid - 1;
          ans = mid;
      } else {
          start = mid + 1; 
      }
  }
  return ans;
}