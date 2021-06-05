#include<iostream>
#include<vector>

#define ll long long int 
#define cinll(x) ll x;  cin>>x;
#define pb(x) push_back(x)

using namespace std;

void solve() {
  cinll(n);
  vector<ll> arr;
  for(ll i = 0;i < n; i++) {
    cinll(x);
    arr.pb(x);
  }
  ll start = 0;
  for(ll i = 0 ;i < n;i++ ) {
    if(arr[i] < 0) {
      swap(arr[start],arr[i]);
      start++;
    }
  }
  for(ll i = 0;i < n; i++) cout<<arr[i]<<" ";
  cout<<"\n";
  return;
}

int main() {
  solve();
  return 0;
}