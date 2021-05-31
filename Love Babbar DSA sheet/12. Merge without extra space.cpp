// METHOD 1
/*
  Brute force : MERGE Them 
  time compexity : O(n+m)
  memory: O(n+m)
*/

// METHOD  2  (SWAPS ON THE ELEMENTS WITH GAP X)
/*
    First example: 

a1[] = {3 27 38 43}, 

a2[] = {9 10 82}

Start with 

gap =  ceiling of n/2 = 4 

[This gap is for whole merged array]

3 27 38 43   9 10 82 

3 27 38 43   9 10 82

3 10 38 43   9 27 82


gap = 2:

3 10 38 43   9 27 82

3 10 38 43   9 27 82

3 10 38 43   9 27 82 

3 10 9 43   38 27 82

3 10 9 27   38 43 82


gap = 1:

3 10 9 27   38 43 82

3 10 9 27   38 43 82

3 9 10 27   38 43 82

3 9 10 27   38 43 82

3 9 10 27   38 43 82

3 9 10 27   38 43 82
Output : 3 9 10 27 38 43 82


*/

class Solution{
public:
	void merge(int a1[], int a2[], int n, int m) {
        int gap = ceil((long double) (n + m) / (long double) 2);
        while(gap >= 1) {
            int p1 = 0;
            int p2 = gap;
            while(p2 < n + m) {
                if(p1 < n && p2 < n) 
                    if(a1[p1] > a1[p2]) {
                        swap(a1[p1],a1[p2]);
                    }
                } else if(p1 < n && p2 >= n) {
                    if(a1[p1] > a2[p2-n]) {
                        swap(a1[p1],a2[p2-n]);
                    }
                } else if(p1 >= n && p2 >= n){
                    if(a2[p1-n] > a2[p2-n]) {
                        swap(a2[p1-n],a2[p2-n]);
                    }    
                }
                p1++;
                p2++;
            }
            if(gap == 1) gap = 0;
            gap = ceil(gap/(long double)2);
        }
	}
};

// METHOD 3
/*

  MULTIPLICATION AND MODULO TECHNIQUE

  We will merge them again but not into an external array but use a1 and a2 to store the 
  both the values real value and the sorted value 

  choose some x > max(all elements)

  a1[i]'s sorted value can be stored as a1[i] += x * (sorted value) 

  a1[i]'s original value is equal to a1[i] % x;
  sorted elements values stores at a1[i] is a1[i] / x;  
   
  time compexity : O(n+m)
  memory: O(1)

*/
class Solution{
  public:
    void merge(int a1[], int a2[], int n, int m) {
          
      long long int arr1[n];
      long long int arr2[m];
              
      for(int i = 0; i < n; i++) {
        arr1[i] = (long long int) a1[i];
      }
      for(int i = 0; i < m; i++) {
          arr2[i] = (long long int) a2[i];
      }
        
      long long int x = 1e8;
          
      long long int p1 = 0;
      long long int p2 = 0;
      long long int p3 = 0;
        
      while(p1 < n && p2 < m) {
          if( (arr1[p1] % x) <=  (arr2[p2] % x)) {
              if(p3 < n) {
                  arr1[p3] += (arr1[p1] % x) * x;
              } else {
                  arr2[p3-n] += (arr1[p1] % x) * x;
              }
              p1++;
          } else {
              if(p3 < n) {
                  arr1[p3] += (arr2[p2] % x) * x;
              } else {
                  arr2[p3-n] += (arr2[p2] % x) * x;
              }
              p2++;
          }
          p3++;
      }
      while(p1 < n) {
            if(p3 < n) {
                arr1[p3] += (arr1[p1] % x) * x;
            } else {
                arr2[p3-n] += (arr1[p1] % x) * x;
            }
            p1++;
            p3++;
      }
      
      while(p2 < m) {
          if(p3 < n) {
                arr1[p3] += (arr2[p2] % x) * x;
            } else {
                arr2[p3-n] += (arr2[p2] % x) * x;
            }
            p2++;
            p3++;
      }
      for(int i = 0; i < n; i++) {
          arr1[i] /= x;
          a1[i] = (int) arr1[i];
      }
      for(int i = 0; i < m; i++) {
          arr2[i] /= x;
          a2[i] = (int) arr2[i];
      }
    }
};