#include<iostream>
#include<vector>

#define ll long long int 
#define cinll(x) ll x; cin>>x;
#define pb(x) push_back(x)
#define MAX 1e18 
#define MIN -1e18
#define mp(x,y) make_pair(x,y)

using namespace std;


// METHOD 1 Linear Iteration 
/*
  Declare two variables one for min and one for max.
  then iterate over the array and keep updating item.
  
  Number of comparisons =  2 * n
*/

void solve(vector<ll> &arr) {
  ll min_el = MAX;
  ll max_el = MIN;
  for(ll i = 0;i < arr.size() ;i++) {
    min_el = min(min_el,arr[i]);
    max_el = max(max_el,arr[i]);
  }
  cout<<min_el<<" "<<max_el<<"\n";
}

// Method 2 Divide and conquer
/*
  Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.

  T(n) = 2T(n/2) + 2
  T(n)  = 3n/2 - 2

*/
pair<ll,ll> solveDAC(vector<ll> &arr,ll l,ll r) {
  if(r - l + 1 == 1) {
    return mp(arr[l],arr[l]);
  } else if(r - l + 1 == 2){
    if(arr[l] < arr[r]) {
      return mp(arr[l],arr[r]);
    } else {
      return mp(arr[r],arr[l]);
    }
  } else {
    ll mid = (l + r)/2;
    pair<ll,ll> left = solveDAC(arr,l,mid);
    pair<ll,ll> right = solveDAC(arr,mid,r);
    return mp(min(left.first,right.first),max(left.second,right.second));
  }
}


// Method 3 Compare in pairs 
/*

  If N is odd assign min and max as first element 
  If N is even assign  min and max by comparing first two elements 
  Then choose the elements in pair and then compare 

*/

int main() {
  cinll(n);
  vector<ll> arr;
  for( ll i = 0;i < n; i++) {
    cinll(x);
    arr.pb(x);
  }

  solve(arr);
  pair<ll,ll> minmax = solveDAC(arr,0,n-1);
  cout<<minmax.first<<" "<<minmax.second<<"\n";
  return 0;
}