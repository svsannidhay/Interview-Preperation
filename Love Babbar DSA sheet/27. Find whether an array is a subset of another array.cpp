// METHOD 1 Binary search
/*

  TC : O(nlogn)
  SC : O(1)
*/


// METHOD 2 Hashing 
/*

  TC : O(N)
  SC : O(N)

*/


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> m1;
    for(int i = 0; i < n; i++) {
        m1[a1[i]] = 1;
    }
    for(int i = 0 ;i < m; i++) {
        if(m1[a2[i]] == 0) {
            return "No";
        }
    }
    
    return "Yes";
}