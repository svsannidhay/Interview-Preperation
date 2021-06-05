//METHOD 1 
/*

  We could use 3 start pointers each for each array and controlled sweep to the right.

*/

class Solution {
  public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
      int p1 = 0;
      int p2 = 0;
      int p3 = 0;
      vector<int> ans;
      while (p1 < n1)
      {
        while (p2 < n2 && B[p2] < A[p1])
          p2++;
        while (p3 < n3 && C[p3] < A[p1])
          p3++;
        if (A[p1] == B[p2] && B[p2] == C[p3])
        {
          ans.push_back(A[p1]);
          while (p1 + 1 < n1 && A[p1] == A[p1 + 1])
            p1++;
        }
        p1++;
      }
      return ans;
    }
};

// METHOD 2
/*

  HASHMAP 

*/
class Solution {
  public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> ans;
            unordered_map<int,int> mapit;
            for(int i = 0;i < n1; i++) {
                if(mapit[A[i]] == 0) mapit[A[i]]++;
            }
            for(int i = 0;i < n2; i++) {
                if(mapit[B[i]] == 1) mapit[B[i]]++;
            }
            for(int i = 0;i < n3; i++) {
                if(mapit[C[i]] == 2) {
                    mapit[C[i]]++;
                    if(mapit[C[i]] == 3) ans.push_back(C[i]);
                }
            }
            return ans;
        }
};