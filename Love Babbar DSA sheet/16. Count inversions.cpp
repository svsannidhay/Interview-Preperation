class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[],long long temp[],long long left,long long mid,long long right) {
        long long int p1 = left;
        long long int p2 = mid+1;
        long long int p3 = left;
        long long int inversions = 0;
        while(p1 <= mid && p2 <= right) {
            if(arr[p1] <= arr[p2]) {
                temp[p3] = arr[p1];
                p1++;
            } else {
                temp[p3] = arr[p2];
                inversions += (mid - p1 + 1);
                p2++;
            }  
            p3++;
        }
        while(p1 <= mid) {
            temp[p3++] = arr[p1];
            p1++;
        }
        while(p2 <= right) {
            temp[p3++] = arr[p2];
            p2++;
        }
        for(long long i = left; i <=right ;i++) {
            arr[i] = temp[i];
        }
        // cout<<inversions <<"   "; 
        return inversions;
    }
    
    long long int  mergeSort(long long arr[],long long temp[],long long left,long long right) {
        if(left >= right) return 0;
        
        long long mid = (left + right) / 2;
        long long int inversions = 0;
        inversions += mergeSort(arr,temp,left,mid);
        inversions += mergeSort(arr,temp,mid + 1,right);
        
        return inversions + merge(arr,temp,left,mid,right);
    }
    
    long long int inversionCount(long long arr[], long long N) {
        long long temp[N+1]; 
        return mergeSort(arr,temp,0,N-1);
    }


};