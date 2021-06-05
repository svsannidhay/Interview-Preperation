/*

  whole complexity is based upon the choice of pivot and the partitioning 
  if pivot element is the median of the elements between l and r then the 
  array will be paritioned perfectly into n / 2 sized partitions. 

  Time Complexity : O(NlogN)  // Best case 
  Time Complexity : O(N^2)    // worst case 


  ex : 
  Worst case (if we choose the minumum or maximum element as a pivot)
  1 2 3 4 5
  1  2 3 4 5 
    2   3 4 5
      3   4 5 
        4   5 
          => time complexity is O(N^2)

  ex 
  Best case (if we always choose median of the elements)
   1 2 3 4 5

   1 2   4 5

  1  2   4   5
          => Time Complexity : O(NlogN)
*/

#include<iostream>
#include<vector>
#include<stdlib.h>

#define ll long long int 
#define cinll(x) ll x;cin>>x;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb(x) push_back(x)

using namespace std;

ll partition(vector<ll> &arr, ll l, ll r) {
  ll pos = l;
  for(ll i = l;i < r ;i++) {
    if(arr[i] < arr[r]) {
      swap(arr[i],arr[pos]);
      pos++;
    }
  }
  swap(arr[pos],arr[r]);
  return pos;
}

ll selectPivot(vector<ll> &arr,ll l,ll r) {
  ll pivot = l + (rand() % (r - l + 1));
  swap(arr[pivot],arr[r]);
  return partition(arr,l,r);
}

void quickSort(vector<ll> &arr,ll l,ll r) {
  if(l < r) {
    ll pivot = selectPivot(arr,l,r);
    quickSort(arr,l,pivot-1);
    quickSort(arr,pivot+1,r);
  }
}


int main() {
  cinll(n);
  vector<ll> arr;
  for(ll i = 0;i < n; i++) {
    cinll(x);
    arr.pb(x);
  }
  quickSort(arr,0,n-1);
  for(auto i:arr) cout<<i<<" ";
  return 0;
}