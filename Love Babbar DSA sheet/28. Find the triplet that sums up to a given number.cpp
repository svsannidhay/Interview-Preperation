// BRUTE 
/*

  Create a hashmap store the sum of all possible pairs 
  Now iterate over the array selecting one element at a time 
  
  Time complexity : O(N^2)
  Space Complexity : O(N^2)

*/


//METHOD 1 (Sorting then two pointers)

/*

  Sort the original array then 
  iterate over the array selecting one element each time 
  now place two pointers left on i+1 and right at the end 
  then adjust them greedly for the sum to be equal the desired number

  Time complexity : O(N^2 + NlogN)
  Space Complexity : O(1)
*/

bool find3Numbers(int A[], int n, int X)    {
    sort(A,A+n);
    bool found = false;
    for(int i = 0 ;i < n; i++) {
        int val = A[i];
        int left = i+1;
        int right = n-1;
        while(left < right) {
            if(A[i] + A[left] + A[right] == X) {
                found = true;
                break;
            }
            if(A[left] + A[right] > X - A[i]) {
                right--;
            } else {
                left++;
            }
        }
    }
    return found;
}