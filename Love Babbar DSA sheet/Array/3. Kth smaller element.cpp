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
  Randomised quickSelect

  https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
*/
struct custom_compare{
    bool operator() (int a,int b) {
        return a<b;
    }
};

int partition(int a[],int l,int r) {
    int pivot = l;
    for(int i = l; i < r; i++) {
        if(a[i] < a[r]) {
            swap(a[i],a[pivot]);
            pivot++;
        }
    }
    swap(a[pivot],a[r]);
    return pivot;
}

int selectPivot(int a[],int l,int r) {
    int pivot = l + (rand() % (r - l + 1));
    swap(a[pivot],a[r]);
    return partition(a,l,r);
}

int quickSelect(int a[],int l,int r,int k) {
    if(l <= r) {
        int pivot = selectPivot(a,l,r);
        if(pivot == k) {
            // cout<<"here";
            return a[pivot];
        } 
        if(k <= pivot) {
            quickSelect(a,l,pivot-1,k);
        } else {
            quickSelect(a,pivot + 1,r,k);
        }
    }    
}

class Solution{
    public:
    int kthSmallest(int a[], int l, int r, int k) {
        return quickSelect(a,l,r,k-1);
    }
    
};