// METHOD 1
/*
  Sort and return a[k-1]

  Complexity : O(nlogn)
*/
class Solution{
  public:
    int kthSmallest(int a[], int l, int r, int k)
    {
      sort(a, a + r - l + 1);
      return a[k - 1];
    }
};

// METHOD 2
/*
  Maintain the max_heap of maximum size K 
  Print the top of heap

  Time complexity : O(nlogk)
*/

struct custom_compare{
    bool operator() (int a,int b) {
        return a<b;
    }
};

class Solution{
    public:
    int kthSmallest(int a[], int l, int r, int k) {
        priority_queue<int,vector<int>,custom_compare> pq;
        for(int i = 0;i <= r; i++) {
            pq.push(a[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
    
};

//Method 3

/*
  Randomised quickSort

  https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
*/
class Solution{
    public:

    int partition(int arr[],int l,int r) {
        int i = l;
        int x = arr[r];
        for(int j = l;j < r; j++) {
            if(arr[j] <= x) {
                swap(arr[j],arr[i]);
                i++;
            }
        }
        swap(arr[i],arr[r]);
        return i;
    }

    int createPivot(int arr[],int l,int r) {
        int n = r-l+1; 
        int pivot = rand() % n; 
        swap(arr[l + pivot],arr[r]);
        return partition(arr,l,r);
    }
    
    int solveRecursive(int arr[],int l,int r,int k) {
        if (k > 0 && k <= r - l + 1) 
        { 
            // Partition the array around a random element and 
            // get position of pivot element in sorted array 
            int pos = createPivot(arr, l, r); 
     
            // If position is same as k 
            if (pos-l == k-1) 
                return arr[pos]; 
            if (pos-l > k-1) // If position is more, recur for left subarray 
                return solveRecursive(arr, l, pos-1, k); 
     
            // Else recur for right subarray 
            return solveRecursive(arr, pos+1, r, k-pos+l-1); 
        } 
    }

    int kthSmallest(int a[], int l, int r, int k) {
        
        int ans = solveRecursive(a,l,r,k);
        return ans;
    }

    
};